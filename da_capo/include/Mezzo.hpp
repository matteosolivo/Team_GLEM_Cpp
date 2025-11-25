#ifndef MEZZO_HPP
#define MEZZO_HPP

#include "Risorsa.hpp"

using namespace std;

class Mezzo : public Risorsa {
private:
    string tipo;

public:
    Mezzo(int id, const string& tipo);

    string getTipo() const;
    void getDescrizione() const override;
};

#endif