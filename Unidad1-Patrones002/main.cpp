#include <iostream>


class Motor{
    public:
        virtual void encender()  = 0;
        virtual void acelerar()  = 0;
        virtual void apagar()  = 0;
};

class MotorComun : public Motor{
    public:
        MotorComun(){};
        virtual void encender(){ std::cout<< "El motor comun se encendio. ";};
        virtual void acelerar(){ std::cout<< "El motor comun se acelero. ";};
        virtual void apagar() { std::cout<< "El motor comun se apago. ";};

        

};
class MotorEconomico : public Motor{
    public:
        MotorEconomico(){};
        virtual void encender(){ std::cout<< "El motor Economico se encendio. ";};
        virtual void acelerar(){ std::cout<< "El motor Economico se acelero. ";};
        virtual void apagar() { std::cout<< "El motor Economico se apago. ";};

};


class MotorElectrico {
    public:
        MotorElectrico(){};
        virtual void encender(){ std::cout<< "El motor electrico se encendio. ";};
        virtual void acelerar(){ std::cout<< "El motor electrico se acelero. ";};
        virtual void apagar() { std::cout<< "El motor electrico se apago. ";};

};
class MotorElectricoAdapter : public Motor{
    private:
        MotorElectrico* mEletrico;
    public:
        MotorElectricoAdapter(MotorElectrico* mE) : mEletrico{mE}{};
        virtual void encender(){ mEletrico->encender();};
        virtual void acelerar(){ mEletrico->acelerar();};
        virtual void apagar() { mEletrico->apagar();};
};
class Aplication{
    private:
        
    public:
        Aplication(){};
        virtual void usarMotorComun(MotorComun* mC){mC->encender();mC->acelerar();mC->apagar();};
        virtual void usarMotorEconomico(MotorEconomico* mE){mE->encender();mE->acelerar();mE->apagar();};
        virtual void usarMotorElectrico(MotorElectricoAdapter* mEA){mEA->encender();mEA->acelerar();mEA->apagar();} ;
        
};

int main(){
    std::cout << "HOLA MUNDO" << std::endl;

    Aplication* app = new Aplication();

    MotorComun* motorcomun = new MotorComun();
    MotorEconomico* motoreconomico = new MotorEconomico();
    MotorElectrico* motorelectrico = new MotorElectrico();

    MotorElectricoAdapter* adapterelectrico = new MotorElectricoAdapter(motorelectrico);

    app->usarMotorComun(motorcomun);
    printf("\n");
    app->usarMotorEconomico(motoreconomico);
    printf("\n");
    app->usarMotorElectrico(adapterelectrico);
    printf("\n");

    return 0;
}
