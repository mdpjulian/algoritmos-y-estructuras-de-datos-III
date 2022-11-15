#ifndef ClientController_H
#define ClientController_H

#include <Client.h>
#include "./JsonSerializer.h"

#include <memory>
#include <vector>



class ClientController{
    private:
        std::vector<std::shared_ptr<Client>> clientCollection;
        
    public:
        ClientController();
        ~ClientController();
        void createClient(unsigned int id, std::string name, std::string surname);
        bool addClientToCollection(std::shared_ptr<Client> client);
        int findClient(unsigned int id);
        bool updateClient(unsigned int id, std::string name, std::string surname);
        bool deleteClient(unsigned int id);
        std::shared_ptr<Client> getClientObject(unsigned int id);
        void displayClients();
        void writeFile();
        void readFile();
};



#endif