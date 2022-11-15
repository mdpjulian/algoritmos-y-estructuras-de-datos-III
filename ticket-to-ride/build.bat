::Compilo las librerías
g++ -Wall -std=c++11 -I.\include\ -c .\source\Client.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\source\ClientController.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\source\Manager.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\source\ManagerController.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\source\Ticket.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\source\TicketController.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\source\Menu.cpp

g++ -Wall -std=c++11 -I.\include\ -c main.cpp 

:: Compilo el Binario


g++ Client.o ClientController.o Manager.o ManagerController.o Ticket.o TicketController.o Menu.o main.o -o app.exe

::Borrar .o
DEL .\*.o

::Ejecuto el binario:
app.exe
