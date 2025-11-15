#ifndef CASERMA_HPP
#define CASERMA_HPP

#include "Personale.hpp"
#include "Mezzo.hpp"
#include "Missione.hpp"
#include <vector>
#include <memory>

using namespace std;

class Caserma {
private:
// COSTRUTTORE PRIVATO
    Caserma() {}
    Caserma(const Caserma&) = delete;
    Caserma& operator=(const Caserma&) = delete;

// VETTORI PER LA MEMORIZZAZIONE DEI DATI
    vector<Personale> personale;
    vector<Mezzo> mezzi;
    vector<Missione> missioni;

public:
// AGGIUNTA getInstance()
static Caserma& getInstance() {
    static Caserma instance;
    return instance;
}

// AGGIUNTA OGGETTI SINGOLI
    void aggiungiPersonale(const Personale& p);

    void aggiungiMezzo(const Mezzo& m);

    void creaMissione(const string& descrizione,
                      const vector<int>& idPersonale,
                      const vector<int>& idMezzi);

// VISUALIZZAZIONE
    void mostraPersonale() const;

    void mostraMezzi() const;

    void mostraMissioni() const;
};

#endif
