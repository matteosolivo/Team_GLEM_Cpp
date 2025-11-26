#include "../include/Personale.hpp"
#include "Personale.hpp"

using namespace std;

Personale::Personale(int id, const string& nome, Grado grado, bool pilota)
    : Risorsa(id), nome(nome), grado(grado), pilota(pilota){};

// GETTERS
int Personale::getId() const { return id; }
string Personale::getNome() const { return nome; }
Grado Personale::getGrado() const { return grado; }
bool Personale::isPilota(){ return pilota; }

void Personale::setNome(string nome) { nome = nome; }
void Personale::setPilota(bool pilota){ this->pilota = pilota; }

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
    cout << id << " - "
    << nome << " ("
    << gradoToString() << ") ["
    << (disponibile ? "Disponibile" : "In missione") << "]\n";
}
