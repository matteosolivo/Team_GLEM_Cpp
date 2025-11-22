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
    bool disponibile;
    bool pilota; //vero se è pilota, falso se non lo è.

public:
    Personale(int id, const string& nome, Grado grado);

    string getNome() const;
    Grado getGrado() const;
    bool isDisponibile() const;
    bool isPilota();

    void setDisponibile(bool d;isp);
    void setPilota(bool pilota)
    std::string gradoToString() const;

    string gradoToString() const;
    void getDescrizione() const override;
};

#endif