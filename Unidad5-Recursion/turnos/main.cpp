#include <iostream>
#include <queue>
#include "client.h"

void TiempoTurnos(int tiempoAproximado, int NroTurno){
    if(tiempoAproximado > 35) return;
    std::cout << "Turno " << NroTurno << ": ";
    std::cout << "Falta para ser atendido " << tiempoAproximado << " minutos." << '\n';
    TiempoTurnos(tiempoAproximado + 5, ++NroTurno);

    
}
void showQueue(std::queue<Client*> gq)
{
    std::queue<Client*> g = gq;
    while (!g.empty()) {
        std::cout << '\t' << g.front()->getClientInfo();
        
        g.pop();
    }
    std::cout << '\n';
};


int main(){

    std::queue<Client*> q;

    Client* juan = new Client("juan", 35);
    Client* pedro = new Client("pedro", 22);
    Client* ana = new Client("ana", 56);

    q.push(juan);
    q.push(pedro);
    q.push(ana);

    showQueue(q);

    
    q.pop();
    showQueue(q);

    TiempoTurnos(5, 1);


    return 0;
}