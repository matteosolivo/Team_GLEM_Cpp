#ifndef MISSIONE_HPP
#define MISSIONE_HPP

#include <string>
#include <vector>
#include <fstream>

#include "Personale.hpp"
#include "Mezzo.hpp"

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
    GestoreRisorse<shared_ptr<Personale>> personaleAssegnato;
    GestoreRisorse<shared_ptr<Mezzo>> mezziAssegnati;
    TipoMissione tipo;


public:
    Missione(int id, const string& descrizione, TipoMissione tipo);

    void assegnaPersonale(shared_ptr<Personale>& p);
    void assegnaMezzo(shared_ptr<Mezzo>& m);

    TipoMissione chooseTipoMissione();
    void setTipoMissione(TipoMissione t);
    
    string tipoMissioneToString() const;

    void mostraDettagli() const;
    void stampaDettagliSuFile(ofstream& output) const;
};

#endif
