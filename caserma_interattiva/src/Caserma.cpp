#include <stdexcept>

#include "../include/Caserma.hpp"
#include "../include/Missione.hpp"
#include "../include/Eccezioni.hpp"

using namespace std;

// SINGLETON: RITORNA L'UNICA ISTANZA DI CASERMA
Caserma &Caserma::getInstance()
{
    static Caserma instance;
    return instance;
}

// AGGIUNTA PERSONALE ED EFFETTUA IL CONTROLLO SUI DUPLICATI
void Caserma::aggiungiPersonale(const shared_ptr<Personale> &p)
{
    if (personale.aggiungiRisorsa(p))
    {
        cout << "\nPersonale aggiunto con ID: " << p->getId() << endl;
    }
    else
    {
        cout << "\nPersonale con ID: " << p->getId() << " è già presente nella Caserma\n"
             << endl;
    }
}

// AGGIUNTA MEZZO ED EFFETTUA IL CONTROLLO SUI DUPLICATI
void Caserma::aggiungiMezzo(const shared_ptr<Mezzo> &m)
{
    if (mezzi.aggiungiRisorsa(m))
    {
        cout << "\nMezzo aggiunto con ID: " << m->getId() << endl;
    }
    else
    {
        cout << "\nMezzo con ID: " << m->getId() << " è già presente nella Caserma\n"
             << endl;
    }
}

// CONTROLLO VALIDITÀ MISSIONE RISPETTO AI VINCOLI RICHIESTI
bool Caserma::isMissioneValida(vector<int> &idPersonale, vector<int> &idMezzi, vector<shared_ptr<Personale>> &personaleDisponibile, vector<shared_ptr<Mezzo>> &mezziDisponibili, TipoMissione tipo) const
{

    for (int id : idPersonale)
    {
        shared_ptr<Personale> persona = personale.getById(id);

        // CONTROLLA SE IL PERSONALE ESISTE ED È DISPONIBILE
        if (persona && persona->isDisponibile())
        {
            personaleDisponibile.push_back(persona);
        }
        else
        {
            throw ExceptionPersonale();
        }
    }

    for (int id : idMezzi)
    {
        shared_ptr<Mezzo> mezzo = mezzi.getById(id);

        // CONTROLLA SE IL MEZZO ESISTE ED È DISPONIBILE
        if (mezzo && mezzo->isDisponibile())
        {
            mezziDisponibili.push_back(mezzo);
        }
        else
        {
            throw ExceptionPersonale();
        }
    }

    int nMezzi = mezziDisponibili.size();
    int nPersonale = personaleDisponibile.size();

    // CONTA QUANTI PILOTI CI SONO IN QUESTA MISSIONE
    int numeroPiloti = 0;
    for (auto &p : personaleDisponibile)
    {
        if (p->isPilota() == true)
        {
            numeroPiloti++;
        }
    }

    // ALMENO UN PILOTA PER MEZZO
    if (numeroPiloti < nMezzi)
    {
        return false;
    }

    // CONTROLLO EQUIPAGGIO PER OGNI MEZZO (MIN 2, MAX 6 PERSONE)
    if ((nPersonale < 2 * nMezzi) || (nPersonale > 6 * nMezzi))
    {
        return false;
    }

    // CONTROLLO IN BASE AL TIPO DI MISSIONE
    switch (tipo)
    {
    case TipoMissione::SCORTA:
        return nMezzi >= 3;

    case TipoMissione::ASSALTO:
        return nMezzi <= (nPersonale / 5);

    case TipoMissione::ESTRAZIONE:
    {
        int mezziTerrestri = 0;
        for (auto &mezzo : mezziDisponibili)
        {
            string tipo = mezzo->getTipo();

            // CONTROLLO SCRITTA "TERRESTRE" SU TIPO MEZZO (CASE UNSENSITIVE)
            for (auto &c : tipo)
            {
                c = toupper(c);
            }
            if (tipo == "TERRESTRE")
            {
                mezziTerrestri++;
            }
        }

        return (mezziTerrestri >= 2 && nPersonale >= 5);
    }
    default:
        return false;
    }
}

