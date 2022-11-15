#include <Ticket.h>

Ticket::Ticket(){};

Ticket::Ticket(unsigned int id, std::string msg, std::shared_ptr<Client> client, std::shared_ptr<Manager> manager)
            : _id(id), _message(msg), _client(client), _manager(manager) 
{
    this->_messageCollection.push_back(msg);
    this->_status = "Abierto!";

};

void Ticket::addMessageToCollection(std::string msg){
    this->_messageCollection.push_back(msg);
}
void Ticket::displayMessageCollection(){
    std::cout << "\nMostrando historial de mensajes del ticket[" << _id << "]:" << std::endl;
    for(unsigned int i = 0; i < _messageCollection.size(); i++){
        std::cout << "[" << i << "]: " << _messageCollection[i] << std::endl;
    }
}

unsigned int Ticket::getId(){
    return this->_id;
}
void Ticket::setId(unsigned int id){
    this->_id = id;
}
std::string Ticket::getMessage(){
    return this->_message;
}
void Ticket::setMessage(std::string msg){
    this->_message = msg;
}
std::shared_ptr<Client> Ticket::getClient(){
    return this->_client;
};
void Ticket::setClient(std::shared_ptr<Client> client){
    this->_client = client;
};
std::shared_ptr<Manager> Ticket::getManager(){
    return this->_manager;
};
void Ticket::setManager(std::shared_ptr<Manager> manager){
    this->_manager = manager;
};
std::string Ticket::getStatus(){
    return this->_status;
};

void Ticket::setStatus(std::string status){
    this->_status = status;
};