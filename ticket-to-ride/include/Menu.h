#ifndef MENU_H
#define MENU_H
#include <ClientController.h>
#include <ManagerController.h>
#include <TicketController.h>

class Menu{
    private:
        TicketController* ticketController ;
        ClientController* clientController;
        ManagerController* managerController;
    public:
        Menu();
        ~Menu();
        void display();
        void subMenuAdmin(int option);
        void subMenuClient(int option);
        void subMenuManager(int option);

};


#endif