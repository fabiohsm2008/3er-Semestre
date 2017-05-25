#include <iostream>
#include <vector>
#include <math.h>

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

vector <int> mcd(int a, int b){
    if (b==0){
        ++b;
    }
    int u = 1, g = a, x = 0, y = b;
    while(y != 0){
        int q = g/y;
        int t = modulo(g,y);
        int s = u - (q*x);
        u = x, g = y;
        x = s, y = t;
    }
    int v = (g - (a*u))/b;
    u = modulo(u,b);
    vector<int> rpta;
    rpta.push_back(g);
    rpta.push_back(u);
    rpta.push_back(v);
    return rpta;
}

int xx(int a, int b){
    if (a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    else if((a&1==0) && (b&1==0)){
        return 2*xx(a/2,b/2);
    }
    else if((a&1==0) && (b&1)){
        return 2*xx(a/2,b);
    }
    else if((a&1) && (b&1 == 0)){
        return 2*xx(a,b/2);
    }
    else
        return xx(fabs(a+b)/2,b);
}

int main()
{
    ///generador(3,7,0,11);
    ///cout << euclides(3,5);
    ///vector<int> prueba = mcd(228,1258);
    ///cout << prueba[0] << " " << prueba[1] << " " << prueba[2] << endl;
    cout << xx(1764,868);

    return 0;
}
