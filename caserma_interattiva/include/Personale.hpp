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
    bool pilota; //vero se è pilota, falso se non lo è.

public:
    Personale(int id, const std::string& nome, Grado grado);

    int getId() const;
    std::string getNome() const;
    Grado getGrado() const;
    bool isDisponibile() const;
    bool isPilota();

    void setDisponibile(bool d;isp);
    void setPilota(bool pilota)
    std::string gradoToString() const;
};

#endif
