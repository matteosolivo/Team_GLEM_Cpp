#ifndef GESTORERISORSE_HPP
#define GESTORERISORSE_HPP

#include <vector>

using namespace std;

template <typename T>
class GestoreRisorse {
private:
    vector<T> risorse;

public:
    // return false -> se non esiste
    // return true -> se esiste
    bool esisteRisorsa(int id) const {
        for (const auto& r : risorse){
            if (r->getId() == id){ return true; }
        }
        return false;
    }

    // AGGIUNGE UNA RISORSA AL RISPETTIVO VETTORE RICHIAMANDO IL CONTROLLO DEL DUPLICATO
    bool aggiungiRisorsa(const T& r) {
        if(esisteRisorsa(r->getId())) {
            return false;
        } else {
            risorse.push_back(r);
            return true;
        }
    }

    // RITORNA UN VETTORE DI OGGETTI. UTILE PER LA STAMPA
    const vector<T>& getRisorse() const { return risorse; }

    // RITORNA nullptr SE NON TROVA NULLA
    T getById(int id) const {
        for (const auto& r : risorse){
            if (r->getId() == id){
                return r;
            }
        }
        return T(nullptr);
    }

};

#endif
