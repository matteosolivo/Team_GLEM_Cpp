#ifndef PERSONALE_HPP
#define PERSONALE_HPP

#include "Risorsa.hpp"

// DEFINIZIONE ENUMERAZIONE PER Grado
enum class Grado
{
    SOLDATO,
    CAPORALE,
    SERGENTE,
    TENENTE,
    CAPITANO,
    MAGGIORE
};

class Personale : public Risorsa
{
private:
    std::string nome;
    Grado grado;
    bool pilota; // true se è pilota, false se non lo è.

public:
    Personale(int id, const std::string &nome, Grado grado, bool pilota);

    // GETTERS
    int getId() const;
    std::string getNome() const;
    Grado getGrado() const;
    bool isPilota();

    // SETTERS
    void setNome(std::string nome);
    void setPilota(bool pilota);

    // METODI DA FAR IMPLEMENTARE ALLA SINGOLA CLASSE Personale.cpp
    std::string gradoToString() const;
    void getDescrizione() const override;
};

#endif