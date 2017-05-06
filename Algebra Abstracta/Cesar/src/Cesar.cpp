#include "Cesar.h"

Cesar::Cesar()
{
    clave = ga(3,8,2,3);
}

string Cesar::codificar(string cadena)
{
    int i;
    clave = modulo(clave,to_ZZ(alfabeto.size()));
    for(i = 0; i < cadena.size(); i++){
        if (alfabeto.find(cadena[i])+clave >= alfabeto.size())
            cadena[i] = alfabeto[to_int(modulo(to_ZZ(alfabeto.find(cadena[i]))+clave , to_ZZ(alfabeto.size())))];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i]) + to_int(clave)];
    }
    return cadena;
}

string Cesar::decodificar(string cadena)
{
    int i;
    clave = modulo(clave,to_ZZ(alfabeto.size()));
    for (i = 0; i <= cadena.size(); i++){
        if(clave - alfabeto.find(cadena[i]) > 0)
            cadena[i] = alfabeto[to_int(modulo(to_ZZ(alfabeto.find(cadena[i])) - clave , to_ZZ(alfabeto.size())))];
        else
            cadena[i] = alfabeto[alfabeto.find(cadena[i]) - to_int(clave)];
    }
    return cadena;
}

