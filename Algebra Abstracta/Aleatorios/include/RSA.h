#ifndef RSA_H
#define RSA_H
#include <string>
#include <vector>
#include "Funciones.h"
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
class RSA
{
    std::string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;";
    ZZ clave_publica, clave_privada, N;
    void generar_claves();
    public:
        RSA(ZZ e, ZZ n);
        RSA();
        ZZ get_N();
        ZZ get_clave_publica();
        vector <ZZ> cifrar(string mensaje);
        string descifrar(vector <ZZ> mensaje_cifrado);
        void set_publica(ZZ a);
        void set_privada(ZZ b);
        void set_N(ZZ c);
};
#endif // RSA_H
