#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ n);

ZZ euclides(ZZ a, ZZ b);

ZZ inverso(ZZ a, ZZ b);

ZZ potencia(ZZ a, ZZ b, ZZ modu);

///Funciones para aleatorios
ZZ convertir_decimal(std::vector <bool> a, int bits_num);
void rotar_derecha(std::vector <bool> &vec, int indice, int elementos, int vueltas);
void rotar_izquierda(std::vector <bool> &vec, int indice, int elementos, int vueltas);
ZZ ga(int bits_seed, int bits_num, int particiones, int vueltas);

#endif
