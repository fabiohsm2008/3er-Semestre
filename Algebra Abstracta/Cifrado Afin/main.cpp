#include <iostream>
#include <string>
#include "Funciones.h"
#include "Cifrado.h"

using namespace std;

int main()
{
    string cadena;
    cout << "Ingrese su frase:";
    cin >> cadena;

    Cifrado a;
    cadena = a.codificar(cadena);
    cout << "Mensaje cifrado = " << cadena << endl;
    cadena = a.decodificar(cadena);
    cout << "Mensaje descifrado = " << cadena << endl;

    return 0;
}
