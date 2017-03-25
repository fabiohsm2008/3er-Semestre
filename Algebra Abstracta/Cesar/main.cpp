#include <iostream>
#include <string.h>
#include "Funciones.h"
#include "Cesar.h"

using namespace std;

int main()
{
    cout << modulo(-225,111) << endl;
    cout << euclides(11,225) << endl;

    string cadena;
    cout << "Ingrese una cadena: ";
    cin >> cadena;

    Cesar a;
    cadena = a.codificar(cadena);
    cout << cadena << endl;
    cadena = a.decodificar(cadena);
    cout << cadena << endl;

    return 0;
}
