#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <memory>

#include "../include/Caserma.hpp"
#include "../include/Missione.hpp"
#include "../include/Eccezioni.hpp"

using namespace std;

Caserma& Caserma::getInstance() {
    static Caserma instance;
    return instance;
}

void Caserma::aggiungiPersonale(const shared_ptr<Personale>& p) {
    if(personale.aggiungiRisorsa(p)){
        cout << "\nPersonale aggiunto con ID: " << p->getId();
    } else {
        cout << "\nPersonale con ID: " << p->getId() << " è già presente nella Caserma" << endl;
    }
}

void Caserma::aggiungiMezzo(const shared_ptr<Mezzo>& m) {
    if(mezzi.aggiungiRisorsa(m)){
        cout << "\nMezzo aggiunto con ID: " << m->getId();
    } else {
        cout << "\nMezzo con ID: " << m->getId() << " è già presente nella Caserma" << endl;
    }
}

// il for non può ciclare "personale" perchè è shared_ptr<T> quindi lo trasformo con una funzione (GestoreRisorse::getRisorse()) che ritorna un vettore
void Caserma::mostraPersonale() const {
    cout << "\n--- Personale ---\n";
    for (const auto& p : personale.getRisorse())
        cout << p->getId() << " - "
        << p->getNome() << " ("
        << p->gradoToString() << ") ["
        << (p->isDisponibile() ? "Disponibile" : "In missione")
        << (p->isPilota() ? "E' un pilota" : "Non è un pilota") << "]\n";
}

bool Caserma::isMissioneValida(vector<int>& idPersonale, vector<int>& idMezzi, vector<shared_ptr<Personale>>& personaleDisponibile, vector<shared_ptr<Mezzo>>& mezziDisponibili, TipoMissione tipo){
    
    for (int id : idPersonale) {
        shared_ptr<Personale> persona = personale.getById(id);

        if (persona && persona->isDisponibile()){
            personaleDisponibile.push_back(persona);
        } else {
            throw ExceptionPersonale();
        }
    }

    for (int id : idMezzi) {
        shared_ptr<Mezzo> mezzo = mezzi.getById(id);

        if (mezzo && mezzo->isDisponibile()){
            mezziDisponibili.push_back(mezzo);
        } else {
            throw ExceptionPersonale();
        }
    }

    int nMezzi = mezziDisponibili.size();
    int nPersonale = personaleDisponibile.size();
    
    // CONTA QUANTI PILOTI CI SONO IN QUESTA MISSIONE
    int numeroPiloti = 0;
    for(auto& p : personaleDisponibile){
        if(p->isPilota() == true){
            numeroPiloti++;
        }
    }

    // ALMENO UN PILOTA PER MEZZO
    if(numeroPiloti < nMezzi){
        return false;
    }

    // CONTROLLO EQUIPAGGIO PER OGNI MEZZO: PER OGNI MEZZO: MIN 2, MAX 6 PERSONE
    if((nPersonale < 2 * nMezzi) || (nPersonale > 6 * nMezzi)){
        return false;
    }
    
    switch (tipo) { 
        case TipoMissione::SCORTA:
            return nMezzi >= 3;

        case TipoMissione::ASSALTO:
            return nMezzi <= (nPersonale / 5);

        case TipoMissione::ESTRAZIONE:
            int mezziTerrestri = 0;
            for (auto& mezzo : mezziDisponibili) {
                string tipo = mezzo->getTipo();

            // CONTROLLO SCRITTA "TERRESTRE" CASE UNSENSITIVE
            for (auto& c : tipo){
                c = toupper(c);
            }
                if (tipo == "TERRESTRE") {
                    mezziTerrestri++;
                }
            }
            
            return (mezziTerrestri >= 2 && nPersonale >= 5);
        default:
            return false;
    }
}

// CREAZIONE DELLA MISSIONE
void Caserma::creaMissione(const string& descrizione, const vector<shared_ptr<Personale>>& personaleMissione, const vector<shared_ptr<Mezzo>>& mezziMissione, TipoMissione tipo) {
    shared_ptr<Missione> missione = make_shared<Missione>(missioni.size() + 1, descrizione, tipo);
    for (auto p : personaleMissione) {
        missione->assegnaPersonale(p);
    }

    for (auto m: mezziMissione) {
        missione->assegnaMezzo(m);
    }

    missioni.push_back(missione);
}

// il for non può ciclare "personale" perchè è shared_ptr<T> quindi lo trasformo con una funzione (GestoreRisorse::getRisorse()) che ritorna un vettore
void Caserma::mostraPersonale() const {
    cout << "\n--- Personale ---\n";
    for (const auto& p : personale.getRisorse())
        cout << p->getId() << " - "
        << p->getNome() << " ("
        << p->gradoToString() << ") ["
        << (p->isDisponibile() ? "Disponibile" : "In missione")
        << (p->isPilota() ? "E' un pilota" : "Non è un pilota") << "]\n";
}

// il for non può ciclare "mezzi" perchè è shared_ptr<T> quindi lo trasformo con una funzione (GestoreRisorse::getRisorse()) che ritorna un vettore
void Caserma::mostraMezzi() const {
    cout << "\n--- Mezzi ---\n";
    for (const auto& m : mezzi.getRisorse())
        cout << m->getId() << " - "
        << m->getTipo() << " ["
        << (m->isDisponibile() ? "Disponibile" : "In missione") << "]\n";
}

void Caserma::mostraMissioni() const {
    for (const auto& m : missioni){
        m->mostraDettagli();
    }
}

void Caserma::stampaSuFile() {
    ofstream fUscitaCaserma("Caserma.txt");
    //eccezione controllo apertura corretta del file 

    fUscitaCaserma << "================ CASERMA ================" << endl;
    
    fUscitaCaserma << "------------ PERSONALE ------------" << endl;
    fUscitaCaserma << "  id  -  nome  -  grado" << endl;
    for (const auto& p : personale.getRisorse()) {
        fUscitaCaserma << p->getId() << " - " << p->getNome() << " - " << p->gradoToString() << endl;
    }

    fUscitaCaserma << "------------ MEZZI ------------" << endl;
    fUscitaCaserma << "  id  -  tipo" << endl;
    for (const auto& m : mezzi.getRisorse()) {
        fUscitaCaserma << m->getId() << " - " << m->getTipo() << endl;
    }

    fUscitaCaserma << "------------ MISSIONI ------------" << endl;
    for (const auto& m : missioni){
        m->stampaDettagliSuFile(fUscitaCaserma);
    }   
}
