// Eccezioni.hpp
#ifndef ECCEZIONI_HPP
#define ECCEZIONI_HPP

#include <iostream>
#include <string>

class ExceptionPersonale {
public:
    void showMessageP(const std::string& msg);
};

class ExceptionMezzo {
public:
    void showMessageM(const std::string& msg);
};

class FileException {
public:
    void showMessageF(const std::string& msg);
};

#endif
