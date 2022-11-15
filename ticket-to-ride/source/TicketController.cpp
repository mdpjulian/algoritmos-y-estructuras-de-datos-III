#include <TicketController.h>
#include <iostream>
#include <fstream>


TicketController::TicketController(){};
TicketController::~TicketController(){};

void TicketController::createTicket(unsigned int id, std::string msg, std::shared_ptr<Client> client, std::shared_ptr<Manager> manager){
    if(client && manager != nullptr){
    
    std::shared_ptr<Ticket> ticket = std::make_shared<Ticket>(id, msg, client, manager);
    addTicketToCollection(ticket);
    }else{
        std::cout << "fallo ticket[" << id << "]: Se ingreso un cliente y/o representante incorrecto\n\n";
    }
};
bool TicketController::addTicketToCollection(std::shared_ptr<Ticket> ticket){
    this->ticketCollection.push_back(ticket);
    return 0;
};

int TicketController::findTicket(unsigned int id){
    for(unsigned int i = 0; i < ticketCollection.size(); i++){
        if(id == ticketCollection[i]->getId()) return i;
    };
    return -1;
};

void TicketController::updateTicket(unsigned int id, std::string msg){
    int ticketPosition = findTicket(id);
    if(ticketPosition != -1){
        ticketCollection.at(ticketPosition)->setMessage(msg);
        ticketCollection.at(ticketPosition)->addMessageToCollection(msg);
        ticketCollection.at(ticketPosition)->setStatus("Pendiente");
    }
};

bool TicketController::deleteTicket(unsigned int id){
    int ticketPosition = findTicket(id);
    if(ticketPosition != -1){
    ticketCollection.erase(ticketCollection.begin() + ticketPosition);
    return 1;
    }else{
        return 0;
    }
};

bool TicketController::closeTicket(unsigned int id){
    int ticketPosition = findTicket(id);
    if(ticketPosition != -1){
    ticketCollection.at(ticketPosition)->setStatus("Cerrado!");
    return 1;
    }else{
        return 0;
    }
};

bool TicketController::reOpenTicket(unsigned int id){
    int ticketPosition = findTicket(id);
    if(ticketPosition != -1){
    ticketCollection.at(ticketPosition)->setStatus("Re-Abierto!");
    return 1;
    }else{
        return 0;
    }
};

void TicketController::showTicketHistory(unsigned int id){
    int ticketPosition = findTicket(id);
    if(ticketPosition != -1){
    ticketCollection.at(ticketPosition)->displayMessageCollection();
    }
};

void TicketController::displayAllTickets(){
    std::cout << "Listando tickets: \n\n";
     for(unsigned int i = 0; i < ticketCollection.size(); i++){
        std::cout << "ID: " << ticketCollection[i]->getId() << " || Ultimo Mensaje: " << ticketCollection[i]->getMessage() << " || Cliente: " << ticketCollection[i]->getClient()->getName() << " || Representante: " << ticketCollection[i]->getManager()->getName() << " || Estado: " << ticketCollection[i]->getStatus() << std::endl;
    };
    std::cout << "--------------------------------------------------------------------------------------------------\n";
}

void TicketController::displayClientTicketsById(unsigned int id){
    std::cout << "Listando ticket del cliente[" << id << "]:\n\n";
     for(unsigned int i = 0; i < ticketCollection.size(); i++){
        if(id == ticketCollection[i]->getClient()->getId()){
            std::cout << "ID: " << ticketCollection[i]->getId() << " || Ultimo Mensaje: " << ticketCollection[i]->getMessage() << " || Cliente: " << ticketCollection[i]->getClient()->getName() << " || Representante: " << ticketCollection[i]->getManager()->getName() << " || Estado: " << ticketCollection[i]->getStatus() << std::endl;
        }
    };
    std::cout << "--------------------------------------------------------------------------------------------------\n";
}

void TicketController::displayManagerTicketsById(unsigned int id){
    std::cout << "Listando ticket del representante[" << id << "]:\n\n";
     for(unsigned int i = 0; i < ticketCollection.size(); i++){
        if(id == ticketCollection[i]->getManager()->getId()){
            std::cout << "ID: " << ticketCollection[i]->getId() << " || Ultimo Mensaje: " << ticketCollection[i]->getMessage() << " || Cliente: " << ticketCollection[i]->getClient()->getName() << " || Representante: " << ticketCollection[i]->getManager()->getName() << " || Estado: " << ticketCollection[i]->getStatus() << std::endl;
        }
    };
    std::cout << "--------------------------------------------------------------------------------------------------\n";
}
