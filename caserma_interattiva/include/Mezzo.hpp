#pragma once
#include <string>
#include "../Abstract_risorsa/abs.risorsa.hpp"

class Mezzo : public Risorsa {
private:
    std::string tipo;

public:
    // Il costruttore deve ricevere i dati per la classe base
    Mezzo(int id, bool disponibile, const std::string& tipo);

    // Implementazione del Contratto di Risorsa
    //Mezzo implementerà questi metodi
    // La parola chiave 'override' è un controllo di sicurezza
    int getId() const override;
    bool isDisponibile() const override;
    void setDisponibile(bool disp)override;

    //Metodo Specifico della classe Mezzo
    std::string getTipo() const;
};

