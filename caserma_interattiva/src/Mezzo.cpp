#include "../include/Mezzo.hpp"

using namespace std;

Mezzo::Mezzo(int id, const string& tipo)
    : Risorsa(id), tipo(tipo){}

void Mezzo::getDescrizione() const {
    cout << id << " - " << tipo << " [" << (disponibile ? "Disponibile" : "In missione") << "]\n";
}