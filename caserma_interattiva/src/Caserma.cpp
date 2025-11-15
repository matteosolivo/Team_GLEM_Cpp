#include "../include/Caserma.hpp"
#include <iostream>

void Caserma::aggiungiPersonale(const Personale& p) {
    bool duplicato = false;
    for(auto& persona : personale){
        if (persona.getId() == p.getId()){
            duplicato = true;
        }
    }
    // CONTROLLO DUPLICATI PER Personale
    if (!duplicato)
    {
        personale.push_back(p);
    } else {
        ///////////////////////////////////////////// eccezione
    }
}

void Caserma::aggiungiMezzo(const Mezzo& m) {
    bool duplicato = false;
    for(auto& mezzo : mezzi){
        if (mezzo.getId() == m.getId()){
            duplicato = true;
        }
    }
    // CONTROLLO DUPLICATI PER Mezzi
    if (!duplicato)
    {
        mezzi.push_back(m);
    } else {
        ///////////////////////////////////////////// eccezione
    }
}

void Caserma::creaMissione(const string& descrizione,
                           const vector<int>& idPersonale,
                           const vector<int>& idMezzi) {

    // UTILIZZO DEL BUILDER PER COMPORRE OGGETTO Missione??
    //MissionBuilder builder;

    int id = missioni.size() + 1;
    Missione missione(id, descrizione);

    for (int idP : idPersonale) {
        for (auto& p : personale)
            if (p.getId() == idP && p.isDisponibile())
                missione.assegnaPersonale(&p);
    }
    
    for (int idM : idMezzi) {
        for (auto& m : mezzi)
            if (m.getId() == idM && m.isDisponibile())
                missione.assegnaMezzo(&m);
    }

    missioni.push_back(missione);
}

void Caserma::mostraPersonale() const {
    cout << "\n--- Personale ---\n";
    for (const auto& p : personale){
        cout << p.getId() << " - "
             << p.getNome() << " ("
             << p.gradoToString() << ") ["
             << (p.isDisponibile() ? "Disponibile" : "In missione") << "]\n";
    }
}

void Caserma::mostraMezzi() const {
    cout << "\n--- Mezzi ---\n";
    for (const auto& m : mezzi){
        cout << m.getId() << " - "
             << m.getTipo() << " ["
             << (m.isDisponibile() ? "Disponibile" : "In missione") << "]\n";
    }
}

void Caserma::mostraMissioni() const {
    cout << "\n=== Elenco Missioni ===\n";
    for (const auto& m : missioni){
        m.mostraDettagli();
    }
}
