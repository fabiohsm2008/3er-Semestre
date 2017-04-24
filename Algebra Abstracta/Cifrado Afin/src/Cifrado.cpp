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

Cifrado::Cifrado(int a, int b)
{
    this -> clave_a = a;
    this -> clave_b = b;
    privada = inverso(clave_a,alfabeto.length());
}

string Cifrado::codificar(string cadena)
{
    int i;
    for(i = 0; i <= cadena.length(); i++){
        int temp = modulo(clave_a,alfabeto.length());
        temp = temp * alfabeto.find(cadena[i]);
        temp = modulo(temp,alfabeto.length()) + modulo(clave_b,alfabeto.length());
        temp = modulo(temp,alfabeto.length());
        cadena[i] = alfabeto[temp];
    }
    return cadena;
}

string Cifrado::decodificar(string cadena)
{
    int i;
    for(i = 0; i <= cadena.length(); i++){
        int temp = modulo(clave_b,alfabeto.length());
        temp = alfabeto.find(cadena[i]) - temp;
        temp = modulo(privada,alfabeto.length()) * temp;
        temp = modulo(temp,alfabeto.length());
        cadena[i] = alfabeto[temp];
    }
    return cadena;
}
