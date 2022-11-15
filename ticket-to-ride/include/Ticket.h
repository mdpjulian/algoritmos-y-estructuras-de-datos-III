#ifndef Ticket_H
#define Ticket_H

#include <Client.h>
#include <Manager.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>


class Ticket{
    private:
        unsigned int _id;
        std::string _message;
        std::shared_ptr<Client> _client;
        std::shared_ptr<Manager> _manager;
        std::vector<std::string> _messageCollection;
        std::string _status;

    public:
        Ticket();
        Ticket(unsigned int id, std::string msg, std::shared_ptr<Client> client, std::shared_ptr<Manager> manager);
        unsigned int getId();
        void addMessageToCollection(std::string msg);
        void displayMessageCollection();
        void setId(unsigned int id);
        std::string getMessage();
        void setMessage(std::string msg);
        std::shared_ptr<Client> getClient();
        void setClient(std::shared_ptr<Client> client);
        std::shared_ptr<Manager> getManager();
        void setManager(std::shared_ptr<Manager> manager);
        std::string getStatus();
        void setStatus(std::string status);

};

#endif