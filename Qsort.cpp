#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generar(int *a, int tam){
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        a[i] = rand()%50;
    }
}

void imprimir(int *a, int tam){
    cout << "[";
    for(int i = 0; i < tam; i++){
        if(i != tam-1){
            cout << a[i] << ",";
        }
        else{
            cout << a[i];
        }
    }
    cout << "]" << endl;
}

void quicksort(int *a, int *b){
    int *p = a;
    p += (b-a)/2;
    cout << *p << endl;
}

int main()
{
    int tama;
    cout << "Ingrese el largo: ";
    cin >> tama;
    int a[tama];
    generar(a,tama);
    imprimir(a,tama);

    quicksort(a,a+tama);
    imprimir(a,tama);

    return 0;
}
