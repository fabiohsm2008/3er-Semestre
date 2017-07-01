#ifndef PROTOCOLO_H
#define PROTOCOLO_H
#include "Funciones.h"

class Protocolo
{
private:
    ZZ p1;
    ZZ p2;
    ZZ q;
    ZZ g;
    ZZ N1;
    ZZ e1;
    ZZ D;
    ZZ e2;
    ZZ N2;
    string alfabeto = "0123456789 abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string firma = "128128128128128128128128128128128128128128128128128128128128128128128128128128128";
public:
    Protocolo(int bits);
    Protocolo(ZZ publicaE, ZZ publicaN, int bits);
    string cifrar(string mensaje);
    string descifrar(string mensaje_cifrado);
    string firmar();
    void generar_aleatorios(int bits);
    virtual ~Protocolo();
};

#endif // PROTOCOLO_H
