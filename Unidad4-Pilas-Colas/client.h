#ifndef clientH
#define clientH

#include <iostream>

class Client{
    private:
        std::string _name;
        int _id;
        int _phone;

    public:
        Client(){};
        Client(std::string name, int id) : _name(name), _id(id){};
        std::string getClientInfo(){
            std::string output;
            return output = "Client: " + _name + ", ID: "  + std::to_string(_id) + "\n";
        }
        void setPhone(int phone){this->_phone = phone;}
        int getPhone(){return this->_phone;}
};

#endif