#include <iostream>

struct IHoteles{
    virtual ~IHoteles(){}
    virtual std::string obtenerPrecio() const = 0;
};

class HotelEconomico : public IHoteles{
    public:
        std::string obtenerPrecio() const override{
            return "1300";
        }

};

class HotelLujoso : public IHoteles{
    public:
        std::string obtenerPrecio()const override{
            return "2600";
        }
};

class Decorator : public IHoteles{
    private:
        IHoteles* hoteles_;
    public:
        Decorator(IHoteles* hotel): hoteles_(hotel){}
     std::string obtenerPrecio()const override{
        return this->hoteles_->obtenerPrecio();
    }
};

class DecoratorApartamentos : public Decorator{
    public:
        DecoratorApartamentos(IHoteles* hotel) : Decorator(hotel){};
         std::string obtenerPrecio()const override{
            return "[Decorador de apartamentos]: " + Decorator::obtenerPrecio();
    }  
};

void BuscarHotel(IHoteles* hotel){
    std::cout << "PRECIO = " << hotel->obtenerPrecio();
}


int main(){

    HotelEconomico* hoteleconomico = new HotelEconomico();
    HotelLujoso* hotellujoso = new HotelLujoso();


    
    DecoratorApartamentos decoratorapartamentos = new DecoratorApartamentos(hoteleconomico);
    Decorator* decorator = new Decorator(decoratorapartamentos);

    BuscarHotel(hotellujoso);
    std::cout << "\n";
    BuscarHotel(decorator);

    return 0;
}