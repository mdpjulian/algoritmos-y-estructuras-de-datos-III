#include <iostream>
#include <list>
#include <algorithm>
#include "pacientes.h"



int main(){

    Paciente* pablo = new Paciente("Pablo", 30445724);
    Paciente* juan = new Paciente("Juan", 20347326);
    Paciente* carlos = new Paciente("Carlos", 35837482);

    std::list<Paciente*> lista {pablo, juan, carlos};

    
    Paciente* gabriela = new Paciente("Gabriela", 29374659);

    lista.push_back(gabriela);

    for (Paciente* x : lista) {
		std::cout << x->getName() << '\n';
	}


    lista.pop_back();
    for (Paciente* x : lista) {
		std::cout << x->getName() << '\n';
	}

    return 0;
}