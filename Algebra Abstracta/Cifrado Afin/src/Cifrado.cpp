#include "Cifrado.h"

Cifrado::Cifrado()
{
    srand(time(NULL));
    clave_a = rand();
    while(euclides(clave_a,alfabeto.length()) != 1){
        clave_a = rand();
    }
    clave_b = rand()%alfabeto.length();
    privada = inverso(clave_a,alfabeto.length());
    cout << "Su clave publica es: " << clave_a << endl;
    cout << "Su clave privada es: " << privada << endl;
    cout << "Su segunda clave es: " << clave_b << endl;
}

string Cifrado::codificar(string cadena)
{
    int i;
    for(i = 0; i <= cadena.length(); i++){
        cadena[i] = alfabeto[modulo((clave_a*alfabeto.find(cadena[i])+clave_b),alfabeto.length())];
    }
    return cadena;
}

string Cifrado::decodificar(string cadena)
{
    int i;
    for(i = 0; i <= cadena.length(); i++){
        cadena[i] = alfabeto[modulo((privada*(alfabeto.find(cadena[i])-clave_b)),alfabeto.length())];
    }
    return cadena;
}
