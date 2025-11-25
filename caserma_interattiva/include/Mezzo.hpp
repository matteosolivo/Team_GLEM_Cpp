#ifndef MEZZO_HPP
#define MEZZO_HPP

#include "Risorsa.hpp"

class Mezzo : public Risorsa {
private:
    string tipo;

public:
    Mezzo(int id, const string& tipo);

    string getTipo() const { return tipo; }
    void getDescrizione() const override;
};

#endif