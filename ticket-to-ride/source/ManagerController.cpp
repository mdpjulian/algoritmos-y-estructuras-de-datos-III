#include <ManagerController.h>
#include <iostream>
#include <fstream>

namespace nh = nlohmann;


ManagerController::ManagerController(){
    readFile();
};
ManagerController::~ManagerController(){};

void ManagerController::createManager(unsigned int id, std::string name, std::string role){
    std::shared_ptr<Manager> manager = std::make_shared<Manager>(id, name, role);
    addManagerToCollection(manager);
};
bool ManagerController::addManagerToCollection(std::shared_ptr<Manager> manager){
    this->managerCollection.push_back(manager);
    return 0;
};

int ManagerController::findManager(unsigned int id){
    for(unsigned int i = 0; i < managerCollection.size(); i++){
        if(id == managerCollection[i]->getId()) return i;
    };
    return -1;
};

bool ManagerController::updateManager(unsigned int id, std::string name, std::string role){
    int managerPosition = findManager(id);
    if(managerPosition != -1){
        managerCollection.at(managerPosition)->setName(name);
        managerCollection.at(managerPosition)->setRole(role);
        std::cout << "Representante actualizado correctamente!\n";
        writeFile();
        return 1;
    }else{
        std::cout << "Error al actualizar el representante\n";
        return 0;
    }
};

bool ManagerController::deleteManager(unsigned int id){
    int managerPosition = findManager(id);
    if(managerPosition != -1){
        managerCollection.erase(managerCollection.begin() + managerPosition);
        std::cout << "Representante borrado correctamente!\n";
        writeFile();
        return 1;
    }else{
        std::cout << "Error al borrar el representante\n";
        return 0;
    }
};

std::shared_ptr<Manager> ManagerController::getManagerObject(unsigned int id){
    int managerPosition = findManager(id);
    if(managerPosition != -1){
       return managerCollection.at(managerPosition);
    }else{
        return nullptr;
    }
};

void ManagerController::displayManagers(){
    std::cout << "Listando representantes: \n\n";
    for(unsigned int i = 0; i < managerCollection.size(); i++){
        std::cout << "ID: " << managerCollection[i]->getId() << " || Nombre: " << managerCollection[i]->getName() << " || Rol: " << managerCollection[i]->getRole() << std::endl;
    };
    std::cout << "---------------------------------------------\n";
}


void ManagerController::writeFile(){

    nh::json j = managerCollection;

    std::ofstream myfile;
    myfile.open ("managers.json");
    myfile << std::setw(4) << j;
    myfile.close();
    
}

void ManagerController::readFile(){

    std::ifstream file("managers.json");
    nh::json j = nh::json::parse(file);

    managerCollection = j;

}

