#ifndef MEZZO_HPP
#define MEZZO_HPP

#include "Risorsa.hpp"

class Mezzo : public Risorsa {
private:
    std::string tipo;

public:
    Mezzo(int id, const std::string& tipo);
    
    std::string getTipo() const { return tipo; }
    void getDescrizione() const override;
};

#endif