#include <iostream>
#include <queue>
#include "client.h"
void showQueue(std::queue<Client> gq)
{
    std::queue<Client> g = gq;
    while (!g.empty()) {
        std::cout << '\t' << g.front().getClientInfo();
        g.pop();
    }
    std::cout << '\n';
};
int main(){

    std::queue<Client> q;

    Client juan("juan", 35);
    Client pedro("pedro", 22);
    Client ana("ana", 56);

    q.push(juan);
    q.push(pedro);
    q.push(ana);

    showQueue(q);

    
    q.pop();
    showQueue(q);


    return 0;
}