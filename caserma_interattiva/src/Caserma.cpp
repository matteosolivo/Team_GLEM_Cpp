#include "../include/Caserma.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>

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

void Caserma::creaMissione(const string& descrizione, const vector<int>& idPersonale, const vector<int>& idMezzi) {
    Missione missione(missioni.size() + 1, descrizione);

    TipoMissione t = missione.chooseTipoMissione();
    missione.setTipoMissione(t);
    
    for (int id : idPersonale) {
        Personale* p = personale.getById(id);
        if (p && p->isDisponibile()){
            missione.assegnaPersonale(p); 
            p->setDisponibile(false);
        }
        else cout << "\nPersonale con l'Id: " << id << " non disponibile o non presente in Caserma" << endl; 
    }

    for (int id : idMezzi) {
        Mezzo* m = mezzi.getById(id);
        if (m && m->isDisponibile()){
            missione.assegnaMezzo(m);
            m->setDisponibile(false);
        }
        else cout << "\nMezzo con l'Id: " << id << " non disponibile o non presente in Caserma" << endl;
    }

    int numeroPiloti = 0;
    for(auto& p : Personale){
        if(p.isPilota() == true){
            numeroPiloti++;
        }
    }

    if(numeroPiloti < mezzi.length){
            //eccezione + richiesta di inserire del personale pilota/cambiare le persone assegnateS? altrimenti il codice va avanti e può fare la pushback
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
