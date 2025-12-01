#ifndef ECCEZIONI_HPP
#define ECCEZIONI_HPP

#include <iostream>
#include <string>

// CLASSE PER GESTIONE ECCEZIONI PERSONALE
class ExceptionPersonale
{
public:
    void showMessageP(const std::string &msg);
};

// CLASSE PER GESTIONE ECCEZIONI MEZZO
class ExceptionMezzo
{
public:
    void showMessageM(const std::string &msg);
};

// CLASSE PER GESTIONE ECCEZIONI FILE
class FileException
{
public:
    void showMessageF(const std::string &msg);
};

#endif
