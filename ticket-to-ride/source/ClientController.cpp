#include <ClientController.h>
#include <iostream>
#include <fstream>

namespace nh = nlohmann;


ClientController::ClientController(){
    //get Clients from Json
    readFile();
};
ClientController::~ClientController(){};

void ClientController::createClient(unsigned int id, std::string name, std::string surname){
    std::shared_ptr<Client> client = std::make_shared<Client>(id, name, surname);
    addClientToCollection(client);
};
bool ClientController::addClientToCollection(std::shared_ptr<Client> client){
    this->clientCollection.push_back(client);
    writeFile();
    return 0;
};

int ClientController::findClient(unsigned int id){
    for(unsigned int i = 0; i < clientCollection.size(); i++){
        if(id == clientCollection[i]->getId()) return i;
    };
    return -1;
};

bool ClientController::updateClient(unsigned int id, std::string name, std::string surname){
    int clientPosition = findClient(id);
    if(clientPosition != -1){
        clientCollection.at(clientPosition)->setName(name);
        clientCollection.at(clientPosition)->setSurname(surname);
        std::cout << "Cliente actualizado correctamente!\n";
        writeFile();
        return 1;
    }else{
        std::cout << "Error al actualizar el cliente\n";
        return 0;
    }
};

bool ClientController::deleteClient(unsigned int id){
    int clientPosition = findClient(id);
    if(clientPosition != -1){
        clientCollection.erase(clientCollection.begin() + clientPosition);
        std::cout << "Cliente borrado correctamente!\n";
        writeFile();
        return 1;
    }else{
        std::cout << "Error al borrar el cliente\n";
        return 0;
    }
    
};

std::shared_ptr<Client> ClientController::getClientObject(unsigned int id){
    int clientPosition = findClient(id);
    if(clientPosition != -1){
        return clientCollection.at(clientPosition);
    }else{
        return nullptr;
    }
};

void ClientController::displayClients(){
    std::cout << "Listando clientes: \n\n";
     for(unsigned int i = 0; i < clientCollection.size(); i++){
        std::cout << "ID: " << clientCollection[i]->getId() << " || Nombre: " << clientCollection[i]->getName() << " || Apellido: " << clientCollection[i]->getSurname() << std::endl;
    };
    std::cout << "---------------------------------------------\n";
}

void ClientController::writeFile(){

    nh::json j = clientCollection;

    std::ofstream myfile;
    myfile.open ("clients.json");
    myfile << std::setw(4) << j;
    myfile.close();
}

void ClientController::readFile(){

    std::ifstream file("clients.json");
    nh::json j = nh::json::parse(file);
    
    clientCollection = j;
}
