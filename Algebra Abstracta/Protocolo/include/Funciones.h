#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <sstream>

using namespace std;
using namespace NTL;

int rdtsc();
ZZ modulo(ZZ a, ZZ n);
ZZ euclides(ZZ a, ZZ b);
ZZ mcd(ZZ a, ZZ b);
vector <ZZ> euclides_extendido(ZZ a, ZZ b);
ZZ inversa(ZZ a, ZZ alfabeto);
ZZ potencia(ZZ a, ZZ b, ZZ modu);
string zzToString(ZZ z);
ZZ stringTozz(string str);
vector<bool> ZZtoBinary(ZZ num);
ZZ potenciaMod(ZZ n, ZZ m, ZZ mod);

int potencia_i(int a, int b, int modu);
int modulo_i(int a, int n);

ZZ raiz_primitiva(ZZ p);

///Funciones para aleatorios
ZZ convertir_decimal(vector <bool> a, int bits_num);
void rotar_derecha(vector <bool> &vec, int indice, int elementos, int vueltas);
void rotar_izquierda(vector <bool> &vec, int indice, int elementos, int vueltas);
vector <bool> ga(int bits_seed, int bits_num, int particiones, int vueltas);
vector<bool> permutar56(vector<bool> bits);
vector<bool> permutar48(vector<bool> bits);
vector<bool> rotarizquierda(vector<bool> num, int vueltas);
vector<bool> partir(vector<bool> numero,int posicion, int numeros);
vector<bool> unir(vector<bool> A, vector<bool> B);
ZZ des(int bits);

#endif

