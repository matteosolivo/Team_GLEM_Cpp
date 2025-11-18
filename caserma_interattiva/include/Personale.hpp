#pragma once
#include "../Abstract_risorsa/abs.risorsa.hpp"
#include <string>

enum class Grado{
    SOLDATO,
    CAPORALE,
    SERGENTE,
    TENENTE,
    CAPITANO,
    MAGGIORE
};

class Personale:public Risorsa {
private:
    std::string nome;
    Grado grado;

public:
    Personale(int id, const std::string& nome, Grado grado,bool disponibile);

    int getId() const override;
    std::string getNome() const;
    Grado getGrado() const;
    bool isDisponibile() const override;

    void setDisponibile(bool disp)override;
    std::string gradoToString() const;
};

