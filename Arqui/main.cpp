#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

int suma(int a,int b){         ///Funcion para sumar bits
	int c = a&b,s=a^b;
	while(c!=0){
		int cs=c<< 1;
		c=s&cs;
		s ^= cs;
	}
	return s;
}

int complemento(int x){     ///Funcion para hallar el complemento a 2 de un numero
    x = ~x+1;
    return x;
}

int tam(int num){
    int tam;
    while(num > 0){
        ++tam;
        num = num>>1;
    }
    return tam;
}

int multi(int a,int b)              ///Multiplicacion en bits
{
    int result = 0;
    cout << a << " * " << b << endl;

    if(a < 0){
        a = complemento(a);
        b = complemento(b);
    }

    int n = tam(a);

    while (n > 0)
    {
        if (a & 1){
            result += b;
            cout << result << " \t " << (bitset<8>)result << endl;
        }
        a >>= 1;
        b <<= 1;
        --n;
    }
    cout << "El resultado final es: " << result << endl;
    cout << "El resutlado en bits es: " << (bitset<8>) result << endl;

    return result;
}

unsigned int division(unsigned int m, unsigned int q){      ///Division en bits
    unsigned int a=0;
	int n = tam(m), count=n;
	while(n>0){
		a=a<<1;
		if(q&pow(2,count)==pow(2,count))
			a++;
		q=q<<1;
		a=suma(a,complemento(m));
		if(a<0){
			if((q&1)==1)
				q--;
			a=suma(a,m);
		}
		else
		   if((q&1)==0)
				q++;
		n--;
	}
	return q;
}

int main()
{
    int a = 11;
    int b = 15;
    multi(a,b);

    /*unsigned int m = 9;
    unsigned int q = 3;
    cout << division(a,b) << endl;*/
}
