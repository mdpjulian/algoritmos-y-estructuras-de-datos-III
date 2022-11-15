#!/bin/bash

g++ -Wall -std=c++11 -I./include/ -c ./source/Client.cpp
g++ -Wall -std=c++11 -I./include/ -c ./source/ClientController.cpp
g++ -Wall -std=c++11 -I./include/ -c ./source/Manager.cpp
g++ -Wall -std=c++11 -I./include/ -c ./source/ManagerController.cpp
g++ -Wall -std=c++11 -I./include/ -c ./source/Ticket.cpp
g++ -Wall -std=c++11 -I./include/ -c ./source/TicketController.cpp
g++ -Wall -std=c++11 -I./include/ -c ./source/Menu.cpp


g++ -Wall -std=c++11 -I./include/ -c main.cpp



g++ -o app.bin  main.o Manager.o ManagerController.o Client.o ClientController.o Ticket.o TicketController.o Menu.o

rm ./*.o
