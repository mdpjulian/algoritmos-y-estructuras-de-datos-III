#include <Client.h>


Client::Client(){};
Client::~Client(){};

Client::Client(int id, std::string name, std::string surname)  
        :_id(id), _name(name), _surname(surname){};


unsigned int Client::getId(){
    return this->_id;
}
void Client::setId(unsigned int id){
    this->_id = id;
}
std::string Client::getName(){
    return this->_name;
}
void Client::setName(std::string name){
    this->_name = name;
}
std::string Client::getSurname(){
    return this->_surname;
}
void Client::setSurname(std::string surname){
    this->_surname = surname;
}