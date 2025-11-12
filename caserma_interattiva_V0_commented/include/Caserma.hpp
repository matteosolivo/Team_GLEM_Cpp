#ifndef CASERMA_HPP // sono "include guards". Prevengono la doppia inclusione dell'header (sarà includo solo dalla prima classe che lo include, ovvero, in questo caso, Caserma.cpp)
#define CASERMA_HPP // questo definisce l' header con il nome CASERMA_HPP utilizzazto dall' include guard sopra

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
// AGGIUNTA OGGETTI SINGOLI                    // const impedisce di modificare p dentro la funzione
    void aggiungiPersonale(const Personale& p);// Personale& p è un passaggio per riferimento (evida duplicazioni)
    void aggiungiMezzo(const Mezzo& m);


// CREAZIONE DI OGGETTI DI OGGETTI
    void creaMissione(const std::string& descrizione,
                      const std::vector<int>& idPersonale,// sta passando un vettore per riferimento..
                                                     // ..(quindi memory address dove è contenuto il valore dall'indice 0)
                      const std::vector<int>& idMezzi);

// VISUALIZZAZIONE
    void mostraPersonale() const; // const alla fine serve per garantire che lo stato dell'oggetto non sarà modificato
    void mostraMezzi() const;
    void mostraMissioni() const;
};

#endif // fine dello scope dell' include guard '#ifndef'
