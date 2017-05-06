#ifndef CESAR_H
#define CESAR_H
#include <iostream>
#include "Funciones.h"
#include <string>

using namespace std;

class Cesar
{
private:
    ZZ clave;
    string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
public:
    Cesar();
    string codificar(string cadena);
    string decodificar(string cadena);
};

#endif // CESAR_H
