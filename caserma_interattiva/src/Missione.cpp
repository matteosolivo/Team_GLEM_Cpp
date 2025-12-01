#include <iostream>
#include <memory>

#include "../include/Missione.hpp"

using namespace std;

Missione::Missione(int id, const string &descrizione, TipoMissione tipo)
    : id(id), descrizione(descrizione), tipo(tipo) {}

// ASSEGNA PERSONALE ALLA MISSIONE E LO IMPOSTA COME NON DISPONIBILE
void Missione::assegnaPersonale(shared_ptr<Personale> &p)
{
    personaleAssegnato.aggiungiRisorsa(p);
    p->setDisponibile(false);
}

// ASSEGNA MEZZO ALLA MISSIONE E LO IMPOSTA COME NON DISPONIBILE
void Missione::assegnaMezzo(shared_ptr<Mezzo> &m)
{
    mezziAssegnati.aggiungiRisorsa(m);
    m->setDisponibile(false);
}

// RITORNA LA RAPPRESENTAZIONE TESTUALE DEL TIPO DI MISSIONE
string Missione::tipoMissioneToString() const
{
    switch (tipo)
    {
    case TipoMissione::SCORTA:
        return "Scorta";
    case TipoMissione::ASSALTO:
        return "Assalto";
    case TipoMissione::ESTRAZIONE:
        return "Estrazione";
    default:
        return "Sconosciuto";
    }
}

// MOSTRA I DETTAGLI DELLA MISSIONE A SCHERMO
void Missione::mostraDettagli() const
{
    cout << "\n=== Missione " << id << " ===\n";
    cout << "Tipo di Missione: " << tipoMissioneToString() << "\n";
    cout << "Descrizione: " << descrizione << "\n";

    cout << "Personale assegnato:\n";
    for (auto p : personaleAssegnato.getRisorse())
    {
        p->getDescrizione();
    }
    cout << "Mezzi assegnati:\n";
    for (auto m : mezziAssegnati.getRisorse())
    {
        m->getDescrizione();
    }

    cout << endl;
}

// IMPOSTA IL TIPO DI MISSIONE
void Missione::setTipoMissione(TipoMissione t)
{
    tipo = t;
}

// STAMPA I DETTAGLI DELLA MISSIONE SU FILE
void Missione::stampaDettagliSuFile(ofstream &output) const
{
    output << "=== Missione " << id << " ===\n";
    output << "Tipo di Missione: " << tipoMissioneToString() << "\n";
    output << "Descrizione: " << descrizione << "\n";

    output << "Personale assegnato:\n";
    for (auto p : personaleAssegnato.getRisorse())
    {
        output << " - " << p->getNome() << " (" << p->gradoToString() << ")\n";
    }
    output << "Mezzi assegnati:\n";
    for (auto m : mezziAssegnati.getRisorse())
    {
        output << " - " << m->getTipo() << "\n";
    }
    cout << endl;
}
