#include <iostream>
#include "RSA.h"

using namespace std;

int main(){

    srand(time(NULL));
    RSA Receptor;
    RSA Emisor(Receptor.get_publica(),Receptor.get_N());
    string mensaje = "Mango";
    ZZ *temp;
    cout << Receptor.descifrar(temp,mensaje.length());

    return 0;
}
