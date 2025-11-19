#pragma once
#include <iostream>
#include <string>

// Classe astratta da implementare per metodi comuni a Mezzo e Personale
class Risorsa {
protected:
    int id;
    bool disponibile;

public:
    // Costruttore base
    Risorsa(int id, bool disponibile){
        this->id=id;
        this->disponibile=disponibile;
    }
    // Il "contratto" che le classi figlie devono implementare
    virtual int getId() const = 0;
    virtual bool isDisponibile() const = 0;
    virtual void setDisponibile(bool disp)=0;

    virtual ~Risorsa() {}
};

// Interfaccia
class Descrizione {
public:
    virtual std::string to_string() const = 0;
    virtual ~Descrizione() {}
};