#include "../include/Personale.hpp"
using namespace std;

Personale::Personale(const string& nome, Grado grado)
    : Risorsa (id,disponibile)
    {
    this->nome=nome;
    this->grado=grado;
    }
    //: id(id), nome(nome), grado(grado), disponibile(true) {}

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
