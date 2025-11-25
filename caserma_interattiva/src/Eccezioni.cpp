#include <iostream>

#include "../include/Eccezioni.hpp"

using namespace std;

void ExceptionPersonale::showMessageP(const string& message){
    cerr << "ERRORE: " << message << endl;
}

void ExceptionMezzo::showMessageM(const string& message){
    cerr << "ERRORE: " << message << endl;
}