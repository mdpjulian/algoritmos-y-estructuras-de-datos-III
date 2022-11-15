#include <iostream>

#include <ClientController.h>

#include <ManagerController.h>

#include <TicketController.h>

#include <Menu.h>


int main(){

    Menu* ticketMenu = new Menu();
    ticketMenu->display();



    delete ticketMenu;
    return 0;

}