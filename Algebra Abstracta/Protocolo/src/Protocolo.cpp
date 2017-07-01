#include "Protocolo.h"

Protocolo::Protocolo(int bits)
{
    generar_aleatorios(bits);
    cout << q << endl;
    cout << g << endl;
}

Protocolo::~Protocolo()
{

}

Protocolo::Protocolo(ZZ publicaE, ZZ publicaN, int bits){
    generar_aleatorios(bits);
    this -> e2 = publicaE;
    this -> N2 = publicaN;
}

string Protocolo::cifrar(string mensaje){
    ZZ a = modulo(des(1024),N2-1);
    ZZ K = potenciaMod(g,a,N2);
    ZZ Ca = potenciaMod(a,e2,N2);
    string digitos;
    for(int i = 0; i < mensaje.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(mensaje[i]));
        string nume = zzToString(to_ZZ(alfabeto.find(alfabeto[alfabeto.size()-1])));
        int num_pos = zzToString(pos).size();
        if(num_pos < nume.size()){
            digitos += "0";
            num_pos++;
        }
        digitos += zzToString(pos);
    }
    ZZ temp = to_ZZ(digitos.size());
    ZZ N_1 = to_ZZ(zzToString(this -> q).size()-1);
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
        ZZ temp_2 = modulo(stringTozz(tempi)*K,this -> N2);
        ZZ cont_num = to_ZZ(zzToString(temp_2).size());
        while(cont_num < zzToString(q).size()){
            dig_2 += "0";
            ++cont_num;
        }
        dig_2 += zzToString(temp_2);
    }
    int tama = zzToString(N2).size()-zzToString(Ca).size();
    string cifrado(tama,'0');
    cifrado += zzToString(Ca);
    cifrado += dig_2;
    return cifrado;
}

string Protocolo::descifrar(string mensaje){
    string C = mensaje.substr(0,zzToString(N1).size());
    mensaje = mensaje.substr(zzToString(N1).size());
    ZZ Km = potenciaMod(stringTozz(C),this -> D,this -> N1);
    string resultado;
    int num = (zzToString(N1).size());
    for(int i = 0; i < mensaje.size();){
        int a = 0;
        string temp;
        while(a < num){
            a++;
            temp += mensaje[i];
            ++i;
        }
        ZZ valor = modulo(stringTozz(temp)*inversa(Km,N1),N1);
        int x = zzToString(valor).size();
        while(x < zzToString(q).size()-1){
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

string Protocolo::firmar(){

}

void Protocolo::generar_aleatorios(int bits){
    this -> p1 = des(bits);
    this -> p2 = des(bits);
    this -> N1 = p1*p2;
    ZZ phi_N;
    phi_N = (p1 - 1) * (p2 - 1);
    this -> e1 = des(bits);
    while(e1 > phi_N || (euclides(e1, phi_N) != 1))
    {
        e1 = des(bits);
    }
    this -> D = inversa(e1, phi_N);
    this -> q = des(bits);
    this -> g = raiz_primitiva(q);
}
