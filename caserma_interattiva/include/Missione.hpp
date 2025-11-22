#ifndef MISSIONE_HPP
#define MISSIONE_HPP

#include "Personale.hpp"
#include "Mezzo.hpp"
#include <string>
#include <vector>

using namespace std;

enum class TipoMissione{
    SCORTA,
    ASSALTO,
    ESTRAZIONE
};

class Missione {
private:
    int id;
    string descrizione;
    vector<Personale*> personaleAssegnato;
    vector<Mezzo*> mezziAssegnati;
    TipoMissione tipo;


public:
    Missione(int id, const std::string& descrizione, TipoMissione t);

public:
    Missione(int id, const string& descrizione);

    void assegnaPersonale(Personale* p);
    void assegnaMezzo(Mezzo* m);

    void mostraDettagli() const;
    void stampaDettagliSuFile() const;
};

#endif
