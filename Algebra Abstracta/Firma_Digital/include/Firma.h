#ifndef FIRMA_H
#define FIRMA_H
#include <string>
#include "Funciones.h"

class Firma
{
private:
    ZZ d;
    ZZ e;
    ZZ N;
    ZZ p;
    ZZ q;
    ZZ e_publica;
    ZZ N_publica;
    string alfabeto = "0123456789 abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string firma = "Fabio Soto Mejia";
public:
    Firma(int bits);
    Firma(ZZ,ZZ,int);
    string cifrar(string);
    string descifrar(string);
    void generar_claves(int);
    ZZ chino_Firma(ZZ);
    void impr_claves();
    string firmar();
};

#endif // FIRMA_H
