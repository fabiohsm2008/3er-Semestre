#include "Funciones.h"

ZZ modulo(ZZ a, ZZ n)
{
    ZZ q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}
ZZ euclides(ZZ a, ZZ b)
{
     ZZ residuo = modulo(a,b);
     while(residuo!=0)
     {
         a = b;
         b = residuo;
         residuo = modulo(a,b);
     }
     return b;
}
ZZ mcd(ZZ a, ZZ b)
{
    ZZ resultado;
    resultado = 1;
    ZZ i;
    for(i=1;i<=a;i++)
    {
        if((modulo(a,i)==0)&&(modulo(b,i)==0))
        {
            resultado = i;
        }
    }
    return resultado;
}
vector <ZZ> euclides_extendido(ZZ a, ZZ b)
{
    vector <ZZ> resultados;
    ZZ r1,s1,t1,r2,s2,t2,q,r;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    while(r2>0)
    {
        q = r1/r2;

        ZZ r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        ZZ s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        ZZ t = t1 - q * t2;
        t1 = t2;
        t2 = t;

    }
    resultados.push_back(r1);
    resultados.push_back(s1);
    resultados.push_back(t1);
    return resultados;
}
ZZ inversa(ZZ a, ZZ alfabeto)
{
    ZZ x = euclides_extendido(a,alfabeto)[1];
    if(x<0)
    {
        return modulo(x,alfabeto);
    }
    return x;
}
ZZ potencia(ZZ a, ZZ b, ZZ modu)
{
    ZZ result = to_ZZ(1);
    ZZ n = to_ZZ(2);
    ZZ wapo = to_ZZ(a);
    while(b != 0){
        if(modulo(b,n)==1){
            result = modulo((result * wapo),modu);
        }
        wapo = modulo((wapo * wapo),modu);
        b = b/2;
    }
    return result;
}

string zzToString(ZZ z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ stringTozz(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}

int potencia_i(int a, int b, int modu)
{
    int result = 1;
    while(b != 0){
        if(b&1){
            result = modulo_i((result * a),modu);
        }
        cout << a << endl;
        a = modulo_i((a * a),modu);
        b = b/2;
    }
    return result;
}

int modulo_i(int a, int n)
{
    int q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}

vector<bool> ZZtoBinary(ZZ num){
    vector<bool> binario;
    while(num>0){
        binario.push_back(to_int(modulo(num,to_ZZ(2))));
        num=num>>1;
    }
    return binario;
}

ZZ potenciaMod(ZZ n, ZZ m, ZZ mod){
    if(n>mod)
        n=modulo(n,mod);
    vector<bool> b=ZZtoBinary(m);
    ZZ d=to_ZZ(1);
	for(int i=b.size();i>0;i--){
        d=modulo(d*d,mod);
        if(b[i-1]==1)
            d=modulo(d*n,mod);
	}
	return d;
}


///Funciones para aleatorios ##############################################################################
ZZ convertir_decimal(vector <bool> a, int bits_num)
{
    ZZ num;
    num = 0;
    int e = 0;
    for(int i = bits_num - 1; i >= 0; i--)
    {
        if(a[i])
        {
            num += power2_ZZ(e);
        }
        else
            num += to_ZZ(0);
        e += 1;
    }
    return num;
}
ZZ convertir_base10(string a)
{
    ZZ num;
    num = 0;
    int e = 0;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        if(a[i] == '1')
        {
            num += power2_ZZ(e);
        }
        else
            num += to_ZZ(0);
        e += 1;
    }
    return num;
}
void rotar_derecha(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    bool temp;
    bool ultimo = vec[indice + elementos - 1];
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = elementos + indice - 1; i > indice; i--)
        {
            temp = vec[i];
            vec[i] = vec[i - 1];
            vec[i - 1] = temp;
        }
    }
    vec[indice] = ultimo ^ vec[rand()%(elementos-1)];
}
void rotar_izquierda(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    bool temp;
    bool primero = vec[indice];
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = indice; i < indice + elementos - 1; i++)
        {
            temp = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = temp;
        }
    }
    vec[indice + elementos - 1] = primero ^ vec[rand()%(elementos - 1)];
}
vector<bool> ga(int bits_seed, int bits_num, int particiones, int vueltas)
{
    vector <bool> a;
    for(int i = 0; i < bits_num; i++)
    {
        a.push_back(0);
    }
    for(int i = 0; i < bits_seed; i++)
    {
        a[i] = rand()%2;
    }
    int s = 0;
    for(int i = bits_seed; i < bits_num; i++)
    {
        a[i] = a[s] ^ a[s+1];
        s++;
    }
    int elementos_pedazo = bits_num/particiones;
    int indice = 0;
    int cont_particiones = 0;
    while(cont_particiones < particiones - 1)
    {
        if(cont_particiones%2 == 0)
        {
            rotar_izquierda(a, indice, elementos_pedazo, vueltas);
        }
        else
            rotar_derecha(a, indice, elementos_pedazo, vueltas);
        indice += elementos_pedazo;
        cont_particiones++;
    }
    if(cont_particiones%2 == 0)
    {
        rotar_izquierda(a, indice, bits_num - ((particiones - 1) * elementos_pedazo), vueltas);
    }
    else
        rotar_derecha(a, indice, bits_num - ((particiones - 1) * elementos_pedazo), vueltas);

    return a;
}

string permutar56(string bits){
    string respuesta;
    int tabla_predefinida[56] = {57,49,41,33,25,17,9,1,57,50,42,34,26,18,10,2,59,57,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    for(int i = 0; i < 56; i++){
        respuesta+= bits[tabla_predefinida[i]-1];
    }
    return respuesta;
}

string permutar48(string bits){
    string respuesta;
    int tabla_predefinida[48] = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,41,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    for(int i = 0; i < 48; i++){
        respuesta+= bits[tabla_predefinida[i]-1];
    }
    return respuesta;
}

string rotarizquierda(string num, int vueltas)
{
    char temp;
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = 0; i < num.size() - 1; i++)
        {
            temp = num[i];
            num[i] = num[i + 1];
            num[i + 1] = temp;
        }
    }
    return num;
}

ZZ des(int bits){
    vector<bool> valores = ga(11,bits,3,3);
    string digitos;
    for(int i = 0; i < valores.size(); i++){
        if(valores[i])
            digitos+='1';
        else
            digitos+='0';
    }
    int vueltas[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    string actual;
    for(int j = 0; j < bits; j+=64)
        actual += permutar56(digitos.substr(j,64));
    for(int k = 0; k < 16; k++){
        string num_48bits;
        for(int l = 0; l < actual.size(); l+=56){
            string c = rotarizquierda(actual.substr(l,28),vueltas[k]);
            string d = rotarizquierda(actual.substr(l+28,28),vueltas[k]);
            num_48bits += (c+d);
        }
        if(num_48bits[num_48bits.size()-1] == '0')
            num_48bits[num_48bits.size()-1] = '1';
        ZZ resultado = convertir_base10(num_48bits);
        if(ProbPrime(resultado,10)){
            return resultado;
        }
        actual = num_48bits;
    }
    return des(bits);
}
