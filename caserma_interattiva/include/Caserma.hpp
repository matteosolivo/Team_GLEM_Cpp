#ifndef CASERMA_HPP
#define CASERMA_HPP

#include "GestoreRisorse.hpp"
#include "Personale.hpp"
#include "Mezzo.hpp"
#include "Missione.hpp"
#include <vector>

class Caserma {
private:
    Caserma() = default;
    Caserma(const Caserma&) = delete;
    Caserma& operator=(const Caserma&) = delete;

    GestoreRisorse<Personale> personale;
    GestoreRisorse<Mezzo> mezzi;
    vector<Missione> missioni;

public:
    static Caserma& getInstance();

    void aggiungiPersonale(const Personale& p);
    void aggiungiMezzo(const Mezzo& m);

    void Caserma::creaMissione(const string& descrizione, 
        const vector<Personale>& personaleMissione, 
        const vector<Mezzo>& mezziMissione,
        TipoMissione t)

    void mostraPersonale() const;
    void mostraMezzi() const;
    void mostraMissioni() const;
    void stampaSuFile() const;
    bool isMissioneValida(vector<int>& idPersonale,
                            vector<int>& idMezzi,
                            vector<Personale>& personaleDisponibile,
                            vector<Mezzo>& mezziDisponibili, 
                            TipoMissione tipo) const;
};

#endif
