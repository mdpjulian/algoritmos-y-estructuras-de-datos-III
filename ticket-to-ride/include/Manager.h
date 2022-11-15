#ifndef Manager_H
#define Manager_H

#include "./nlohmann/json.hpp"



class Manager{
    private:
        unsigned int _id;
        std::string _name;
        std::string _role;
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Manager, _id, _name, _role);
        Manager();
        Manager(unsigned int id, std::string name, std::string role);
        virtual ~Manager();
        virtual unsigned int getId();
        virtual void setId(unsigned int i);
        virtual std::string getName();
        virtual void setName(std::string n);
        virtual std::string getRole();
        virtual void setRole(std::string r);
    };

#endif