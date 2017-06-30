#ifndef RSA_H
#define RSA_H
#include <string>
#include "Funciones.h"

using namespace std;

class RSA
{
private:
    ZZ d;
    ZZ e;
    ZZ N;
    ZZ p;
    ZZ q;
    string alfabeto = "0123456789 abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    RSA(int bits);
    RSA(ZZ,ZZ);
    string cifrar(string);
    string descifrar(string);
    void generar_claves(int);
    ZZ chino_RSA(ZZ);
    ///###############################
    void impr_claves();
};

#endif // RSA_H
