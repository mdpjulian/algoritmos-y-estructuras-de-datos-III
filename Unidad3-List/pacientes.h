#ifndef PACIENTES_H
#define PACIENTES_H
#include <iostream>


struct Paciente{ 
    std::string name;
    int dni;
    Paciente(){};
    Paciente(std::string n, int d){
        this->name = n;
        this->dni = d;
    }
    std::string getName(){
        return name;
    }

};





#endif