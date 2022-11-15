#ifndef ManagerController_H
#define ManagerController_H
#include "./Manager.h"
#include "./JsonSerializer.h"
#include <memory>
#include <vector>



class ManagerController{
    private:
        std::vector<std::shared_ptr<Manager>> managerCollection;
        
    public:
        ManagerController();
        ~ManagerController();
        void createManager(unsigned int id, std::string name, std::string role);
        bool addManagerToCollection(std::shared_ptr<Manager> manager);
        int findManager(unsigned int id);
        bool updateManager(unsigned int id, std::string name, std::string role);
        bool deleteManager(unsigned int id);
        std::shared_ptr<Manager> getManagerObject(unsigned int id);
        void displayManagers();
        void writeFile();
        void readFile();
};

#endif