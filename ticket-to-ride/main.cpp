#include <iostream>

#include <ClientController.h>

#include <ManagerController.h>

#include <TicketController.h>

#include <Menu.h>


int main(){

    //ClientController clientCl ;
    //ManagerController managerCl;
    //TicketController ticketCl;



    Menu* ticketMenu = new Menu();
    ticketMenu->display();

    delete ticketMenu;
/*
    clientCl->displayClients();
    managerCl.displayManagers();


    //ticket con id erroneo, falla.
    ticketCl.createTicket(2938473, "Consulta sobre una compra", clientCl.getClientObject(31), managerCl.getManagerObject(102));

    ticketCl.createTicket(1315524, "Problema en el envio", clientCl.getClientObject(123), managerCl.getManagerObject(164));


    ticketCl.updateTicket(2938473, "nueva modificacion msg", "PENDIENTE");
    ticketCl.displayTickets();

*/
    




    return 0;

}