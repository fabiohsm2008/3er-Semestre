#ifndef RSA_H
#define RSA_H
#include "Funciones.h"
#include <string>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

class RSA
{
private:
    ZZ publica, privada, N;
    string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYX .,;";

public:
    ZZ get_publica();
    ZZ get_N();
    RSA(ZZ pu, ZZ n);
    RSA();
    ZZ* cifrar(string mensaje);
    string descifrar(ZZ* mensaje, int tama);

};

#endif // RSA_H
