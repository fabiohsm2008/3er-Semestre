#include <iostream>
#include <string>
#include "Rutas.h"

using namespace std;

int main()
{
    cout << "Ingrese el mensaje: ";
    string mensaje;
    cin >> mensaje;

    Rutas r;
    mensaje = r.cifrar(mensaje);
    cout << mensaje << endl;
    mensaje = r.descifrar(mensaje);
    cout << mensaje << endl;

    return 0;
}
