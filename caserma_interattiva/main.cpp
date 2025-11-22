#include "include/Caserma.hpp"
#include <iostream>
#include <limits>

void menu();
Grado scegliGrado();

int main() {
    Caserma& caserma = Caserma::getInstance();
    int scelta = 0;

    do {
        menu();
        cout << "\nScelta: ";
        cin >> scelta;

        if (std::cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Input non valido.\n";
            continue;
        }

        switch (scelta) {
            case 1: {
                string nome;
                cout << "Inserisci nome del militare: ";
                cin.ignore();
                getline(std::cin, nome);
                Grado grado = scegliGrado();
                int id = rand() % 1000 + 1;  // ID casuale. Controllo inserimento su GestoreRisorse.hpp
                caserma.aggiungiPersonale(Personale(id, nome, grado));
                cout << "Personale aggiunto con ID " << id << "\n";
                break;
            }

            case 2: {
                string tipo;
                cout << "Inserisci tipo di mezzo (es: Jeep, Camion, Elicottero): ";
                cin.ignore();
                getline(std::cin, tipo);
                int id = rand() % 1000 + 1; // ID casuale. Controllo inserimento su GestoreRisorse.hpp
                caserma.aggiungiMezzo(Mezzo(id, tipo));
                cout << "Mezzo aggiunto con ID " << id << "\n";
                break;
            }

            case 3: {
                string descrizione;
                cout << "Descrizione missione: ";
                cin.ignore();
                getline(std::cin, descrizione);

                caserma.mostraPersonale();
                cout << "Inserisci ID del personale da assegnare (termina con -1): ";
                vector<int> idPersonale;
                int idp;
                while (std::cin >> idp && idp != -1)
                    idPersonale.push_back(idp);

                caserma.mostraMezzi();
                cout << "Inserisci ID dei mezzi da assegnare (termina con -1): ";
                vector<int> idMezzi;
                int idm;
                while (std::cin >> idm && idm != -1)
                    idMezzi.push_back(idm);

                caserma.creaMissione(descrizione, idPersonale, idMezzi);
                cout << "Missione creata!\n";
                break;
            }

            case 4:
                caserma.mostraPersonale();
                break;

            case 5:
                caserma.mostraMezzi();
                break;

            case 6:
                caserma.mostraMissioni();
                break;

            case 7:{
                caserma.stampaSuFile();
                break;
            }                               

            case 0:
                cout << "Uscita...\n";
                break;

            default:
                cout << "Scelta non valida!\n";
        }

    } while (scelta != 0);

    return 0;
}

void menu() {
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

Grado scegliGrado() {
    int g;
    cout << "Scegli grado:\n";
    cout << "1. Soldato\n2. Caporale\n3. Sergente\n4. Tenente\n5. Capitano\n6. Maggiore\n";
    cout << "Scelta: ";
    cin >> g;

    switch (g) {
        case 1: return Grado::SOLDATO;
        case 2: return Grado::CAPORALE;
        case 3: return Grado::SERGENTE;
        case 4: return Grado::TENENTE;
        case 5: return Grado::CAPITANO;
        case 6: return Grado::MAGGIORE;
        default: return Grado::SOLDATO;
    }
}
