#include <iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<utility>
#include<numeric>
using namespace std;

int main()
{
    int brklijenata=0;
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
}
    return 0;
}

