#ifndef GESTORERISORSE_HPP
#define GESTORERISORSE_HPP

#include <vector>

template <typename T>
class GestoreRisorse {
private:
    vector<T> risorse;

public:
    void aggiungiRisorsa(const T& r) {
        bool esiste = false;
        for (const auto& esistente : risorse){
            if (esistente.getId() == r.getId())
                esiste = true;
        } 
        if(!esiste)
            risorse.push_back(r);
        else cout << "\nRisorsa con Id: " << r.getId() << "è già presente in Caserma" << endl;
    }

    bool esisteRisorsa(int id) const {
        for (const auto& r : risorse){
            if (r.getId() == id){
                return true;
        return false;
            }
        }
    }

    T* getById(int id) {
        for (auto& r : risorse){
            if (r.getId() == id){
                return &r;
            }
        return nullptr;
        }
    }

    void stampaTutte() const {
        for (const auto& r : risorse){
            r.stampa();
        }
    }
};

#endif
