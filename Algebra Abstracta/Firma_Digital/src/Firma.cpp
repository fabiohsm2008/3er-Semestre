#include "Firma.h"
#include <fstream>

using namespace std;

Firma::Firma(int bits){
    generar_claves(bits);
}

Firma::Firma(ZZ publica, ZZ n, int bits){
    this -> e_publica = publica;
    this -> N_publica = n;
    generar_claves(bits);
}

string Firma::cifrar(string mensaje){
    string digitos;

    for(int i = 0; i < mensaje.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(mensaje[i]));
        string nume = zzToString(to_ZZ(alfabeto.size()-1));
        int num_pos = zzToString(pos).size();
        if(num_pos < nume.size()){
            digitos += "0";
            num_pos++;
        }
        digitos += zzToString(pos);
    }
    ZZ temp = to_ZZ(digitos.size());
    ZZ N_1 = to_ZZ(zzToString(N_publica).size()-1);
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
        ZZ temp_2 = potenciaMod(stringTozz(tempi),e_publica,N_publica);
        ZZ cont_num = to_ZZ(zzToString(temp_2).size());
        while(cont_num < zzToString(N_publica).size()){
            dig_2 += "0";
            ++cont_num;
        }
        dig_2 += zzToString(temp_2);
    }
    return dig_2 + firmar();
}

string Firma::firmar(){
    string digitos;

    for(int i = 0; i < firma.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(firma[i]));
        string nume = zzToString(to_ZZ(alfabeto.size()-1));
        int num_pos = zzToString(pos).size();
        if(num_pos < nume.size()){
            digitos += "0";
            num_pos++;
        }
        digitos += zzToString(pos);
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
        while(cont_num < zzToString(N_publica).size()){
            dig_2 += "0";
            ++cont_num;
        }
        dig_2 += zzToString(temp_2);
    }
    /**###########################################################################**/
    ZZ Npubl = to_ZZ(zzToString(N_publica).size() - 1);
    ZZ temp_2 = to_ZZ(dig_2.size());
    string mensaje;
    int num = (zzToString(N_publica).size());
    for(int k = 0; k < dig_2.size();){
        int a = 0;
        string temporal;
        while(a < num){
            a++;
            temporal += dig_2[k];
            ++k;
        }
        ZZ valor = potenciaMod(stringTozz(temporal),e_publica,N_publica);
        int x = zzToString(valor).size();
        while(x < zzToString(N_publica).size()){
            mensaje += "0";
            ++x;
        }
        mensaje += zzToString(valor);
    }
    return mensaje;
}

string Firma::descifrar(string mensaje){
    string resultado;
    string hola = mensaje.substr((mensaje.size()-1)-zzToString(N).size());
    mensaje = mensaje.substr(0,(mensaje.size()-1)-zzToString(N).size());
    int num = (zzToString(N).size());
    for(int i = 0; i < mensaje.size();){
        int a = 0;
        string temp;
        while(a < num){
            a++;
            temp += mensaje[i];
            ++i;
        }
        ZZ valor = chino_Firma(stringTozz(temp));
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
    /**##############################################################################**/

    return rpta;
}

ZZ Firma::chino_Firma(ZZ num){
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

void Firma::generar_claves(int bits)
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
    this -> e = e;
    this -> d = inversa(e, phi_N);
}

void Firma::impr_claves(){
    cout << "Clave publica: " << this -> e << endl;
    cout << "N: " << this -> N << endl;
    ofstream guardarClaves;
    guardarClaves.open("Claves.txt");
    guardarClaves << "e: " << e << endl;
    guardarClaves << "N: " << N << endl;
    guardarClaves.close();
}
