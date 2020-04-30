#include <iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<utility>
#include<numeric>
using namespace std;
bool negativan(int a)
{
    if (a<0)
        return true;
    return false;
}
bool tekuci(unsigned long long int a)
{
    if(a/100000000==32)
        return true;
    return false;
}
int main()
{
    int brklijenata=0,i;
    unsigned long long int *brracuna=new unsigned long long int [1000];
    string *ime=new string [1000];
    double *saldo=new double[1000];
    unsigned long long int unos;
    string unoss;
    int izbor;
    while(1)
    {
        cout<<"1. Unos novog racuna"<<endl;
        cout<<"2. Ispisi sve podatke"<<endl;
        cout<<"3. Pretraga prema prezimenu i imenu"<<endl;
        cout<<"4. Brisanje racuna"<<endl;
        cout<<"5. Ispisi sortirano po prezimenu i imenu"<<endl;
        cout<<"6. Izmjena podataka prema broju racuna"<<endl;
        cout<<"7. Izlaz iz programa"<<endl;
        cin>>izbor;
        if(izbor==1)
        {
            while(1)
            {
        try {
                    cout<<"Unesite broj racuna ";
                    cin>>unos;
                    if(unos<1000000000 || unos>9999999999)
                            throw  "Broj racuna mora imati 10 znamenaka !";
                    break;
        } catch (const char* msg) {
            cout<<msg<<endl;
        }
            }

        brracuna[brklijenata]=unos;
        cout<<"Unesite prezime i ime: ";
        cin.ignore();
        getline(cin,ime[brklijenata]);
        cout<<"Unesite saldo: "<<endl;
        cin>>saldo[brklijenata];
        brklijenata++;
    }
        else if (izbor==2)
        {
        for(i=0;i<brklijenata;i++)
        {
            cout<<"Broj racuna: "<<brracuna[i]<<" Ime klijenta:  "<<ime[i]<<" Saldo:  "<<saldo[i]<<endl;
        }
        cout<<"Suma svih stanja na racunima iznosi: "<<accumulate(saldo,saldo+brklijenata,0.0)<<endl;
        cout<<"Najveci saldo ima: "<<ime[max_element(saldo,saldo+brklijenata)-saldo]<<endl;
        cout<<count_if(saldo,saldo+brklijenata,negativan)<<" racuna ima negativan saldo"<<endl;;
        cout<<count_if(brracuna,brracuna+brklijenata,tekuci)<<" gradana ima tekuci racun"<<endl;
        system("pause");
        }
}
    return 0;
}

