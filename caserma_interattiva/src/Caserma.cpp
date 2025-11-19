#include "../include/Caserma.hpp"
#include <iostream>
#include <stdexcept>

Caserma& Caserma::getInstance() {
    static Caserma instance;
    return instance;
}

void Caserma::aggiungiPersonale(const Personale& p) {
    if (personale.esisteRisorsa(p.getId()))
        throw runtime_error("ID personale duplicato.");
    personale.aggiungiRisorsa(p);
}

void Caserma::aggiungiMezzo(const Mezzo& m) {
    if (mezzi.esisteRisorsa(m.getId()))
        throw runtime_error("ID mezzo duplicato.");
    mezzi.aggiungiRisorsa(m);
}

void Caserma::creaMissione(const string& descrizione, const vector<int>& idPersonale, const vector<int>& idMezzi) {
    Missione missione(missioni.size() + 1, descrizione);

    for (int id : idPersonale) {
        Personale* p = personale.getById(id);
        if (!p || !p->isDisponibile()){
            missione.assegnaPersonale(p);
        }
        p->setDisponibile(false);
    }

    for (int id : idMezzi) {
        Mezzo* m = mezzi.getById(id);
        if (!m || !m->isDisponibile()){
            missione.assegnaMezzo(m);
            m->setDisponibile(false);
        }
    }
    missioni.push_back(missione);
}

void Caserma::mostraPersonale() const { personale.stampaTutte(); }
void Caserma::mostraMezzi() const { mezzi.stampaTutte(); }
void Caserma::mostraMissioni() const {
    for (const auto& m : missioni){
        m.mostraDettagli();
    }
}
