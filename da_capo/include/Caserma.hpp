#ifndef CASERMA_HPP
#define CASERMA_HPP

#include <vector>
#include <memory>

#include "GestoreRisorse.hpp"
#include "Personale.hpp"
#include "Mezzo.hpp"
#include "Missione.hpp"

using namespace std;

class Caserma {
private:
    // COSTRUTTORE PER SINGLETON
    Caserma() = default;
    Caserma(const Caserma&) = delete;
    Caserma& operator=(const Caserma&) = delete;

    GestoreRisorse<shared_ptr<Personale>> personale;
    GestoreRisorse<shared_ptr<Mezzo>> mezzi;
    vector<shared_ptr<Missione>> missioni;

public:
    // METODO STATICO DI CLASSE PER RILEVARE L'ISTANZA
    static Caserma& getInstance();

    void aggiungiPersonale(const shared_ptr<Personale>& p);
    void aggiungiMezzo(const shared_ptr<Mezzo>& m);

    void Caserma::creaMissione(const string& descrizione, 
                                const vector<shared_ptr<Personale>>& personaleMissione, 
                                const vector<shared_ptr<Mezzo>>& mezziMissione,
                                TipoMissione t);

    void mostraPersonale() const;
    void mostraMezzi() const;
    void mostraMissioni() const;
    void stampaSuFile();
    bool isMissioneValida(vector<int>& idPersonale,
                            vector<int>& idMezzi,
                            vector<shared_ptr<Personale>>& personaleDisponibile,
                            vector<shared_ptr<Mezzo>>& mezziDisponibili, 
                            TipoMissione tipo);
};

#endif
