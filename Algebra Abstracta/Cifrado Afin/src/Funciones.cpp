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
