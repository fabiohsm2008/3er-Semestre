#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void generar(int *a, int tam){
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        a[i] = rand()%50;
    }
}

void imprimir(int *a, int *tam){
    cout << "[";
    for(; a < tam; a++){
        if(a != tam-1){
            cout << *a << ",";
        }
        else{
            cout << *a;
        }
    }
    cout << "]" << endl;
}

void quicksort(int* first, int* last){
    int *pivote = first;
    pivote = pivote + (last-first)/2;
    cout << *pivote << endl;
	for(int *i = first; i < pivote;){
		if(*i > *pivote){
			int *aux = i;
			for(;aux < pivote; aux++)
				swap(aux,aux+1);
			pivote--;
		}
		else
		   i++;
	}
	for(int *i = last; i>pivote;){
		if(*i < *pivote){
			int *aux = i;
			for(;aux > pivote;aux--)
				swap(aux,aux-1);
			pivote++;
		}
		else
		   i--;
    }

    if (first < pivote)
        quicksort(first, pivote-1);
    if (last > pivote)
        quicksort(pivote+1, last);
}

int main()
{
    int tama;
    cout << "Ingrese el largo: ";
    cin >> tama;
    int a[tama];
    generar(a,tama);
    imprimir(a,a+tama);
    quicksort(a,a+tama);
    imprimir(a,a+tama);

    return 0;
}
