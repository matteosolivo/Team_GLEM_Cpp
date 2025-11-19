#ifndef RISORSA_HPP
#define RISORSA_HPP

#include <iostream>
#include <string>

class Risorsa {
protected:
    int id;
    bool disponibile;

public:
    // Il tuo codice precedente ignorava i parametri (metteva sempre 0 e true).
    Risorsa(int id, bool disponibile){
        this->id=0;
        this->disponibile=true;
    }
    
    int getId() const {
        return id;
    }

    bool isDisponibile() const {
        return disponibile;
    }

    void setDisponibile(bool disp) {
        this->disponibile = disp;
    }
    // Questo è l'unico metodo che cambia veramente tra un Mezzo e il Personale.
    virtual std::string descrizione() const = 0;

    // Distruttore virtuale (Best practise)
    virtual ~Risorsa() = default;
};

#endif