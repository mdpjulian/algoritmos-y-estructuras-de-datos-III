#include <iostream>
#include <stdexcept>
#include <memory>
using namespace std;
////////////////////////////////////////
class Chair{
    public:
        virtual string getChair() const = 0;
        virtual ~Chair(){};
};

class ModernChair : public Chair{
    public:
        virtual string getChair() const {return "silla modern";}
        virtual ~ModernChair() {};
} ;

class VictorianChair : public Chair{
    public:
        virtual string getChair() const {return "silla virtorian";}
        virtual ~VictorianChair() {};
} ;

class ArcChair : public Chair{
    public:
        virtual string getChair() const {return "silla arcdeco";}
        virtual ~ArcChair() {};
} ;
////////////////////////////////////////
//TABLES
////////////////////////////////////////
class Table{
    public:
        virtual string getTable() const = 0;
        virtual ~Table(){};
};

class ModernTable : public Table{
    public:
        virtual string getTable() const {return "mesa modern";}
        virtual ~ModernTable() {};
} ;

class VictorianTable : public Table{
    public:
        virtual string getTable() const {return "mesa virtorian";}
        virtual ~VictorianTable() {};
} ;

class ArcTable : public Table{
    public:
        virtual string getTable() const {return "mesa arcdeco";}
        virtual ~ArcTable() {};
} ;
////////////////////////////////////////
//SOFAS
////////////////////////////////////////
class Sofa{
    public:
        virtual string getSofa() const = 0;
        virtual ~Sofa(){};
};

class ModernSofa : public Sofa{
    public:
        virtual string getSofa() const {return "sofa modern";}
        virtual ~ModernSofa() {};
} ;

class VictorianSofa : public Sofa{
    public:
        virtual string getSofa() const {return "sofa virtorian";}
        virtual ~VictorianSofa() {};
} ;

class ArcSofa : public Sofa{
    public:
        virtual string getSofa() const {return "sofa arcdeco";}
        virtual ~ArcSofa() {};
} ;
////////////////////////////////////////


class MuebleriaFactory {
public:
	virtual Chair* createChair() const = 0;
    virtual Table* createTable() const = 0;
    virtual Sofa* createSofa() const = 0;
    virtual ~MuebleriaFactory() {};
    
};

class ModernFactory : public MuebleriaFactory {
public:
    
	Chair* createChair() const override {return new ModernChair(); };
    Table* createTable() const override {return new ModernTable(); };
    Sofa* createSofa() const override {return new ModernSofa(); };
    virtual ~ModernFactory() {};
};

class VictorianFactory : public MuebleriaFactory {
public:
    
	Chair* createChair() const override {return new VictorianChair(); };
    Table* createTable() const override {return new VictorianTable(); };
    Sofa* createSofa() const override {return new VictorianSofa(); };
    virtual ~VictorianFactory() {};
};

class ArcFactory : public MuebleriaFactory {
public:
    
	Chair* createChair() const override {return new ArcChair(); };
    Table* createTable() const override {return new ArcTable(); };
    Sofa* createSofa() const override {return new ArcSofa(); };
    virtual ~ArcFactory() {};
};

void ClientCode(const MuebleriaFactory& creator) {
  // ...
  std::cout << "Creando:" << std::endl
            << creator.createChair()->getChair() << std::endl
            << creator.createTable()->getTable() << std::endl
            << creator.createSofa()->getSofa() << std::endl;
  // ...
}

int main(){

    MuebleriaFactory* muebleriaFactoryModern = new ModernFactory();
  ClientCode(*muebleriaFactoryModern);

    MuebleriaFactory* muebleriaFactoryVirtorian = new VictorianFactory();
  ClientCode(*muebleriaFactoryVirtorian);

  MuebleriaFactory* muebleriaFactoryArc = new ArcFactory();
  ClientCode(*muebleriaFactoryArc);

     


    return 0;
}