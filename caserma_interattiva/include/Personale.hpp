#ifndef PERSONALE_HPP
#define PERSONALE_HPP

#include <string>

using namespace std;

enum class Grado {
    SOLDATO,
    CAPORALE,
    SERGENTE,
    TENENTE,
    CAPITANO,
    MAGGIORE
};

class Personale {
private:
    int id;
    string nome;
    Grado grado;
    bool disponibile;

public:
    Personale(int id, const string& nome, Grado grado);

    int getId() const;
    string getNome() const;
    Grado getGrado() const;
    bool isDisponibile() const;

    void setDisponibile(bool disp);
    string gradoToString() const;
};

#endif
