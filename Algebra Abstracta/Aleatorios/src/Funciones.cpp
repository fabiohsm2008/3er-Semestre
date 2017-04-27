#include "Funciones.h"

ZZ modulo(ZZ a, ZZ n)
{
    ZZ q = a / n;
    ZZ residuo = a - q*n;
    if (residuo < 0){
        residuo = residuo + n;
    }
    return residuo;
}

ZZ euclides(ZZ a, ZZ b)
{
    ZZ r;
    r = modulo(a,b);
    while(r != 0){
        a = b;
        b = r;
        r = modulo(a,b);
    }
    return b;
}

ZZ inverso(ZZ a, ZZ b)
{
    ZZ r1 = a, r2 = b;
    ZZ x1 , x2;
    x1 = 0;
    x2 = 1;

    ZZ q , r , x ;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 -q*x2;
        x1 = x2;
        x2 = x;
    }
    if(x1 < 0)
        x1 = a - x1;
    return x1;
}

ZZ potencia(ZZ a, ZZ b, ZZ modu)
{
    ZZ result, temp, lol;
    result = 1;
    temp = 2;
    lol = to_ZZ(a);
    while(b > 0){
        if(modulo(b,temp) == 1){
            result = modulo((result * a),modu);
        }
        lol = modulo((lol * lol),modu);
        b = b/2;
    }
    return result;
}
///Funciones para aleatorios ##############################################################################
ZZ convertir_decimal(vector <bool> a, int bits_num)
{
    ZZ num;
    num = 0;
    int e = 0;
    for(int i = bits_num - 1; i >= 0; i--)
    {
        if(a[i]==1)
        {
            num += power2_ZZ(e);
        }
        else
            num += to_ZZ(0);
        e += 1;
    }
    return num;
}
void rotar_derecha(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = elementos + indice - 1; i > indice; i--)
        {
            int temp = vec[i];
            vec[i] = vec[i - 1];
            vec[i - 1] = temp;
        }
    }
}
void rotar_izquierda(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = indice; i < indice + elementos - 1; i++)
        {
            int temp = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = temp;
        }
    }
}
ZZ ga(int bits_seed, int bits_num, int particiones, int vueltas)
{

    vector <bool> a;
    for(int i = 0; i < bits_num; i++)
    {
        a.push_back(0);
    }
    for(int i = 0; i < bits_seed; i++)
    {
        a[i] = rand()%2;
    }
    int s = 0;
    for(int i = bits_seed; i < bits_num; i++)
    {
        a[i] = a[s] ^ a[s+1];
        s++;
    }
    int elementos_pedazo = bits_num/particiones;
    int residuo_elementos = bits_num%particiones;
    if(residuo_elementos!=0)
    {
        elementos_pedazo += 1;
    }
    int indice = 0;
    while(indice < bits_num)
    {
        if((indice + elementos_pedazo) > bits_num)
        {
            if(particiones%2!=0)
            {
                rotar_izquierda(a, indice, residuo_elementos, vueltas);
                indice += elementos_pedazo;
            }
            else
                rotar_derecha(a, indice, residuo_elementos, vueltas);
                indice += elementos_pedazo;
        }
        rotar_izquierda(a, indice, elementos_pedazo, vueltas);
        indice += elementos_pedazo;
        rotar_derecha(a, indice, elementos_pedazo, vueltas);
        indice += elementos_pedazo;
    }
    ZZ num;
    num = convertir_decimal(a, bits_num);
    return num;
}
