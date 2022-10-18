#include <iostream>
bool par(signed int n);

bool inpar(signed int n){
    if(n == 1){
        return true;
    }else{
        return par(n - 1);
    };
};
bool par(signed int n){
    if(n == 1){
        return false;
    }else{
        return inpar(n - 1);
    };
};

int main (){

    if(inpar(10)){
        std::cout << "El numero es inpar!";
    }else{
        std::cout << "El numero es par!";
    };

    return 0;
}