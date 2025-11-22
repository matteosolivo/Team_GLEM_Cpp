#include "../include/Missione.hpp"
#include <iostream>

//Costruttore dell'oggetto Missione
Missione::Missione(int id, const std::string& descrizione)
    : id(id), descrizione(descrizione) {}

//Assegna un singolo membro di personale ad una missione e poi segna come non disponibile il membro stesso
void Missione::assegnaPersonale(Personale* p) {
    personaleAssegnato.push_back(p);
    p->setDisponibile(false);
}

//Assegna un mezzo ad una missione e segna come non disponibile il mezzo stesso
void Missione::assegnaMezzo(Mezzo* m) {
    mezziAssegnati.push_back(m);
    m->setDisponibile(false);
}

//Stampa i dettagli della missione
void Missione::mostraDettagli() const {
    std::cout << "=== Missione " << id << " ===\n";
    std::cout << "Descrizione: " << descrizione << "\n";

    std::cout << "Personale assegnato:\n";
    for (auto p : personaleAssegnato)
        std::cout << " - " << p->getNome() << " (" << p->gradoToString() << ")\n";

    std::cout << "Mezzi assegnati:\n";
    for (auto m : mezziAssegnati)
        std::cout << " - " << m->getTipo() << "\n";
}
