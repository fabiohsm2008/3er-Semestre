#include "RSA.h"

ZZ RSA::get_publica()
{
    return this ->publica;
}

ZZ RSA::get_N()
{
    return this-> N;
}

RSA::RSA()
{
    ZZ P, Q, phi_N;
    P = ga(4,8,2,3);
    while(ProbPrime(P,10)!= 1)
        P = ga(4,8,2,3);
    Q = ga(3,8,3,5);
    while(ProbPrime(Q,10)!=1)
        Q = ga(3,8,3,5);
    this -> N = P * Q;
    phi_N = (P-1)*(Q-1);
    this -> publica = ga(6,8,4,9);
    while(publica > N || (euclides(publica,phi_N) != 1))
        this -> publica = ga(6,8,4,9);
    this -> privada = inverso(publica,phi_N);

    cout << publica << endl;
    cout << privada << endl;
    cout << N << endl;
}

RSA::RSA(ZZ pu, ZZ n)
{
    this -> publica = pu;
    this -> N = n;
}

ZZ* RSA::cifrar(string mensaje)
{
    ZZ respuesta[mensaje.length()];
    ZZ tam;
    for(int i = 0; i < mensaje.length(); i++){
        tam = alfabeto.find(mensaje[i]);
        respuesta[i] = potencia(tam,publica,N);
    }
    return respuesta;
}

string RSA::descifrar(ZZ* mensaje, int tama)
{
    string respuesta;
    for(int i = 0; i < tama; i++){
        respuesta += alfabeto[to_int(potencia(mensaje[i],privada,N))];
    }
    return respuesta;
}

