#include <iostream>
#include "RSA.h"

using namespace std;

int main()
{

    /*srand(time(NULL));

    string texto_plano = "Hola";
    RSA Receptor;
    ZZ clave_publica = Receptor.get_clave_publica();
    ZZ n = Receptor.get_N();
    RSA Emisor(clave_publica, n);
    ///RSA Emisor(to_ZZ(175), to_ZZ(30301));
    vector <ZZ> texto = Emisor.cifrar(texto_plano);
    for(int i = 0; i < texto.size(); i++){
        cout << texto[i] << ",";
    }
    int temp[] = {16208,2744,1331,0};
    vector <ZZ> texto;
    for(int i = 0; i < sizeof(temp)/sizeof(temp[0]); i++){
        texto.push_back(to_ZZ(temp[i]));
    }
    cout << endl;

    texto_plano = Receptor.descifrar(texto);
    cout << texto_plano << endl;*/

    cout << potencia_i(36,11,91);

}
