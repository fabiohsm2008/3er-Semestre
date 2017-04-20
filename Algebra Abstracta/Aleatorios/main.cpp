#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <vector>

using namespace std;

int ga(int bits_seed, int bits_num, int particiones, int vueltas)
{
    srand(time(NULL));
    bitset <1024> a;
    vector< bitset<512> > part_n;
    bitset<512> aux;

    for(int i = 0; i < bits_seed; i++){
        a[i + bits_num - bits_seed] = rand()%2;
    }
    int hola = bits_num - 1;

    for(int i = bits_num - bits_seed - 1; i >= 0; i--)
    {
        a[i] = a[hola] ^ a[hola - 1];
        hola--;
    }



    cout << a << endl;
}

int main(){
    ga(30,1024,2,5);
    return 0;
}
