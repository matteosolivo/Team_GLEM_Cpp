#ifndef MEZZO_HPP
#define MEZZO_HPP

#include <string>

using namespace std;

class Mezzo {
private:
    int id;
    string tipo;
    bool disponibile;

public:
    Mezzo(int id, const string& tipo);

    int getId() const;
    string getTipo() const;
    bool isDisponibile() const;
    void setDisponibile(bool disp);
};

#endif
