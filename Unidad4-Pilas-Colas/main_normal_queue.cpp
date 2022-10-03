#include <iostream>
#include "client.h"
#include "queue.h"


int main(){

    queue Q;
    Client juan("juan", 35);
    Client pedro("pedro", 22);
    Client ana("ana", 56);
  
    Q.Add(juan);
    Q.Add(pedro);
    Q.Add(ana);

    Q.displayQueue();

    Q.Delete();
    Q.displayQueue();


    return 0;
}