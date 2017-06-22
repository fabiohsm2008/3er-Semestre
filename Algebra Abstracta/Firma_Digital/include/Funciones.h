#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <sstream>

using namespace std;
using namespace NTL;

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
ZZ ga(int bits_seed, int bits_num, int particiones, int vueltas);

#endif

