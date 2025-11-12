#ifndef MISSIONE_HPP
#define MISSIONE_HPP

#include "Personale.hpp"
#include "Mezzo.hpp"
#include <string>
#include <vector>

class Missione {
private:
    int id;
    std::string descrizione;
    std::vector<Personale*> personaleAssegnato;
    std::vector<Mezzo*> mezziAssegnati;

public:
    Missione(int id, const std::string& descrizione);

    void assegnaPersonale(Personale* p);
    void assegnaMezzo(Mezzo* m);

    void mostraDettagli() const;
};

#endif
