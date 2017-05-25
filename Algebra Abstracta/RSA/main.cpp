#include <iostream>
#include "RSA.h"

using namespace std;

int main()
{
    srand(time(NULL));
    RSA receptor(18);
    RSA emisor(receptor.get_e(),receptor.get_N());
    /*RSA emisor(to_ZZ(3), to_ZZ(1003));
    receptor.set_p(to_ZZ(17));
    receptor.set_q(to_ZZ(59));
    receptor.set_N(to_ZZ(1003));
    receptor.set_d(to_ZZ(619));*/
    string mensaje = emisor.cifrar("mientras");
    cout << mensaje << endl;
    cout << receptor.descifrar(mensaje) << endl;
    return 0;
}
