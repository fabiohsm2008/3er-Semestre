#ifndef CIFRADO_H
#define CIFRADO_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Funciones.h"

using namespace std;

class Cifrado
{
private:
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    int clave_a;
    int clave_b;
    int privada;
public:
    Cifrado();
    string codificar(string cadena);
    string decodificar(string cadena);

};

#endif // CIFRADO_H
