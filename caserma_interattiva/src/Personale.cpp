#include "../include/Personale.hpp"

Personale::Personale(int id, const string& nome, Grado grado)
    : Risorsa (id), nome(nome), grado(grado){
    }

string Personale::getNome() const { return nome; }
Grado Personale::getGrado() const { return grado; }

string Personale::gradoToString() const {
    switch (grado) {
        case Grado::SOLDATO: return "Soldato";
        case Grado::CAPORALE: return "Caporale";
        case Grado::SERGENTE: return "Sergente";
        case Grado::TENENTE: return "Tenente";
        case Grado::CAPITANO: return "Capitano";
        case Grado::MAGGIORE: return "Maggiore";
        default: return "Sconosciuto";
    }
}

void Personale::getDescrizione() const {
    cout << id << " - " << nome << " (" << gradoToString() << ") [" << (disponibile ? "Disponibile" : "In missione") << "]\n";
}
