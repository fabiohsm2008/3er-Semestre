#include <iostream>
#include <vector>

using namespace std;

int tam(int num){           //Obtener el tamanio de una numero en bits para el bucle
    int tam;
    while(num > 0){
        ++tam;
        num = num>>1;
    }
    return tam;
}

int complemento(int x){     //Funcion para hallar el complemento a 2 de un numero
    x = ~x+1;
    return x;
}

int multi(int a, int b){    //Futura funcion que retornara la multiplicacion ya hecha
    int A, Q, n;
    A = 0;
    Q = 0;
    n = tam(b);
    while (n != 0){
        n++;
        if((b&1)==1 && (b&2)==0){

        }
    }
}

int main()
{
    int a = 6;
    cout << a << endl;
    /*a = complemento(a);
    cout << a << endl;
    cout << tam(a) << endl;*/
    a = a&2;
    if (a > 0){
        a = 1;
    }
    cout << a << endl;
}
