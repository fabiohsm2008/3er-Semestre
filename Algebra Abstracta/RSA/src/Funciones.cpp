#include "Funciones.h"

int modulo(int a, int n)
{
    int q = a / n;
    int residuo = a - q*n;
    if (residuo < 0){
        residuo = residuo + n;
    }
    return residuo;
}

int euclides(int a, int b)
{
    int r;
    r = modulo(a,b);
    while(r != 0){
        a = b;
        b = r;
        r = modulo(a,b);
    }
    return b;
}

int inverso(int a, int b)
{
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 -q*x2;
        x1 = x2;
        x2 = x;
    }
    return x1;
}

int potencia(int a, int b, int modu)
{
    int result = 1;
    while(b != 0){
        if(b&1){
            result = modulo((result * a),modu);
        }
        a = modulo((a * a),modu);
        b = b/2;
    }
    return result;
}
