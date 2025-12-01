#include "../include/Caserma.hpp"
#include "../include/Eccezioni.hpp"

#include <limits>
#include <stdexcept>

using namespace std;

void menu();
Grado scegliGrado();
TipoMissione chooseTipoMissione();
bool scegliPilota();

int main()
{
    // CREAZIONE ISTANZA CASERMA (SINGLETON)
    Caserma &caserma = Caserma::getInstance();
    int scelta = 0;

    // MENU INTERATTIVO
    do
    {
        menu();
        cout << "\nScelta: ";
        cin >> scelta;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input non valido.\n";
            continue;
        }

        switch (scelta)
        {
        case 1: // AGGIUNGI PERSONALE
        {
            string nome;
            cout << "Inserisci nome del militare: ";
            cin.ignore();
            getline(cin, nome);
            Grado grado = scegliGrado();
            bool isPilota = scegliPilota();
            int id = rand() % 1000 + 1; // ID casuale. Controllo inserimento su GestoreRisorse.hpp
            caserma.aggiungiPersonale(make_shared<Personale>(id, nome, grado, isPilota));
            break;
        }

        case 2: // AGGIUNGI MEZZO
        {
            string tipo;
            cout << "Inserisci tipo di mezzo (es: Jeep, Camion, Elicottero): ";
            cin.ignore();
            getline(cin, tipo);
            int id = rand() % 1000 + 1; // ID casuale. Controllo inserimento su GestoreRisorse.hpp
            caserma.aggiungiMezzo(make_shared<Mezzo>(id, tipo));
            break;
        }

        case 3: // CREA MISSIONE
        {
            string descrizione;
            cout << "Descrizione missione: (default: Nessuna descrizione fornita): ";
            cin.ignore();
            getline(cin, descrizione);
            if (descrizione.length() == 0)
            {
                descrizione = "Nessuna descrizione fornita.";
            }

            caserma.mostraPersonale();
            cout << "Inserisci ID del personale da assegnare (termina con -1): ";
            vector<int> idPersonale;
            int idp;
            try
            {
                // ne inserisce uno alla volta fino a che non inserisce -1
                while (cin >> idp && idp != -1)
                    idPersonale.push_back(idp);
            }
            catch (const invalid_argument &e)
            {
                cout << "Errore: tipo di dato inserito sbagliato!\n";
            }

            caserma.mostraMezzi();
            cout << "Inserisci ID dei mezzi da assegnare (termina con -1): ";
            vector<int> idMezzi;
            int idm;
            try
            {
                // ne inserisce uno alla volta fino a che non inserisce -1
                while (cin >> idm && idm != -1)
                    idMezzi.push_back(idm);
            }
            catch (const invalid_argument &e)
            {
                cout << "Errore: tipo di dato inserito sbagliato!\n";
            }

            TipoMissione tipo = chooseTipoMissione();

            try
            {
                vector<shared_ptr<Personale>> personaleDisponibile;
                vector<shared_ptr<Mezzo>> mezziDisponibili;
                bool isMissioneValida = caserma.isMissioneValida(idPersonale, idMezzi, personaleDisponibile, mezziDisponibili, tipo);

                if (isMissioneValida)
                {
                    caserma.creaMissione(descrizione, personaleDisponibile, mezziDisponibili, tipo);
                    cout << "Missione creata!\n";
                }
            }
            catch (ExceptionPersonale e)
            {
                e.showMessageP("Personale non presente in caserma o non disponibile");
            }
            catch (ExceptionMezzo e)
            {
                e.showMessageM("Mezzo non presente in caserma o non disponibile");
            }

            break;
        }

        case 4: // MOSTRA PERSONALE
        {
            caserma.mostraPersonale();
            break;
        }
        case 5: // MOSTRA MEZZI
        {
            caserma.mostraMezzi();
            break;
        }
        case 6: // MOSTRA MISSIONI
        {
            caserma.mostraMissioni();
            break;
        }
        case 7: // STAMPA SU FILE
        {
            try
            {
                caserma.stampaSuFile();
            }
            catch (FileException e)
            {
                e.showMessageF("Errore con il salvataggio del file!");
            }
            break;
        }

        case 0: // ESCI
        {
            cout << "Uscita...\n";
            break;
        }
        default:
            cout << "Scelta non valida!\n";
        }

    } while (scelta != 0);

    return 0;
}

// FUNZIONI DI SUPPORTO AL MAIN
void menu()
{
    cout << "\n========== GESTIONE CASERMA ==========" << endl;
    cout << "1. Aggiungi personale" << endl;
    cout << "2. Aggiungi mezzo" << endl;
    cout << "3. Crea missione" << endl;
    cout << "4. Mostra personale" << endl;
    cout << "5. Mostra mezzi" << endl;
    cout << "6. Mostra missioni" << endl;
    cout << "7. Stampa resoconto Caserma su file txt" << endl;
    cout << "0. Esci" << endl;
}

bool scegliPilota()
{
    int sceltaPilota = 0;
    cout << "\nIl militare è un pilota?: (default: No) \n"
         << "1. Si\n0. No\nScelta: ";
    cin >> sceltaPilota;
    switch (sceltaPilota)
    {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return false;
    }
}

Grado scegliGrado()
{
    int g;
    cout << "\nScegli grado: (default: Soldato)\n";
    cout << "1. Soldato\n2. Caporale\n3. Sergente\n4. Tenente\n5. Capitano\n6. Maggiore\n";
    cout << "Scelta: ";
    cin >> g;

    switch (g)
    {
    case 1:
        return Grado::SOLDATO;
    case 2:
        return Grado::CAPORALE;
    case 3:
        return Grado::SERGENTE;
    case 4:
        return Grado::TENENTE;
    case 5:
        return Grado::CAPITANO;
    case 6:
        return Grado::MAGGIORE;
    default:
        return Grado::SOLDATO;
    }
}

TipoMissione chooseTipoMissione()
{
    int sceltaTipoMissione;
    cout << "Scegli tipo Missione: (default: Scorta)\n";
    cout << "1. Scorta\n2. Assalto\n3. Estrazione\n";
    cout << "Scelta: ";
    cin >> sceltaTipoMissione;

    switch (sceltaTipoMissione)
    {
    case 1:
        return TipoMissione::SCORTA;
    case 2:
        return TipoMissione::ASSALTO;
    case 3:
        return TipoMissione::ESTRAZIONE;
    default:
        return TipoMissione::SCORTA;
    }
}