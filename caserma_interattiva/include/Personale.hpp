#ifndef PERSONALE_HPP
#define PERSONALE_HPP

#include "Risorsa.hpp"

using namespace std;

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
    bool pilota; // vero se è pilota, falso se non lo è.

public:
    Personale(int id, const string &nome, Grado grado, bool pilota = false);

    int getId() const;

    string getNome() const;

    bool isDisponibile() const;
    void setDisponibile(bool disp);

    Grado getGrado() const;
    string gradoToString() const;

    bool isPilota();
    void setPilota(bool pilota);
    
    void getDescrizione() const override;
};

#endif