#ifndef CASERMA_HPP
#define CASERMA_HPP

#include "Personale.hpp"
#include "Mezzo.hpp"
#include "Missione.hpp"
#include <vector>
#include <memory>

class Caserma {
private:
    std::vector<Personale> personale;
    std::vector<Mezzo> mezzi;
    std::vector<Missione> missioni;

public:
    void aggiungiPersonale(const Personale& p);
    void aggiungiMezzo(const Mezzo& m);
    void creaMissione(const std::string& descrizione,
                      const std::vector<int>& idPersonale,
                      const std::vector<int>& idMezzi);

    void mostraPersonale() const;
    void mostraMezzi() const;
    void mostraMissioni() const;
};

#endif
