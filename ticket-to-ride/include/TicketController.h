#ifndef TicketController_H
#define TicketController_H
#include <Ticket.h>
#include <memory>
#include <vector>


class TicketController{
    private:
        std::vector<std::shared_ptr<Ticket>> ticketCollection;

    public:
        TicketController();
        ~TicketController();
        void createTicket(unsigned int id, std::string msg, std::shared_ptr<Client> client, std::shared_ptr<Manager> manager);
        bool addTicketToCollection(std::shared_ptr<Ticket> ticket);
        int findTicket(unsigned int id);
        void updateTicket(unsigned int id, std::string msg);
        bool deleteTicket(unsigned int id);
        bool closeTicket(unsigned int id);
        bool reOpenTicket(unsigned int id);
        void showTicketHistory(unsigned int id);
        void displayAllTickets();
        void displayClientTicketsById(unsigned int id);
        void displayManagerTicketsById(unsigned int id);
};

#endif