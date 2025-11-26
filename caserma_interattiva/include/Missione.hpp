#ifndef MISSIONE_HPP
#define MISSIONE_HPP

#include <fstream>

#include "GestoreRisorse.hpp"
#include "Personale.hpp"
#include "Mezzo.hpp"

enum class TipoMissione{
    SCORTA,
    ASSALTO,
    ESTRAZIONE
};

class Missione {
private:
    int id;
    std::string descrizione;
    GestoreRisorse<std::shared_ptr<Personale>> personaleAssegnato;
    GestoreRisorse<std::shared_ptr<Mezzo>> mezziAssegnati;
    TipoMissione tipo;


public:
    Missione(int id, const std::string& descrizione, TipoMissione tipo);

    void assegnaPersonale(std::shared_ptr<Personale>& p);
    void assegnaMezzo(std::shared_ptr<Mezzo>& m);

    TipoMissione chooseTipoMissione();
    void setTipoMissione(TipoMissione t);
    
    std::string tipoMissioneToString() const;

    void mostraDettagli() const;
    void stampaDettagliSuFile(std::ofstream& output) const;
};

#endif
