#ifndef CASERMA_HPP
#define CASERMA_HPP

#include "GestoreRisorse.hpp"
#include "Personale.hpp"
#include "Mezzo.hpp"
#include "Missione.hpp"
#include <vector>

class Caserma {
private:
    Caserma() = default;
    Caserma(const Caserma&) = delete;
    Caserma& operator=(const Caserma&) = delete;

    GestoreRisorse<Personale> personale;
    GestoreRisorse<Mezzo> mezzi;
    vector<Missione> missioni;

public:
    static Caserma& getInstance();

    void aggiungiPersonale(const Personale& p);
    void aggiungiMezzo(const Mezzo& m);

    void creaMissione(const string& descrizione,
                      const vector<int>& idPersonale,
                      const vector<int>& idMezzi);

    void mostraPersonale() const;
    void mostraMezzi() const;
    void mostraMissioni() const;
    void StampaSuFile() const;
};

#endif
