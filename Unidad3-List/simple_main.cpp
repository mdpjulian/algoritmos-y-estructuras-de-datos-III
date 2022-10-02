#include <iostream>
#include "pacientes.h"
#include "simple_list.cpp"

int main(){

    Linkedlist* list = new Linkedlist();

    Paciente* pablo = new Paciente("pablo", 8888);
    Paciente* juan = new Paciente("juan", 3333);

    list->insertNode(pablo);
    list->insertNode(juan);

    //cout << "Los pacientes son: ";

	// Print the list
	list->printList();
	cout << endl;

    // Delete node at position 2.
	list->deleteNode(2);

    // Print the list
	list->printList();
	cout << endl;

    return 0;
}