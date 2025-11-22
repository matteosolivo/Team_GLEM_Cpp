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

    this->tipo = t;
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

    
    missioni.push_back(missione);
}

void Caserma::mostraPersonale() const { personale.stampaTutte(); }
void Caserma::mostraMezzi() const { mezzi.stampaTutte(); }
void Caserma::mostraMissioni() const {
    for (const auto& m : missioni){
        m.mostraDettagli();
    }
}


void stampaSuFile() const{
    sdt::ofstream output("Caserma.txt");
    //eccezione controllo apertura corretta del file 

    output << "================ CASERMA ================" << std::endl;
    
    output << "------------ PERSONALE ------------" << std::endl;
    output << "  id  -  nome  -  grado" << std::endl;
    for (const auto& p : personale)
        std::output << p.getId() << " - " << p.getNome() << " - " << p.getGrado() << std::endl;
    
    output << "------------ MEZZI ------------" << std::endl;
    output << "  id  -  tipo" << std::endl;
    for (const auto& m : mezzi)
        std::output << m.getId() << " - " << m.getTipo() << std::endl;
    
    output << "------------ MISSIONI ------------" << std::endl;
    for (const auto& m : missioni){
        m.stampaDettagliSuFile(/*riferimento al file aperto*/);
    }   
}
