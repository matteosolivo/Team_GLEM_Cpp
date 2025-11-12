#ifndef PERSONALE_HPP
#define PERSONALE_HPP

#include <string>

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
    std::string nome;
    Grado grado;
    bool disponibile;

public:
    Personale(int id, const std::string& nome, Grado grado);

    int getId() const;
    std::string getNome() const;
    Grado getGrado() const;
    bool isDisponibile() const;

    void setDisponibile(bool disp);
    std::string gradoToString() const;
};

#endif
