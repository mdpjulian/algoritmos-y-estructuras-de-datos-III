#include <Manager.h>

Manager::Manager(){};
Manager::~Manager(){};

Manager::Manager(unsigned int id, std::string name, std::string role) 
            : _id(id), _name(name), _role(role){};

unsigned int Manager::getId(){
    return this->_id;
}
void Manager::setId(unsigned int id){
    this->_id = id;
}

std::string Manager::getName(){
    return this->_name;
}
void Manager::setName(std::string name){
    this->_name = name;
}

std::string Manager::getRole(){
    return this->_role;
}
void Manager::setRole(std::string role){
    this->_role = role;
}