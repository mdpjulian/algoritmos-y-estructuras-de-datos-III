#include <iostream>

struct Strategy{
    virtual void accion() const = 0;
    virtual ~Strategy(){};
};

class Peaton : public Strategy{
    public:
        virtual ~Peaton(){};
        void accion()const override{std::cout << "Algoritmo del peaton ejecutandose..\n";}
};
class Coche : public Strategy{
    public:
        virtual ~Coche(){};
        void accion()const override{std::cout << "Algoritmo del coche ejecutandose..\n";}
};
class TransportePublico : public Strategy{
    public:
        virtual ~TransportePublico(){};
        void accion()const override{std::cout << "Algoritmo del transporte publico ejecutandose..\n";}
};


class Navigator{
    private:
        Strategy* _strat;
    public:
        Navigator(Strategy* strat = nullptr) : _strat(strat){}
        ~Navigator(){delete this->_strat;}
        void setStrategy(Strategy* strat){
            delete this->_strat;
            this->_strat = strat;
        }
        void doAccion()const{
            this->_strat->accion();
        }
        Strategy* getStrategy(){
            return  _strat;
        }

};

int main(){
    
    Navigator* navigator = new Navigator();


    navigator->setStrategy(new Peaton);
    navigator->doAccion();

    navigator->setStrategy(new Coche);
    navigator->doAccion();

    navigator->setStrategy(new TransportePublico);
    navigator->doAccion();

    navigator->getStrategy();

    return 0;
}