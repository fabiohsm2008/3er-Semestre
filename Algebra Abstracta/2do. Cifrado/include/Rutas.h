#ifndef RUTAS_H
#define RUTAS_H
#include <string>
#include <iostream>

using namespace std;


class Rutas
{
private:
    int clave;
public:
    Rutas();
    string cifrar();
    string descifrar();
};

#endif // RUTAS_H
