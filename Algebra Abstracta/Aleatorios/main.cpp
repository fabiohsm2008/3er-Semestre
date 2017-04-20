#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>

using namespace std;

int ga(int bits_seed, const int bits_num, int particiones, int vueltas)
{
    srand(time(NULL));
    bitset <8> a;
    for(int i = 0; i < bits_seed; i++){
        a[i + bits_num - bits_seed] = rand()%2;
    }
    int hola = a.size()-1;
    for(int i = bits_num - bits_seed - 1; i >= 0; i--)
    {
        a[i] = a[hola] ^ a[hola - 1];
        hola--;
    }
    cout << a << endl;
}

int main(){
    ga(4,8,2,5);
    return 0;
}
