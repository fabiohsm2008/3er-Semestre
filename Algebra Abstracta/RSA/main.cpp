#include <iostream>
#include <fstream>
#include "RSA.h"

using namespace std;

int main()
{
    srand(time(NULL));
    /**ifstream ficheroEntrada;
    string mensaje;
    ficheroEntrada.open ("mensaje.txt",ios::out | ios::binary);
    getline(ficheroEntrada,mensaje);
    ficheroEntrada.close();
    RSA receptor(512);
    /*receptor.set_p(stringTozz("3033058104364587777301649224066897044718090035752557577767398758792886556930683886193244742111168716653924518888657886953597137928269798608302231140213563"));
    receptor.set_q(stringTozz("4188713856051730030527755468732128652892657612091528510567075289127877040647398483149583955062017268185485049450755069837852340285466158570551245997116211"));
    receptor.set_N(stringTozz("12704612507961943086842896654718822564677087686870197202866602945676607648494097770191167054247409630628135937630554348358903604149787668658632748316499772747443217408471532150706497728240923389584850841527273183997906274087347642364408391123066501147989268155114436843598969059021816470965792911892669369793"));
    receptor.set_d(stringTozz("9579092735594065042440248953489491536725833054437595393850010325216306883705704145646391209859049300496710610141763542657686445587787881618458328499391823485548433867670732771451226676926161722729812024123092097424931370703212206698077803474839390366294606866702006984378464151398262646617482889101900572957"));
    receptor.set_e(stringTozz("7290591002354201134542048342668614155459233566391948999274795462109710373033395681693177400726006941291323090264250874810823406740288058770373617511217273"));*/
    ///RSA emisor(receptor.get_e(),receptor.get_N());
    /**ZZ e, N;
    /*Cristhian
    e = stringTozz("8050189495819646230367274162312647113687626492793618413811586219413549346409258142644748710444378881002845334635603379236368509428785940922547000358874607");
    N = stringTozz("32541992493192865024404949100205090074774547028968420336938354508114503087301882130019975844009324892080271630066696753285827484808839015255783666113103060446639218367506960291517013790938792999283818593504523408179377470255102546421314864037841412187291154764655718889340996262811672588268220788382494232829");
    */
    /*Alejandro*/
    /**e = stringTozz("1059887421200093008444548582463508531294716966910687851560566280194962299338163259145264389158809414582147648591133571712263217450654979476836194934807931");
    N = stringTozz("18125502443370898743644540610551919868826544327945581290754442075793508504214724264294615595583738943762784420453289031955990518281480249890518866647383155571118823094988602294863357846052845195713876773644316841307191223326627777997384798016429251399902842902768677633528698390309069901853362903602611707987");
    RSA emisor(e, N);
    ///string cifrado = emisor.cifrar(mensaje);
    ///cout << cifrado << endl;

    string original = receptor.descifrar(mensaje);
    cout << original << endl;
    ofstream ficherosalida;
    ficherosalida.open ("ofset.txt");
    ficherosalida << original;
    ///ficherosalida << cifrado;
    ficherosalida.close();**/
    cout << "RSA Cifrado y Descifrado" << endl;
    cout << "1: Imprimir claves" << endl;
    cout << "2: Cifrar un Texto" << endl;
    cout << "3: Descifrar un Texto" << endl;
    cout << "0: Salir" << endl;
    int x;
    cin >> x;
    RSA Receptor(1024);
    while(x != 0){
        switch (x){
        case 1:{
            Receptor.impr_claves();}
            break;
        case 2:{
            string a, b;
            cout << "Ingrese clave publica: ";
            cin >> a;
            cout << "Ingrese N: ";
            cin >> b;
            RSA emisor(stringTozz(a), stringTozz(b));
            ifstream ficheroEntrada;
            string mensaje;
            ficheroEntrada.open ("temp.txt");
            getline(ficheroEntrada,mensaje);
            ficheroEntrada.close();
            ofstream ficheroSalida;
            ficheroSalida.open("mensaje.txt");
            ficheroSalida << emisor.cifrar(mensaje);
            ficheroSalida.close();}
            break;
        case 3:{
            ifstream entrada;
            string mess;
            entrada.open ("entrada.txt");
            getline(entrada,mess);
            cout << Receptor.descifrar(mess);
            entrada.close();
            ofstream salida;
            salida.open("ofset.txt");
            salida << Receptor.descifrar(mess);
            salida.close();}
            break;
        }
        cin >> x;
    }
    return 0;
}
