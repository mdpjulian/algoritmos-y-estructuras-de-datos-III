#ifndef Sort_H
#define Sort_H


struct Client{
    int dni;
    int getDni(){return dni;}
    int setDni(int d){this->dni = d;}
};

struct IOrdenamiento{
    virtual void ordenar(Client arr[]) = 0;
};

class Insertion : public IOrdenamiento{
    
    void ordenar(Client arr[], int n){
        int i, key, j;
        for (i = 1; i < n; i++){
            key = arr[i].getDni();
            j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j].getDni() > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1].setDni(key);
        }
    }

class QuickSort : public IOrdenamiento{

    void swap(int* a, int* b){   
        int t = *a;
        *a = *b;
        *b = t;
    }

    void ordenar(int arr[], int low, int high){
        if (low < high){
            //partition the array 
         int pivot = partition(arr, low, high);
         //sort the sub arrays independently
         ordenar(arr, low, pivot - 1);
         ordenar(arr, pivot + 1, high);
        }
    }
    int partition (int arr[], int low, int high){
        int i = (low - 1);
         for (int j = low; j <= high- 1; j++){
            //if current element is smaller than pivot, increment the low element
             //swap elements at i and j
            if (arr[j] <= pivot) {
                i++; // increment index of smaller element
                 swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
}

#endif
