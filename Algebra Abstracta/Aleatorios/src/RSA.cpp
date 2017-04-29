#include "RSA.h"

RSA::RSA(ZZ e, ZZ n) //EMISOR
{
    this -> clave_publica = e;
    this -> N = n;
}
RSA::RSA() //RECEPTOR
{
    generar_claves();
}
ZZ RSA::get_N()
{
    return N;
}
ZZ RSA::get_clave_publica()
{
    return clave_publica;
}
vector <ZZ> RSA::cifrar(string mensaje)
{
    vector <ZZ> mensaje_cifrado;
    int posicion;
    for(int i = 0; i < mensaje.length(); i++)
    {
        posicion = alfabeto.find(mensaje[i]);
        mensaje_cifrado.push_back(potencia(posicion, clave_publica, N));
    }
    return mensaje_cifrado;
}
string RSA::descifrar(vector <ZZ> mensaje)
{
    string mensaje_descifrado;
    int letra_cifrada;
    for(int i = 0; i < mensaje.size(); i++)
    {
        letra_cifrada = to_int(potencia(to_int(mensaje[i]), clave_privada, N));
        mensaje_descifrado += alfabeto[letra_cifrada];
    }
    return mensaje_descifrado;
}

void RSA::generar_claves()
{
    ZZ p = ga(5,8,3,3);
    ZZ q = ga(5,8,2,4);
    while(ProbPrime(p,10)!=1)
    {
        p = ga(5,8,3,3);
    }
    while(ProbPrime(q,10)!=1)
    {
        q = ga(5,8,2,4);
    }
    N = p * q;
    ZZ phi_N;
    phi_N = (p - 1) * (q - 1);
    ZZ e;
    e = ga(6,8,5,2);
    while(e > phi_N || (euclides(e, phi_N) != 1))
    {
        e = ga(6,8,5,2);
    }
    cout <<"Clave publica: " << e << endl;
    this -> clave_publica = e;
    this -> clave_privada = inversa(clave_publica, phi_N);
    cout << "Clave privada: " << clave_privada << endl;
    cout <<"N: " << N << endl;
}

void RSA::set_publica(ZZ a)
{
    this -> clave_publica = a;
}

void RSA::set_privada(ZZ b)
{
    this ->clave_privada = b;
}

void RSA::set_N(ZZ c)
{
    this -> N = c;
}
