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
    std::string nome;
    Grado grado;
    bool pilota; // vero se è pilota, falso se non lo è.

public:
    Personale(int id, const std::string &nome, Grado grado, bool pilota);

    int getId() const;
    std::string getNome() const;
    Grado getGrado() const;
    bool isPilota();
    
    void setNome(std::string nome);
    void setPilota(bool pilota);

    std::string gradoToString() const;
    void getDescrizione() const override;
};

#endif