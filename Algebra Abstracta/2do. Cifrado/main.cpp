#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

void cifrar(string cadena, int clave)
{
    map <int,string> matriz;
    int i, j;
    int comprobacion = 1;
    int recorrido = 0;
    for(i = 0; i <= cadena.size(); i++){
        matriz[recorrido] += cadena[i];
        if (recorrido == clave - 1){
            comprobacion = comprobacion*(-1);
            recorrido = recorrido + comprobacion;
        }
        else if (recorrido == -1){
                cout << comprobacion << endl;
            comprobacion = comprobacion*(-1);
            recorrido += comprobacion;
        }
        else if (recorrido < clave - 1){
            recorrido += comprobacion;
            //matriz[recorrido] += cadena[i];
        }
    }
    for(j = 0; j <= clave; j++){
        cout << matriz[j] << endl;
    }

}

int main()
{
    string cadena;
    cout << "Ingrese la palabra: ";
    cin >> cadena;

    int clave;
    cout << "Ingrese la clave: ";
    cin >> clave;

    cifrar(cadena,clave);
    return 0;
}
