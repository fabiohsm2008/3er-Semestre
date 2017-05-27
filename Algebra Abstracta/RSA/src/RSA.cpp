#include "RSA.h"

RSA::RSA(int bits){
    generar_claves(bits);
}

RSA::RSA(ZZ publica, ZZ n){
    this -> e = publica;
    this -> N = n;
}

string RSA::cifrar(string mensaje){
    string digitos;

    for(int i = 0; i < mensaje.size(); i++){
        int pos = alfabeto.find(mensaje[i]);
        if(pos < 10)
            digitos += "0";
        digitos += zzToString(to_ZZ(pos));
    }
    ZZ temp = to_ZZ(digitos.size());
    ZZ N_1 = to_ZZ(zzToString(N).size()-1);
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
        ZZ temp_2 = potenciaMod(stringTozz(tempi),e,N);
        ZZ cont_num = to_ZZ(zzToString(temp_2).size());
        while(cont_num < zzToString(N).size()){
            dig_2 += "0";
            ++cont_num;
        }
        dig_2 += zzToString(temp_2);
    }
    return dig_2;
}

string RSA::descifrar(string mensaje){
    string resultado;
    int num = (zzToString(N).size());
    for(int i = 0; i < mensaje.size();){
        int a = 0;
        string temp;
        while(a < num){
            a++;
            temp += mensaje[i];
            ++i;
        }
        ZZ valor = chino_RSA(stringTozz(temp));
        int x = zzToString(valor).size();
        while(x < zzToString(N).size()-1){
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

ZZ RSA::chino_RSA(ZZ num){
    ZZ d1 = modulo(d,p-1);
    ZZ d2 = modulo(d,q-1);
    ZZ D1 = modulo(num,p);
    D1 = potencia(D1,d1,p);
    ZZ D2 = modulo(num,q);
    D2 = potencia(D2,d2,q);
    ZZ P = p*q;
    ZZ P1 = P/p;
    ZZ P2 = P/q;
    ZZ Q1 = inversa(P1,p);
    ZZ Q2 = inversa(P2,q);
    ZZ rpta = modulo(D1 * P1 * Q1,P);
    rpta += modulo(D2 * P2 * Q2,P);
    rpta = modulo(rpta,P);
    return rpta;
}

void RSA::generar_claves(int bits)
{
    ZZ P = ga(11,bits,3,3);
    ZZ Q = ga(11,bits,2,4);
    while(ProbPrime(P,10)!=1)
    {
        P = ga(11,bits,3,3);
    }
    while(ProbPrime(Q,10)!=1)
    {
        Q = ga(11,bits,2,4);
    }
    this -> p = P;
    this -> q = Q;
    N = P * Q;
    ZZ phi_N;
    phi_N = (P - 1) * (Q - 1);
    ZZ e;
    e = ga(11,bits,2,2);
    while(e > phi_N || (euclides(e, phi_N) != 1))
    {
        e = ga(11,bits,2,2);
    }
    cout <<"Clave publica: " << e << endl;
    this -> e = e;
    this -> d = inversa(e, phi_N);
    cout << "Clave privada: " << d << endl;
    cout <<"N: " << N << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
}

ZZ RSA::get_d(){
    return d;
}

ZZ RSA::get_e(){
    return e;
}

ZZ RSA::get_N(){
    return N;
}

ZZ RSA::get_p(){
    return p;
}

ZZ RSA::get_q(){
    return q;
}

void RSA::set_p(ZZ a){
    this -> p = a;
}

void RSA::set_q(ZZ b){
    this -> q = b;
}

void RSA::set_N(ZZ c){
    this -> N = c;
}

void RSA::set_d(ZZ x){
    this -> d = x;
}

void RSA::set_e(ZZ y){
    this -> e = y;
}
