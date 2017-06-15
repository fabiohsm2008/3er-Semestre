#include <iostream>
#include <fstream>
#include "Gamal.h"

using namespace std;

int main()
{
    srand(time(NULL));
    cout << "Gamal Cifrado y Descifrado" << endl;
    cout << "1: Imprimir claves" << endl;
    cout << "2: Cifrar un Texto" << endl;
    cout << "3: Descifrar un Texto" << endl;
    cout << "0: Salir" << endl;
    int x;
    cin >> x;
    Gamal Receptor(1024);
    while(x != 0){
        switch (x){
        case 1:{
            Receptor.impr_claves();}
            break;
        case 2:{
            string a, b, c;
            cout << "Ingrese e_1: ";
            cin >> a;
            cout << "Ingrese e_2: ";
            cin >> b;
            cout << "Ingrese p: ";
            cin >> c;
            Gamal emisor(stringTozz(a), stringTozz(b), stringTozz(c));
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
            string mess, desci, c;
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
