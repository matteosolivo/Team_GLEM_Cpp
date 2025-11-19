#ifndef PERSONALE_HPP
#define PERSONALE_HPP

#include "Risorsa.hpp"
#include <string>

enum class Grado{
    SOLDATO,
    CAPORALE,
    SERGENTE,
    TENENTE,
    CAPITANO,
    MAGGIORE
};

class Personale: public Risorsa {
private:
    std::string nome;
    Grado grado;

public:
    Personale(const std::string& nome, Grado grado);

    //int getId() const;
    std::string getNome() const;
    Grado getGrado() const;
    //bool isDisponibile() const;

   // void setDisponibile(bool disp);
    std::string descrizione()const override{
        gradoToString();
    }
    std::string gradoToString() const;
};

#endif