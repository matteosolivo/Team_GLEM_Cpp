#include "../include/Mezzo.hpp"
#include <string>
#include <iostream>
using namespace std;

Mezzo::Mezzo(int id, bool disponibile, const string& tipo)
    : Risorsa(id, disponibile)
{
    this->tipo = tipo;
}
int Mezzo::getId() const {
    return this->id; 
}
bool Mezzo::isDisponibile() const {
    return this->disponibile;
}

string Mezzo::getTipo() const {
    return this->tipo;
}

void Mezzo::setDisponibile(bool disp) {
    this->disponibile = disp; 
}