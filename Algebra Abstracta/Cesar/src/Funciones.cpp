#include "Funciones.h"

int modulo(int a, int n)
{
    int residuo;
    if (a < 0){
        residuo = (n/a) - 1;
        residuo = (residuo * a) - n;
        return residuo;
    }
    residuo = n / a;
    residuo = n - (a*residuo);
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
