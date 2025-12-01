#include <iostream>

#include "../include/Eccezioni.hpp"

using namespace std;

// ECCEZIONE PER IL PERSONALE PERSONALIZZATA
void ExceptionPersonale::showMessageP(const string &message)
{
    cerr << "ERRORE: " << message << endl;
}

// ECCEZIONE PER I MEZZI PERSONALIZZATA
void ExceptionMezzo::showMessageM(const string &message)
{
    cerr << "ERRORE: " << message << endl;
}

// ECCEZIONE PER I FILE PERSONALIZZATA
void FileException::showMessageF(const string &message)
{
    cerr << "ERRORE: " << message << endl;
}