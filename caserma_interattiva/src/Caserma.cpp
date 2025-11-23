#include "../include/Caserma.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>
using namespace std;

Caserma& Caserma::getInstance() {
    static Caserma instance;
    return instance;
}

void Caserma::aggiungiPersonale(const Personale& p) {
    if (personale.esisteRisorsa(p.getId())){
        personale.aggiungiRisorsa(p);
    }
}

void Caserma::aggiungiMezzo(const Mezzo& m) {
    if (mezzi.esisteRisorsa(m.getId())){
        mezzi.aggiungiRisorsa(m);
    }
}

bool isMissioneValida(vector<int>& idPersonale, vector<int>& idMezzi, vector<Personale>& personaleDisponibile, vector<Mezzo>& mezziDisponibili, TipoMissione tipo){
    
    for (int id : idPersonale) {
        Personale* p = personale.getById(id);
        if (p && p->isDisponibile()){
            personaleDisponibile.push_back(p)
        }
        else cout << "\nPersonale con l'Id: " << id << " non disponibile o non presente in Caserma" << endl; 
    }

    for (int id : idMezzi) {
        Mezzo* m = mezzi.getById(id);
        if (m && m->isDisponibile()){
            mezziDisponibili.push_back(m)
        }
        else cout << "\nMezzo con l'Id: " << id << " non disponibile o non presente in Caserma" << endl;
    }

    nMezzi = mezziDisponibili.length();
    nPersonali = personaleDisponibile.length();
    
    //controllo piloti
    int numeroPiloti = 0;
    for(auto& p : personaleDisponibile){
        if(p.isPilota() == true){
            numeroPiloti++;
        }
    }
    if(numeroPiloti < nMezzi){
        return false;
    }
    //controllo personale assegnato per mezzo (equipaggio): ogni mezzo min 2 pers, max 6 pers
    if((nPersonale < 2*nMezzi) || (nPersonale > 6*nMezzi)){
        return false;
    }
    
    //controllo tipoMissione
    if((tipo == SCORTA) && (nMezzi >= 3)){
        return true;
    } else {
        return false;
    }
    
    if((tipo == ASSALTO) && (static_cast<int>(nPersonale/5) == nMezzi)){
        return true;
    } else {
        return false;
    } 
    
    if((tipo == ESTRAZIONE) && (nPersonale >= 5)){
        int mezziTerrestri = 0;
        for(auto& mezzo : mezziDisponibili){
            if((strcmp(mezzo.getTipo(), "Terrestre")) == 0){
                mezziTerrestri++;
            }
        }
        if(mezziTerrestri <= 2){
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
    
}

void Caserma::creaMissione(const string& descrizione, const vector<Personale>& personaleMissione, const vector<Mezzo>& mezziMissione, TipoMissione t) {
    Missione missione(missioni.size() + 1, descrizione, t);
    for (Personale p : personaleMissione) {
        missione.assegnaPersonale(p);
    }

    for (Mezzo m: mezziMissione) {
        missione.assegnaMezzo(p);
    }

    missioni.push_back(missione);
}

void Caserma::mostraPersonale() const {
    std::cout << "\n--- Personale ---\n";
    for (const auto& p : personale)
        std::cout << p.getId() << " - " << p.getNome() << " (" << p.gradoToString()
                  << ") [" << (p.isDisponibile() ? "Disponibile" : "In missione")
                  << (p.isPilota() ? "E' un pilota" : "Non è un pilota") << "]\n";
}

void Caserma::mostraMezzi() const {
    std::cout << "\n--- Mezzi ---\n";
    for (const auto& m : mezzi)
        std::cout << m.getId() << " - " << m.getTipo()
                  << " [" << (m.isDisponibile() ? "Disponibile" : "In missione") << "]\n";
}

void Caserma::mostraPersonale() const { personale.stampaTutte(); }
void Caserma::mostraMezzi() const { mezzi.stampaTutte(); }
void Caserma::mostraMissioni() const {
    for (const auto& m : missioni){
        m.mostraDettagli();
    }
}


void stampaSuFile() const{
    std::ofstream fUscitaCaserma("Caserma.txt");
    //eccezione controllo apertura corretta del file 

    fUscitaCaserma << "================ CASERMA ================" << std::endl;
    
    fUscitaCaserma << "------------ PERSONALE ------------" << std::endl;
    fUscitaCaserma << "  id  -  nome  -  grado" << std::endl;
    for (const auto& p : personale)
        std::fUscitaCaserma << p.getId() << " - " << p.getNome() << " - " << p.getGrado() << std::endl;
    
    fUscitaCaserma << "------------ MEZZI ------------" << std::endl;
    fUscitaCaserma << "  id  -  tipo" << std::endl;
    for (const auto& m : mezzi)
        std::fUscitaCaserma << m.getId() << " - " << m.getTipo() << std::endl;
    
    fUscitaCaserma << "------------ MISSIONI ------------" << std::endl;
    for (const auto& m : missioni){
        m.stampaDettagliSuFile(fUscitaCaserma);
    }   
}
