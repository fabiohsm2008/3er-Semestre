#include "Cesar.h"
#include "Funciones.h"
#include <string.h>

Cesar::Cesar()
{
    cout << "Ingrese una clave: ";
    cin >> clave;
}

string Cesar::codificar(string cadena)
{
    int i;
    for(i = 0; i <= cadena.size(); i++){
        if (alfabeto.find(cadena[i])+clave >= alfabeto.size())
            cadena[i] = alfabeto[modulo(alfabeto.find(cadena[i])+clave , alfabeto.size())];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i])+clave];
    }
    return cadena;
}

string Cesar::decodificar(string cadena)
{
    int i;
    for (i = 0; i <= cadena.size(); i++){
        if(clave - alfabeto.find(cadena[i]) > 0)
            cadena[i] = alfabeto[modulo(alfabeto.find(cadena[i]) - clave , alfabeto.size())];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i])-clave];
    }
    return cadena;
}

Cesar::~Cesar()
{
    //dtor
}
