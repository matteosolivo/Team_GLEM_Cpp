#include "../include/Mezzo.hpp"
#include <string>
#include <iostream>
using namespace std;

Mezzo::Mezzo(const string& tipo)
    : Risorsa(id, disponibile)
{
    this->tipo = tipo;
}
string Mezzo::getTipo() const {
    return this->tipo;
}