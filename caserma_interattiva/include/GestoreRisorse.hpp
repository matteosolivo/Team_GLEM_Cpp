#ifndef GESTORE_RISORSE_HPP
#define GESTORE_RISORSE_HPP

#include <vector>
#include <iostream>

template<typename T>
class GestoreRisorse {
private:
    std::vector<T*> risorse;

public:
    void aggiungi(T* r) {
        for (auto* x : risorse){
            if (x->getId() == r->getId()){ // EVITA DOPPIONI
                return;
            }
        }
        risorse.push_back(r); 
    }   

    void mostraTutte() const {
        for (auto* r : risorse){
            cout << " - " << r->getDescrizione() << (r->isDisponibile() ? " [Disponibile]" : " [Occupata]") << "\n";
        }
    }

    const vector<T*>& getLista() const { return risorse; }
};

#endif
