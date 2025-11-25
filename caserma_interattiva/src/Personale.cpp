#include "../include/Personale.hpp"

Personale::Personale(int id, const std::string& nome, Grado grado, bool pilota)
    : Risorsa(id), nome(nome), grado(grado), pilota(pilota){};

int Personale::getId() const { return id; }

string Personale::getNome() const { return nome; }

bool Personale::isDisponibile() const { return disponibile; }
void Personale::setDisponibile(bool disp) { disponibile = disp; }

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

bool Personale::isPilota(){ return pilota; }
void Personale::setPilota(bool pilota){ this->pilota = pilota; }

void Personale::getDescrizione() const {
    cout << id << " - "
    << nome << " ("
    << gradoToString() << ") ["
    << (disponibile ? "Disponibile" : "In missione") << "]\n";
}
