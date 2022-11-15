#include <Menu.h>
#include <ClientController.h>
#include <ManagerController.h>
#include <TicketController.h>

#include <iostream>
#include <cstdlib>

void clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

Menu::Menu(){
    this->ticketController = new TicketController();
    this->clientController = new ClientController();
    this->managerController = new ManagerController();
}
Menu::~Menu(){
    delete this->ticketController;
    delete this->clientController;
    delete this->managerController;
}

void Menu::display(){
    int option;

    do{
        clear_screen();
        std::cout << "Bienvenido a Manejador de tickets!\n";
        std::cout << "1- Ingresar como administador.\n";
        std::cout << "2- Ingresar como Cliente.\n";
        std::cout << "3- Ingresar como Representante.\n";
        std::cout << "0- Salir del programa.\n";
        std::cin >> option;

        switch(option){
            case 1:
                subMenuAdmin(option);
                break;
            case 2:
                subMenuClient(option);
                break;
            case 3:
                subMenuManager(option);
                break;
            default:
                std::cout << "opcion invalida, elija nuevamente!\n";
        }
        

    }while(option != 0);
}


void Menu::subMenuAdmin(int option){
    std::string cName, cSurname, mName, mRole;
    unsigned int cId, mId;

    do{
        clear_screen();
        std::cout << "Bienvenido a Manejador de tickets!\n";
        std::cout << "1- Crear (cliente).\n";
        std::cout << "2- Crear (representante).\n";
        std::cout << "3- Actualizar (cliente).\n";
        std::cout << "4- Actualizar(representante).\n";
        std::cout << "5- Borrar (cliente).\n";
        std::cout << "6- Borrar (representante).\n";
        std::cout << "7- Listar clientes y representantes.\n";
        std::cout << "0- Volver al menu de inicio.\n";
        std::cin >> option;

        switch(option){

            case 1:
                clear_screen();
                std::cout << "Ingrese un id:\n";
                std::cin >> cId;
                std::cout << "Ingrese un nombre:\n";
                std::cin >> cName;
                std::cout << "Ingrese un apellido:\n";
                std::cin >> cSurname;
                clientController->createClient(cId, cName, cSurname);
                break;

            case 2:
                clear_screen();
                std::cout << "Ingrese un id:\n";
                std::cin >> mId;
                std::cout << "Ingrese un nombre:\n";
                std::cin >> mName;
                std::cout << "Ingrese un role:\n";
                std::cin >> mRole;
                managerController->createManager(mId, mName, mRole);
                break;

            case 3:
                clear_screen();
                std::cout << "Ingrese el id que desea actualizar:\n";
                std::cin >> cId;
                std::cout << "Ingrese el nombre:\n";
                std::cin >> cName;
                std::cout << "Ingrese el apellido:\n";
                std::cin >> cSurname;
                clientController->updateClient(cId, cName, cSurname);
                break;

            case 4:
                clear_screen();
                std::cout << "Ingrese el id que desea actualizar\n";
                std::cin >> mId;
                std::cout << "Ingrese el nombre:\n";
                std::cin >> mName;
                std::cout << "Ingrese el rol:\n";
                std::cin >> mRole;
                managerController->updateManager(mId, mName, mRole);
                break;

            case 5:
                clear_screen();
                std::cout << "Ingrese el id que desea borrar\n";
                std::cin >> cId;
                clientController->deleteClient(cId);
                break;

            case 6:
                clear_screen();
                std::cout << "Ingrese el id que desea borrar\n";
                std::cin >> mId;
                managerController->deleteManager(mId);
                break;
            case 7:
                clear_screen();
                clientController->displayClients();
                managerController->displayManagers();
                std::cin.ignore();
                std::cin.get();
                break;

            case 0:
                break;

            default:
                std::cout << "opcion invalida, elija nuevamente!\n";
                break;
        }
        
    }while(option != 0);


}

