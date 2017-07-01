#include <iostream>
#include <NTL/ZZ.h>
#include "Protocolo.h"

using namespace std;
using namespace NTL;

int main()
{
    Protocolo Receptor(1024);
    string a;
    string b;
    cin >> a;
    cin >> b;
    Protocolo Emisor(stringTozz(a),stringTozz(b),1024);
    cout << Emisor.cifrar("Hola") << endl;
    string mensaje;
    cin >> mensaje;
    cout << Receptor.descifrar(mensaje);
    return 0;
}
