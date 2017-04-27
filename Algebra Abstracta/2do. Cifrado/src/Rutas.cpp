#include "Rutas.h"

Rutas::Rutas()
{
    cout << "Ingrese la clave: ";
    cin >> clave;
}

string Rutas::cifrar(string mensaje)
{
    int avanza;
    string encriptado;

    for(int i=0;i<clave;i++)
    {
        encriptado += palabra[i];
        avanza = ((2*(clave-i))-2);
        while(avanza+i < palabra.size())
        {
            if(i== 0){
                encriptado += palabra[avanza];
                avanza += ((2*(clave))-2);
            }else if(i == clave-1)
            {
                avanza += (i*2);
                if(avanza+i > palabra.size())
                    break;
                encriptado += palabra[avanza+i];
            }else if(avanza+i != palabra.size()-1){
                encriptado += palabra[avanza+i];
                if(avanza+(i*2)+i < palabra.size()){
                    avanza += i*2;
                    encriptado += palabra[avanza+i];
                }
                avanza += ((2*(clave-i))-2);
            }
            else{
                avanza += ((2*(clave-i))-2);
            }
        }
    }
    return encriptado;
}

string Rutas::descifrar(string mensaje)
{
    return mensaje;
}