// CREAZIONE DELLA MISSIONE
void Caserma::creaMissione(const string &descrizione, const vector<shared_ptr<Personale>> &personaleMissione, const vector<shared_ptr<Mezzo>> &mezziMissione, TipoMissione tipo)
{
    shared_ptr<Missione> missione = make_shared<Missione>(missioni.size() + 1, descrizione, tipo);
    for (auto p : personaleMissione)
    {
        missione->assegnaPersonale(p);
    }

    for (auto m : mezziMissione)
    {
        missione->assegnaMezzo(m);
    }

    missioni.push_back(missione);
}

// IL FOR NON PUÒ CICLARE "personale" PERCHÉ È shared_ptr<T> QUINDI LO TRASFORMO CON UNA FUNZIONE (GestoreRisorse::getRisorse()) CHE RITORNA UN VETTORE
void Caserma::mostraPersonale() const
{
    cout << "\n--- Personale ---\n";
    for (const auto &p : personale.getRisorse())
        cout << p->getId() << " - "
             << p->getNome() << " ("
             << p->gradoToString() << ") ["
             << (p->isDisponibile() ? "Disponibile - " : "In missione ")
             << (p->isPilota() ? "E' un pilota " : "Non è un pilota ") << "]\n";
}

// IL FOR NON PUÒ CICLARE "mezzi" PERCHÉ È shared_ptr<T> QUINDI LO TRASFORMO CON UNA FUNZIONE (GestoreRisorse::getRisorse()) CHE RITORNA UN VETTORE
void Caserma::mostraMezzi() const
{
    cout << "\n--- Mezzi ---\n";
    for (const auto &m : mezzi.getRisorse())
        cout << m->getId() << " - "
             << m->getTipo() << " ["
             << (m->isDisponibile() ? "Disponibile" : "In missione") << "]\n";
}

// MOSTRA DETTAGLI DELLE MISSIONI CONTROLLANDO SE CI SONO MISSIONI
void Caserma::mostraMissioni() const
{
    if (!missioni.empty())
    {
        for (const auto &m : missioni)
        {
            m->mostraDettagli();
        }
    }
    else
    {
        cout << "\nNessuna missione presente in caserma.\n";
    }
}

// STAMPA SU FILE TUTTO IL RIEPILOGO DELLA CASERMA (PERSONALE, MEZZI, MISSIONI)
void Caserma::stampaSuFile()
{
    string nomeFile = "Caserma.txt";
    ofstream fUscitaCaserma(nomeFile);
    // eccezione controllo apertura corretta del file

    fUscitaCaserma << "================ CASERMA ================" << endl;

    // STAMPA PERSONALE
    if (!personale.getRisorse().empty())
    {
        fUscitaCaserma << "\n------------ PERSONALE ------------" << endl;
        fUscitaCaserma << "  id  -  nome  -  grado" << endl;
        for (const auto &p : personale.getRisorse())
        {
            fUscitaCaserma << p->getId() << " - " << p->getNome() << " - " << p->gradoToString() << endl;
        }
    }
    else
    {
        fUscitaCaserma << "\nNessun personale presente in caserma.\n";
    }

    // STAMPA MEZZI
    if (!mezzi.getRisorse().empty())
    {
        fUscitaCaserma << "\n------------ MEZZI ------------" << endl;
        fUscitaCaserma << "  id  -  tipo" << endl;
        for (const auto &m : mezzi.getRisorse())
        {
            fUscitaCaserma << m->getId() << " - " << m->getTipo() << endl;
        }
    }
    else
    {
        fUscitaCaserma << "\nNessun mezzo presente in caserma.\n";
    }

    // STAMPA MISSIONI
    if (!missioni.empty())
    {
        fUscitaCaserma << "\n------------ MISSIONI ------------" << endl;
        for (const auto &m : missioni)
        {
            m->stampaDettagliSuFile(fUscitaCaserma);
        }
    }
    else
    {
        fUscitaCaserma << "\nNessuna missione presente in caserma.\n";
    }

    // NON NECESSARIO IL CONTROLLO DI CHIUSURA MA LO ABBIAMO MESSO PER MAGGIOR SICUREZZA
    fUscitaCaserma.close();

    cout << "\nResoconto caserma salvato su file '" << nomeFile << endl;
}
