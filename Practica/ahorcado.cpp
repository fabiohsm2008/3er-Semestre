#include <iostream>
#include <string>

using namespace std;

char palabra_original[50] = "asd";
char palabra_mostrar[50];
int errores = 0;

char dibuj[9][7]={
    "_____ ",
    "|   | ",
    "|   | ",
    "|     ",
    "|     ",
    "|     ",
    "|     ",
    "|     ",
    "______",
    };

void dibu(int err){
    switch(err){
    case 1:
        dibuj[3][4] = '0';
        break;
    case 2:
        dibuj[4][4] = '|';
        break;
    case 3:
        dibuj[4][3] = '/';
        break;
    case 4:
        dibuj[4][5] = '\\';
        break;
    case 5:
        dibuj[5][3] = '/';
        break;
    case 6:
        dibuj[5][5] = '\\';
        break;
    }
}

void mostrar(){
    for(int i = 0; i < 9; i++){             ///Imprimir dibujo
        cout << dibuj[i] << endl;
    }
    cout << palabra_mostrar << endl;
}

void ingresar(char x){
    char *pal_mos = palabra_mostrar;
    char *pal_ori = palabra_original;
    bool fallo = 1;
    while(*pal_ori != '\0'){
        if(x == *pal_ori){
            *pal_mos = x;
            fallo = 0;
        }
        ++pal_mos;
        ++pal_ori;
    }
    if(fallo){
        errores++;
        dibu(errores);
    }
}

void iniciar(){
    char *pal_mos = palabra_mostrar;
    char *pal_ori = palabra_original;
    while(*pal_ori != '\0'){
        *pal_mos = '-';
        pal_mos++;
        pal_ori++;
    }
}

void ahorcado(){
    iniciar();
    mostrar();
    string ori = palabra_original;
    string mos = palabra_mostrar;
    while(errores < 6 && mos != ori){
        char x;
        cout << "Ingrese una letra: ";
        cin >> x;
        ingresar(x);
        mostrar();
        mos = palabra_mostrar;
    }
    if(errores < 6){
        cout << "Ganaste con " << errores << " errores" << endl;
    }
    else
        cout << "Perdiste, la palabra era: " << palabra_original << endl;

}

int main()
{
    ahorcado();
    return 0;
}
