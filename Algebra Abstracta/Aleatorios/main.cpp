#include <iostream>
#include "RSA.h"

using namespace std;

int main()
{

    srand(time(NULL));

    string texto_plano = "Mango";
    RSA Receptor;
    ZZ clave_publica = Receptor.get_clave_publica();
    ZZ n = Receptor.get_N();
    ///RSA Emisor(clave_publica, n);
    /*RSA Emisor(to_ZZ(215), to_ZZ(34717));
    vector <ZZ> texto = Emisor.cifrar(texto_plano);
    for(int i = 0; i < texto.size(); i++){
        cout << texto[i] << ",";
    }*/

    int temp[] = {23635,0,15869,13874,22361};
    vector <ZZ> texto;
    for(int i = 0; i < sizeof(temp)/sizeof(temp[0]); i++){
        texto.push_back(to_ZZ(temp[i]));
    }
    Receptor.set_privada(to_ZZ(13415));
    Receptor.set_N(to_ZZ(34717));

    cout << endl;

    texto_plano = Receptor.descifrar(texto);
    cout << texto_plano << endl;
}
