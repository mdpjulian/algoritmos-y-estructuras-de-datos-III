#ifndef queueH
#define queueH

#include <iostream>
#include "client.h"
using namespace std;

class queue
{
private:
    int Rear, Front;
    Client Queue[50];
    int max;
    int Size;
    Client client;

public:
    queue()
    {
        Size = 0;
        max = 50;
        Rear = Front = -1;
    }
    bool Is_Empty();
    bool Is_Full();
    void Add(Client client);
    bool Delete();
    void getFront();
    void displayQueue();
    int getFrontPOS(){return Front;};
    int getRearPOS(){return Rear;};
};
bool queue ::Is_Empty()
{
    if (Front == -1)
        return 1;
    else
        return 0;
}
bool queue ::Is_Full()
{
    if (Front == 0 && Rear == max - 1)
        return 1;
    else
        return 0;
}
void queue ::Add(Client client)
{
    if (Is_Full()){
        cout << "Queue is full" << endl;
    }else{
        if(Front == -1) {Front = 0;};
        Queue[++Rear] = client;
        Size++;
    }
        
    
}
bool queue ::Delete()
{

    if (Is_Empty())
    {
        cout << "Queue Empty---";
        return false;
    }else{
        if(Front >= Rear) { Front = Rear = -1;Size = 0;return 1;}
       std::cout << "\n" <<  "Popup last element..." << "\n";
        Size--;
        Front++;
        return 1;
    }
}
void queue::getFront()
{
    if (!Is_Empty()){
        //return (Queue[Front + 1].getClientInfo());
    }else{
        cout << "No Front found!";
    }
}
void queue::displayQueue(){
    for(int i = Front; i <= Rear; i++){
        cout << Queue[i].getClientInfo();
    }
}

#endif