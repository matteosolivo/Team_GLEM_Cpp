#include "include/Caserma.hpp"
#include <iostream>
#include <limits>

void menu();
Grado scegliGrado();

int main() {
    // INIZIALIZZAZIONE CASERMA
    Caserma caserma;
    int scelta = 0;

    // MENU INTERATTIVO
    do {
        menu();
        std::cout << "\nScelta: ";
        std::cin >> scelta;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input non valido.\n";
            continue;
        }

        switch (scelta) {
            case 1: { // AGGIUNGI PERSONALE
                std::string nome;
                std::cout << "Inserisci nome del militare: ";
                std::cin.ignore();
                std::getline(std::cin, nome);
                Grado grado = scegliGrado();
                int id = rand() % 1000 + 1; // ID casuale semplice // fare un controllo (principalmente su Caserma) per non inserire duplicati
                caserma.aggiungiPersonale(Personale(id, nome, grado));
                std::cout << "Personale aggiunto con ID " << id << "\n";
                break;
            }

            case 2: { // AGGIUNGI MEZZO
                std::string tipo;
                std::cout << "Inserisci tipo di mezzo (es: Jeep, Camion, Elicottero): ";
                std::cin.ignore();
                std::getline(std::cin, tipo);
                int id = rand() % 1000 + 1; // fare un controllo (principalmente su Caserma) per non inserire duplicati
                caserma.aggiungiMezzo(Mezzo(id, tipo));
                std::cout << "Mezzo aggiunto con ID " << id << "\n";
                break;
            }

            case 3: { // CREA MISSIONE
                std::string descrizione;
                std::cout << "Descrizione missione: ";
                std::cin.ignore();
                std::getline(std::cin, descrizione);

                caserma.mostraPersonale();
                std::cout << "Inserisci ID del personale da assegnare (termina con -1): ";
                std::vector<int> idPersonale;
                int idp;
                while (std::cin >> idp && idp != -1)
                    idPersonale.push_back(idp);

                caserma.mostraMezzi();
                std::cout << "Inserisci ID dei mezzi da assegnare (termina con -1): ";
                std::vector<int> idMezzi;
                int idm;
                while (std::cin >> idm && idm != -1)
                    idMezzi.push_back(idm);

                caserma.creaMissione(descrizione, idPersonale, idMezzi);
                std::cout << "Missione creata!\n";
                break;
            }

            case 4: // MOSTRA PERSONALE
                caserma.mostraPersonale();
                break;

            case 5: // MOSTRA MEZZI
                caserma.mostraMezzi();
                break;

            case 6: // MOSTRA MISSIONI
                caserma.mostraMissioni();
                break;

            case 0: // USCITA
                std::cout << "Uscita...\n";
                break;

            default:
                std::cout << "Scelta non valida!\n";
        }

    } while (scelta != 0);

    return 0;
}

// FUNZIONI DI SUPPORTO AL MAIN
void menu() {
    std::cout << "\n========== GESTIONE CASERMA ==========" << std::endl;
    std::cout << "1. Aggiungi personale" << std::endl;
    std::cout << "2. Aggiungi mezzo" << std::endl;
    std::cout << "3. Crea missione" << std::endl;
    std::cout << "4. Mostra personale" << std::endl;
    std::cout << "5. Mostra mezzi" << std::endl;
    std::cout << "6. Mostra missioni" << std::endl;
    std::cout << "0. Esci" << std::endl;
}

Grado scegliGrado() {
    int g;
    std::cout << "Scegli grado:\n";
    std::cout << "1. Soldato\n2. Caporale\n3. Sergente\n4. Tenente\n5. Capitano\n6. Maggiore\n";
    std::cout << "Scelta: ";
    std::cin >> g;

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
