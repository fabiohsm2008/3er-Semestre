#include <iostream>

using namespace std;

char dibuj[9][7]={
    "_____",
    "|   |",
    "|   |",
    "|",
    "|",
    "|",
    "|",
    "|",
    "_____",
    };

void imprimir(int *a){
    while (*a != -1){
        cout << *a << ",";
        ++a;
    }
    cout << *a << endl;
}

void mezclar(int *listaA, int *listaB, int *listaC){
    while((*listaA != -1) && (*listaB != -1)){
        if(*listaA < *listaB){
            *listaC = *listaA;
            listaA++;
            listaC++;
        }
        if(*listaB < *listaA){
            *listaC = *listaB;
            listaB++;
            listaC++;
        }
        if(*listaA == *listaB){
            *listaC = *listaA;
            listaA++;
            listaB++;
            listaC++;
        }
    }
    if(*listaA != -1){
        while(*listaA != -1){
            *listaC = *listaA;
            listaA++;
            listaC++;
        }
    }
    if(*listaB != -1){
        while(*listaB != -1){
            *listaC = *listaB;
            listaB++;
            listaC++;
        }
    }
    *listaC = -1;
}

int comparar(char *cadA, char *cadB){
    while((*cadA != '\0') || (*cadB != '\0')){
          if (*cadA < *cadB)
            return 1;
          if (*cadA > *cadB)
            return -1;
          cadA++;
          cadB++;
    }
    return 0;
}

///####################################################################

void impr_dib(){
    for(int i = 0; i < 9; i++){
        cout << dibuj[i] << endl;
    }
}

void ahorcado(char *palabra){
    impr_dib();
    int err = 0;
    char pal_temp;
    while(err < 6){
        cout << "Ingrese una letra: ";
        char letra;
        cin >> letra;
    }
}

int main()
{
    /*int a[] = {2,3,4,5,6,8,9,-1};
    int b[] = {1,3,4,6,7,8,10,-1};
    int c[50];
    mezclar(a,b,c);
    imprimir(c);
    ///#################################################
    char x[] = "MARION";
    char y[] = "MARIO";
    cout << comparar(x,y) << endl;*/
    ///#################################################
    char pal[] = "programacion";
    ///ahorcado(pal);

    return 0;
}
