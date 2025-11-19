#ifndef MEZZO_HPP
#define MEZZO_HPP

#include "Risorsa.hpp"
#include <string>

class Mezzo : public Risorsa {
private:
    std::string tipo;

public:
    // Il costruttore deve ricevere i dati per la classe base
    Mezzo(const std::string& tipo);

    //Metodo Specifico della classe Mezzo
    std::string descrizione()const override{
        getTipo();
    }
    std::string getTipo() const;
};

#endif