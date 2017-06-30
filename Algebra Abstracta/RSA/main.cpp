#include <iostream>
#include <fstream>
#include "RSA.h"

using namespace std;

int rdtsc() ///rand de ciclos utilizados por procesador desde el inicio
{
    __asm__ __volatile__("rdtsc");
}

int main()
{
    srand(rdtsc());
    cout << "RSA Cifrado y Descifrado" << endl;
    cout << "1: Imprimir claves" << endl;
    cout << "2: Cifrar un Texto" << endl;
    cout << "3: Descifrar un Texto" << endl;
    cout << "0: Salir" << endl;
    int x;
    cin >> x;
    RSA Receptor(1024);
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
            RSA emisor(stringTozz(a), stringTozz(b));
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
    ZZ e = des(1024);
    cout << e << endl;
    if(ProbPrime(e,10))
        cout << "ES PRIMO" << endl;
    return 0;
}
