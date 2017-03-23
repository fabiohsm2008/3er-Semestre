#include <iostream>
#include <string.h>
#include "Funciones.h"

using namespace std;

void codifica(int n, string &cadena)
{
    for (int i = 0; i < cadena.size(); i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            if (cadena[i] + n > 'z') {
                cadena[i] = 'a' - 'z' + cadena[i] + n - 1;
            } else if (cadena[i] + n < 'a') {
                cadena[i] = 'z' - 'a' + cadena[i] + n + 1;
            } else {
                cadena[i] += n;
            }
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            if (cadena[i] + n > 'Z') {
                cadena[i] = 'A' - 'Z' + cadena[i] + n - 1;
            } else if (cadena[i] + n < 'A') {
                cadena[i] = 'Z' - 'A' + cadena[i] + n + 1;
            } else {
                cadena[i] += n;
            }
        }
    }
}

//Funcion descodificar
void decodifica(int n, string &cadena)
{
    codifica(-n, cadena);
}

int main()
{
    //cout << modulo(-15,26) << endl;
    //cout << euclides(7,10) << endl;
    string c;
    cin >> c;
    codifica(3,c);
    cout << c << endl;
    decodifica(3,c);
    cout << c << endl;

    return 0;
}
