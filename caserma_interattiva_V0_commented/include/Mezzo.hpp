#ifndef MEZZO_HPP
#define MEZZO_HPP

#include <string>

class Mezzo {
private:
    int id;
    std::string tipo;
    bool disponibile;

public:
    Mezzo(int id, const std::string& tipo);

    // GETTERS
    int getId() const;
    std::string getTipo() const;
    bool isDisponibile() const;

    // SETTERS
    void setDisponibile(bool disp);
};

#endif
