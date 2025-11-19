#ifndef MISSIONE_HPP
#define MISSIONE_HPP

#include "Personale.hpp"
#include "Mezzo.hpp"
#include <string>
#include <vector>

using namespace std;

class Missione {
private:
    int id;
    string descrizione;
    vector<Personale*> personaleAssegnato;
    vector<Mezzo*> mezziAssegnati;

public:
    Missione(int id, const string& descrizione);

    void assegnaPersonale(Personale* p);
    void assegnaMezzo(Mezzo* m);

    void mostraDettagli() const;
};

#endif
