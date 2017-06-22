#include <iostream>
#include <fstream>
#include "Firma.h"

using namespace std;

int main()
{
    srand(time(NULL));
    cout << "Firma Cifrado y Descifrado" << endl;
    cout << "1: Imprimir claves" << endl;
    cout << "2: Cifrar un Texto" << endl;
    cout << "3: Descifrar un Texto" << endl;
    cout << "0: Salir" << endl;
    int x;
    cin >> x;
    int bits = 1024;
    Firma Receptor(bits);
    while(x != 0){
        switch (x){
        case 1:{
            Receptor.impr_claves();}
            break;
        case 2:{
            string a, b;
            cout << "Ingrese clave publica: ";
            cin >> a;
            cout << "Ingrese N: ";
            cin >> b;
            Firma emisor(stringTozz(a), stringTozz(b),bits);
            ifstream ficheroEntrada;
            string mensaje;
            ficheroEntrada.open ("temp.txt");
            getline(ficheroEntrada,mensaje);
            ficheroEntrada.close();
            ofstream ficheroSalida;
            ficheroSalida.open("mensaje.txt");
            ficheroSalida << emisor.cifrar(mensaje);
            ficheroSalida.close();}
            break;
        case 3:{
            string mess, desci;
            cout << "Ingrese el mensaje cifrado: ";
            cin >> mess;
            desci = Receptor.descifrar(mess);
            cout << desci << endl;
            ofstream salida;
            salida.open("ofset.txt");
            salida << desci;
            salida.close();}
            break;
        }
        cin >> x;
    }

    return 0;
}

