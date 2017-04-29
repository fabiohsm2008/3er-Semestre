#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Funciones.h"
#include "Cesar.h"

using namespace std;

int main()
{
    srand(time(NULL));
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
