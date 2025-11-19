#ifndef PERSONALE_HPP
#define PERSONALE_HPP

#include "Risorsa.hpp"

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
    string nome;
    Grado grado;

public:
    Personale(int id, const string& nome, Grado grado);

    string getNome() const;
    Grado getGrado() const;

    string gradoToString() const;
    void getDescrizione() const override;
};

#endif