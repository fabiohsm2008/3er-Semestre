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
    string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
    int clave_a;
    int clave_b;
    int privada;
public:
    Cifrado();
    Cifrado(int a, int b);
    string codificar(string cadena);
    string decodificar(string cadena);

};

#endif // CIFRADO_H
