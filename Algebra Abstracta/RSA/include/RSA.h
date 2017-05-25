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
    string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,;#";
public:
    RSA(int bits);
    RSA(ZZ,ZZ);
    string cifrar(string);
    string descifrar(string);
    void generar_claves(int);
    ZZ chino_RSA(ZZ);
    ///###############################
    ZZ get_d();
    ZZ get_e();
    ZZ get_N();
    ZZ get_p();
    ZZ get_q();
    void set_p(ZZ a);
    void set_q(ZZ b);
    void set_N(ZZ c);
    void set_d(ZZ x);
};

#endif // RSA_H
