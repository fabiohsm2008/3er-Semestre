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
    ZZ get_d();
    ZZ get_e();
    ZZ get_N();
    ZZ get_p();
    ZZ get_q();
    void set_p(ZZ a);
    void set_q(ZZ b);
    void set_N(ZZ c);
    void set_d(ZZ x);
    void set_e(ZZ y);
    void impr_claves();
};

#endif // RSA_H
