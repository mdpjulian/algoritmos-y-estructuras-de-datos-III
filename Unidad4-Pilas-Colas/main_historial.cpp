#include <iostream>
#include <stack>
#include "client.h"

using namespace std;
int main() {
    stack<Client> stack;

    Client juan("juan", 35);
    juan.setPhone(155999999);
    Client pedro("pedro", 22);
    pedro.setPhone(155000000);
    Client ana("ana", 56);
    ana.setPhone(155777777);


    stack.push(juan);
    stack.push(pedro);
    stack.push(ana);
       

   cout << "Historial de numeros telefonicos : ..." << "\n";
    while (!stack.empty()) {
        cout << stack.top().getPhone() <<"\n";
        stack.pop();
    }
}