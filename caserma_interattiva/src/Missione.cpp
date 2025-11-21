#include "Missione.hpp"
#include <iostream>

Missione::Missione(int id, const std::string& descrizione, TipoMissione t)
    : id(id), descrizione(descrizione), tipoMissione(t){}

void Missione::assegnaPersonale(Personale* p) {
    personaleAssegnato.push_back(p);
    p->setDisponibile(false);
}

void Missione::assegnaMezzo(Mezzo* m) {
    mezziAssegnati.push_back(m);
    m->setDisponibile(false);
}

void Missione::mostraDettagli() const {
    std::cout << "=== Missione " << id << " ===\n";
    std::cout << "Tipo di Missione: " << tipo << "\n";
    std::cout << "Descrizione: " << descrizione << "\n";

    std::cout << "Personale assegnato:\n";
    for (auto p : personaleAssegnato)
        std::cout << " - " << p->getNome() << " (" << p->gradoToString() << ")\n";

    std::cout << "Mezzi assegnati:\n";
    for (auto m : mezziAssegnati)
        std::cout << " - " << m->getTipo() << "\n";
}
