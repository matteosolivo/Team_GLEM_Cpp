#include "../include/Caserma.hpp"
#include <iostream>

void Caserma::aggiungiPersonale(const Personale& p) {
    personale.push_back(p);
}

void Caserma::aggiungiMezzo(const Mezzo& m) {
    mezzi.push_back(m);
}

void Caserma::creaMissione(const std::string& descrizione,
                           const std::vector<int>& idPersonale,
                           const std::vector<int>& idMezzi, TipoMissione t) {
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

    int numeroPiloti = 0;
    for(auto& p : Personale){
        if(p.isPilota() == true){
            numeroPiloti++;
        }
    }

    if(numeroPiloti < mezzi.length){
            //eccezione + richiesta di inserire del personale pilota/cambiare le persone assegnateS? altrimenti il codice va avanti e può fare la pushback
    }

    this->tipo = t;
    missioni.push_back(missione);
}

void Caserma::mostraPersonale() const {
    std::cout << "\n--- Personale ---\n";
    for (const auto& p : personale)
        std::cout << p.getId() << " - " << p.getNome() << " (" << p.gradoToString()
                  << ") [" << (p.isDisponibile() ? "Disponibile" : "In missione")
                  << (p.isPilota() ? "E' un pilota" : "Non è un pilota") << "]\n";
}

void Caserma::mostraMezzi() const {
    std::cout << "\n--- Mezzi ---\n";
    for (const auto& m : mezzi)
        std::cout << m.getId() << " - " << m.getTipo()
                  << " [" << (m.isDisponibile() ? "Disponibile" : "In missione") << "]\n";
}

void Caserma::mostraMissioni() const {
    std::cout << "\n=== Elenco Missioni ===\n";
    for (const auto& m : missioni)
        m.mostraDettagli();
}
