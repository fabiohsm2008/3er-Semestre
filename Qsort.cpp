#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int *a, int *b){          ///Funcion swap para cambiar valores
	int temp = *a;
	*a = *b;
	*b = temp;
}

void generar(int *a, int tam){      ///Funcion que genera un arreglo de numeros aleatorios
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        a[i] = rand()%50;
    }
}

void imprimir(int *a, int *tam){    ///Funcion que imprime un arreglo recibiendo puntero inicio y fin
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

void quicksort(int* first, int* last){          ///Ordenamiento QuickSort
    int *pivote = first;                        ///Definimos un pivote que apunte a la posicion del medio + 1
    pivote = pivote + (last-first)/2;
    ///Bucles para mover los valores menores a la izquierda y mayores a la derecha(Referncias :: Luis Rendon Zuniga)

	for(int *i = first; i < pivote;){           ///Recorremos desde el inicio hasta mi pivote
		if(*i > *pivote){                       ///Si es mayor cambiamos los valores
			int *aux = i;                       ///Puntero aux para no modificar i
			for(;aux < pivote; aux++)           ///Mandamos el valor desde aux(i) hasta la posicion del pivote
				swap(aux,aux+1);
			pivote--;                           ///Le restamos 1 al pivote para no considerar el valor cambiado
		}
		else
		   i++;                                 ///Si no es mayor, solo aumentamos en 1 mi inicio
	}

	for(int *i = last; i>pivote;){              ///Recorremos desde mi pivote hasta el final
		if(*i < *pivote){                       ///Si es menor cambiamos los valores
			int *aux = i;                       ///Puntero aux para no modificar i
			for(;aux > pivote;aux--)            ///Mandamos el valor desde aux(i) hasta la posicion del pivote
				swap(aux,aux-1);
			pivote++;                           ///Le sumamos 1 al pivote para no considerar el valor ya cambiado
		}
		else
		   i--;                                 ///Si no es mayor, solo le restamos uno al final
    }
    ///Fin del algoritmo de movimiento de valores

    if (first < pivote)                         ///Condiciones del Quicksort
        quicksort(first, pivote-1);             ///Si mi inicio es menor que mi pivote; aplico Quicksort desde inicio hasta pivote-1
    if (last > pivote)
        quicksort(pivote+1, last);              ///Si mi fin es mayor que mi pivote; aplico Quicksort desde mi pivote +1 hasta fin

        ///Quicksort se basa en el divide y venceras; la recursividad finaliza una vez que solo un elemento entra al algoritmo
        ///Ya que si solo hay un elemento, entonces este ya esta ordenado.
}

int main()
{
    int tama;                               ///Definimos un tamanho
    cout << "Ingrese el largo: ";           ///Lo ingresamos por teclado
    cin >> tama;
    int a[tama];                            ///Creamos un arreglo de numeros aleatorios
    generar(a,tama);
    imprimir(a,a+tama);                     ///Imprimo el arreglo aleatorio
    quicksort(a,a+tama);                    ///Ordeno usando Quicksort
    imprimir(a,a+tama);                     ///Imprimo el arreglo ya ordenado
}