void Menu::subMenuClient(int option){

    std::string message;
    unsigned int cId, mId, tId;

    std::cout << "Ingrese su id de cliente: " << std::endl;
    std::cin >> cId;
    if(clientController->findClient(cId) == -1){
        std::cout << "Cliente inexistente, intente nuevamente!" << std::endl;
        return;
    }; 

    do{
        
        clear_screen();
        std::cout << "Elija una opcion de ticket!\n";
        std::cout << "1- Crear ticket.\n";
        std::cout << "2- Actualizar ticket\n";
        std::cout << "3- Cerrar ticket.\n";
        std::cout << "4- Re-abrir ticket.\n";
        std::cout << "5- Listar tickets.\n";
        std::cout << "6- Mostrar historial de mensajes de un ticket determinado.\n";
        std::cout << "0- Volver al menu de inicio.\n";
        std::cin >> option;

        switch(option){
            case 1:
                clear_screen();
                std::cout << "Elija el id de algun representante:\n";
                managerController->displayManagers();
                std::cin >> mId;
                std::cout << "Escriba su mensaje:\n";
                std::cin.ignore();
                std::getline(std::cin, message);
                ticketController->createTicket(rand(), message, clientController->getClientObject(cId), managerController->getManagerObject(mId));
                ticketController->displayClientTicketsById(cId);
                std::cin.get();
                break;

            case 2:
                clear_screen();
                ticketController->displayClientTicketsById(cId);
                std::cout << "Ingrese el id del ticket que desea actualizar:\n";
                std::cin.ignore();
                std::cin >> tId;
                std::cout << "Ingrese el nuevo mensaje:\n";
                std::cin.ignore();
                std::getline(std::cin, message);
                ticketController->updateTicket(tId, message);
                break;

            case 3:
                clear_screen();
                ticketController->displayClientTicketsById(cId);
                std::cout << "Ingrese el id del ticket que desea cerrar:\n";
                std::cin.ignore();
                std::cin >> tId;
                if(ticketController->closeTicket(tId)){
                    std::cout << "ticket cerrado exitosamente!" << std::endl;
                };
                std::cin.get();
                break;

            case 4:
                clear_screen();
                ticketController->displayClientTicketsById(cId);
                std::cout << "Ingrese el id del ticket que desea re-abrir:\n";
                std::cin.ignore();
                std::cin >> tId;
                if(ticketController->reOpenTicket(tId)){
                    std::cout << "ticket re-abierto exitosamente!" << std::endl;
                };
                std::cin.get();
                break;

            case 5:
                clear_screen();
                ticketController->displayClientTicketsById(cId);
                std::cin.ignore();
                std::cin.get();
                break;

            case 6:
                clear_screen();
                ticketController->displayClientTicketsById(cId);
                std::cin.ignore();
                std::cout << "Ingrese el id del ticket que desea ver el historial" << std::endl;
                std::cin >> tId;
                ticketController->showTicketHistory(tId);
                std::cin.ignore();
                std::cin.get();
                break;
            case 0:
                break;

            default:
                std::cout << "opcion invalida, elija nuevamente!\n";
                break;
        }
        

    }while(option != 0);

}

void Menu::subMenuManager(int option){

    std::string message;
    unsigned int mId, tId;

    std::cout << "Ingrese su id de representante: " << std::endl;
    std::cin >> mId;
    if(managerController->findManager(mId) == -1){
        std::cout << "Representante inexistente, intente nuevamente!" << std::endl;
        return;
    };


    do{

        clear_screen();
        std::cout << "Elija una opcion de ticket!\n";
        std::cout << "1- Actualizar ticket\n";
        std::cout << "2- Cerrar ticket.\n";
        std::cout << "3- Re-abrir ticket.\n";
        std::cout << "4- Listar tickets.\n";
        std::cout << "5- Mostrar historial de mensajes de un ticket determinado.\n";
        std::cout << "0- Volver al menu de inicio.\n";
        std::cin >> option;

        switch(option){
            
            case 1:
                clear_screen();
                ticketController->displayManagerTicketsById(mId);
                std::cout << "Ingrese el id del ticket que desea actualizar:\n";
                std::cin.ignore();
                std::cin >> tId;
                std::cout << "Ingrese el nuevo mensaje:\n";
                std::cin.ignore();
                std::getline(std::cin, message);
                ticketController->updateTicket(tId, message);
                break;

            case 2:
                clear_screen();
                ticketController->displayManagerTicketsById(mId);
                std::cout << "Ingrese el id del ticket que desea cerrar:\n";
                std::cin.ignore();
                std::cin >> tId;
                if(ticketController->closeTicket(tId)){
                    std::cout << "ticket cerrado exitosamente!" << std::endl;
                };
                std::cin.get();
                break;

            case 3:
                clear_screen();
                ticketController->displayManagerTicketsById(mId);
                std::cout << "Ingrese el id del ticket que desea re-abrir:\n";
                std::cin.ignore();
                std::cin >> tId;
                if(ticketController->reOpenTicket(tId)){
                    std::cout << "ticket re-abierto exitosamente!" << std::endl;
                };
                std::cin.get();
                break;

            case 4:
                clear_screen();
                ticketController->displayManagerTicketsById(mId);
                std::cin.ignore();
                std::cin.get();
                break;
            case 5:
                clear_screen();
                ticketController->displayManagerTicketsById(mId);
                std::cin.ignore();
                std::cout << "Ingrese el id del ticket que desea ver el historial" << std::endl;
                std::cin >> tId;
                ticketController->showTicketHistory(tId);
                std::cin.ignore();
                std::cin.get();
                break;

            case 0:
                break;

            default:
                std::cout << "opcion invalida, elija nuevamente!\n";
                break;
        }
    }while(option != 0);
}