#include <iostream>

using namespace std;

int modulo(int a, int n)
{
    int q = a / n;
    int residuo = a - q*n;
    if (residuo < 0){
        residuo = residuo + n;
    }
    return residuo;
}

int generador(int a, int b, int seed, int n){
    int x = seed;
    do{
        x = modulo((a*x)+b,n);
        cout << x << endl;
    }
    while(x != seed);
}

int euclides(int a, int b){
    if (b == 0)
        return a;
    return euclides(b, modulo(a,b));
}

int main()
{
    ///generador(3,7,0,11);
    cout << euclides(5,3);
    return 0;
}
