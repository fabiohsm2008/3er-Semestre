#ifndef CESAR_H
#define CESAR_H
#include <iostream>
#include <string>

using namespace std;

class Cesar
{
private:
    int clave;
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
public:
    Cesar();
    string codificar(string cadena);
    string decodificar(string cadena);
    virtual ~Cesar();
};

#endif // CESAR_H
