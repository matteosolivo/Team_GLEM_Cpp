#include "../include/Mezzo.hpp"

Mezzo::Mezzo(int id, const std::string& tipo)
    : id(id), tipo(tipo), disponibile(true) {}

int Mezzo::getId() const { return id; }
std::string Mezzo::getTipo() const { return tipo; }
bool Mezzo::isDisponibile() const { return disponibile; }
void Mezzo::setDisponibile(bool disp) { disponibile = disp; }
