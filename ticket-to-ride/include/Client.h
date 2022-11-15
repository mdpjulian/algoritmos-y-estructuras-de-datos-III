#ifndef Client_H
#define Client_H


#include "./nlohmann/json.hpp"


    class Client{
        private:
            unsigned int _id;
            std::string _name;
            std::string _surname;
        public:
            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Client, _id, _name, _surname);
            Client();
            Client(int id, std::string name, std::string surname);
            ~Client();
            unsigned int getId();
            void setId(unsigned int id);
            std::string getName();
            void setName(std::string name);
            std::string getSurname();
            void setSurname(std::string surname);
            
    };

#endif