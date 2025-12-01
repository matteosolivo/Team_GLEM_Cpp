#ifndef RISORSA_HPP
#define RISORSA_HPP

#include <iostream>
#include <string>

class Risorsa
{
protected:
    int id;
    bool disponibile;

public:
    // COSTRUTTORE
    Risorsa(int id) : id(id), disponibile(true) {}
    // DISTRUTTORE
    virtual ~Risorsa() = default;

    // GETTERS
    int getId() const { return id; }
    bool isDisponibile() const { return disponibile; }

    // SETTERS
    void setDisponibile(bool disp) { disponibile = disp; }

    // METODI DA FAR IMPLEMENTARE ALLE SINGOLE CLASSI Mezzo.cpp, Personale.cpp, ...
    virtual void getDescrizione() const = 0;
};

#endif