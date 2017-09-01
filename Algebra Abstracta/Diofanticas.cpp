#include <iostream>
#include <vector>

using namespace std;

int modulo(int a, int n)
{
    int q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}

vector <int> euclides_extendido(int a, int b)
{
    vector <int> resultados;
    int r1,s1,t1,r2,s2,t2,q,r;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    while(r2>0)
    {
        q = r1/r2;

        int r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        int s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;

    }
    resultados.push_back(r1);
    resultados.push_back(s1);
    resultados.push_back(t1);
    return resultados;
}

vector<int> diofantica(int a, int b, int c){
    vector<int> rpta;
    vector<int> variables = euclides_extendido(a,b);
    int d = variables[0];
    if(modulo(c,d)!=0){
        cout << "No existen soluciones enteras" << endl;
        return rpta;
    }
    int e = c/d;
    rpta.push_back(variables[1]*e);
    rpta.push_back(variables[2]*e);
    return rpta;
}

int main(){
    vector<int> prueba = diofantica(21,14,35);
    for(int i = 0; i < prueba.size(); i++){
        cout << prueba[i] << endl;
    }
    return 0;
}
