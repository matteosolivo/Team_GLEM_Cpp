#include "../include/Personale.hpp"

Personale::Personale(int id, const std::string& nome, Grado grado)
    : id(id), nome(nome), grado(grado), disponibile(true) {}

int Personale::getId() const { return id; }
std::string Personale::getNome() const { return nome; }
Grado Personale::getGrado() const { return grado; }
bool Personale::isDisponibile() const { return disponibile; }
void Personale::setDisponibile(bool disp) { disponibile = disp; }

std::string Personale::gradoToString() const {
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
