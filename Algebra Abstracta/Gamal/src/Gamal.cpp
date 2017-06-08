#include "Gamal.h"

Gamal::Gamal(int bits)
{
    generar_claves(bits);
}

Gamal::Gamal(ZZ e1, ZZ e2, ZZ publica){
    this -> e_1 = e1;
    this -> e_2 = e2;
    this -> p = publica;
}

string Gamal::cifrar(string mensaje){
    ZZ r = modulo(ga(11,1024,4,6),p-3) + 1;
    ZZ c_1 = potenciaMod(this -> e_1,r,this -> p);
    ZZ Km = potenciaMod(this -> e_2,r,this -> p);
    string digitos;

    for(int i = 0; i < mensaje.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(mensaje[i]));
        if(pos < 10){
            digitos += "0";
        }
        digitos += zzToString(pos);
    }
    ZZ temp = to_ZZ(digitos.size());
    ZZ N_1 = to_ZZ(zzToString(this -> p).size()-1);
    while(modulo(temp,N_1) != 0){
        int pos = alfabeto.find("w");
        digitos += zzToString(to_ZZ(pos));
        temp = to_ZZ(digitos.size());
    }
    string dig_2;
    for(int j = 0; j < digitos.size();){
        int temp = 0;
        string tempi;
        while(temp < to_int(N_1)){
            tempi += digitos[j];
            ++temp;
            ++j;
        }
        ZZ temp_2 = modulo(stringTozz(tempi)*Km,this -> p);
        ZZ cont_num = to_ZZ(zzToString(temp_2).size());
        while(cont_num < zzToString(p).size()){
            dig_2 += "0";
            ++cont_num;
        }
        dig_2 += zzToString(temp_2);
    }
    ofstream guardar_C;
    guardar_C.open("guardar_C.txt");
    guardar_C << zzToString(c_1);
    guardar_C.close();
    return dig_2;
}

string Gamal::descifrar(string mensaje, ZZ C){
    ZZ Km = potenciaMod(C,this -> d,this -> p);
    string resultado;
    int num = (zzToString(p).size());
    for(int i = 0; i < mensaje.size();){
        int a = 0;
        string temp;
        while(a < num){
            a++;
            temp += mensaje[i];
            ++i;
        }
        ZZ valor = modulo(stringTozz(temp)*inversa(Km,p),p);
        int x = zzToString(valor).size();
        while(x < zzToString(p).size()-1){
            resultado += "0";
            ++x;
        }
        resultado += zzToString(valor);
    }
    string dig = zzToString(to_ZZ(alfabeto.size()-1));
    string rpta;
    for(int j = 0; j < resultado.size();){
        int s = 0;
        string tempi;
        while(s < dig.size()){
            tempi += resultado[j];
            ++s;
            ++j;
        }
        rpta += alfabeto[to_int(stringTozz(tempi))];
    }
    while(rpta[rpta.size()-1] == 'w'){
        rpta.erase(rpta.size()-1);
    }
    return rpta;
}

void Gamal::generar_claves(int bits){
    ZZ P = ga(11,bits,3,3);
    while(ProbPrime(P,10)!=1)
    {
        P = ga(11,bits,3,3);
    }
    this -> p = P;
    this -> d = modulo(ga(11,bits,4,6),P-3) + 1;
    this -> e_1 = raiz_primitiva(P);
    this -> e_2 = potenciaMod(this -> e_1,this -> d,P);
}

void Gamal::impr_claves(){
    cout << "e_1: " << this -> e_1 << endl;
    cout << "e_2: " << this -> e_2 << endl;
    cout << "p: " << this -> p << endl;
    ofstream guardarClaves;
    guardarClaves.open("Claves.txt");
    guardarClaves << "e_1: " << e_1 << endl;
    guardarClaves << "e_2: " << e_2 << endl;
    guardarClaves << "p: " << p << endl;
    guardarClaves.close();
}

