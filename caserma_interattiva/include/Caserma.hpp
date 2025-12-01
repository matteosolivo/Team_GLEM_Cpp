#ifndef CASERMA_HPP
#define CASERMA_HPP

#include <memory>

#include "GestoreRisorse.hpp"
#include "Personale.hpp"
#include "Mezzo.hpp"
#include "Missione.hpp"

class Caserma
{
private:
    // COSTRUTTORE PER SINGLETON (private COSI NON PUO' ESSERE USATO ALL'ESTERNO)
    Caserma() = default;
    Caserma(const Caserma &) = delete;
    Caserma &operator=(const Caserma &) = delete;

    GestoreRisorse<std::shared_ptr<Personale>> personale;
    GestoreRisorse<std::shared_ptr<Mezzo>> mezzi;
    std::vector<std::shared_ptr<Missione>> missioni;

public:
    // METODO STATICO DI CLASSE PER RILEVARE L'ISTANZA
    static Caserma &getInstance();

    void aggiungiPersonale(const std::shared_ptr<Personale> &p);
    void aggiungiMezzo(const std::shared_ptr<Mezzo> &m);

    void creaMissione(const std::string &descrizione,
                      const std::vector<std::shared_ptr<Personale>> &personaleMissione,
                      const std::vector<std::shared_ptr<Mezzo>> &mezziMissione,
                      TipoMissione t);

    void mostraPersonale() const;
    void mostraMezzi() const;
    void mostraMissioni() const;
    void stampaSuFile();
    bool isMissioneValida(std::vector<int> &idPersonale,
                          std::vector<int> &idMezzi,
                          std::vector<std::shared_ptr<Personale>> &personaleDisponibile,
                          std::vector<std::shared_ptr<Mezzo>> &mezziDisponibili,
                          TipoMissione tipo) const;
};

#endif
