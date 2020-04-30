#include <iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<utility>
#include<numeric>
using namespace std;
struct sortiranje{
    unsigned long long int brracuna1;
    string ime1;
    double saldo1;
};
bool isort(sortiranje a,sortiranje b)
{
    if(a.ime1>b.ime1)
        return true;
    return false;
}
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
bool kaj(string ime[],int brklijenata,string unoss,unsigned long long int brracuna[],double saldo[])
{
    int i,bo=0;
    for(i=0;i<brklijenata;i++)
        if(ime[i]==unoss)
        {
            cout<<"Broj racuna: "<<brracuna[i]<<" Ime klijenta:  "<<ime[i]<<" Saldo:  "<<saldo[i]<<endl;
            bo++;
        }
    if(bo>0)
        return true;
    return false;
}
int main()
{
    int brklijenata=0,i,j;
    unsigned long long int *brracuna=new unsigned long long int [1000];
    string *ime=new string [1000];
    unsigned long long int brisi;
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
        else if(izbor==3)
        {
            cout<<"Unesite ime: ";
            cin.ignore();
            getline(cin,unoss);
          if(kaj(ime,brklijenata,unoss,brracuna,saldo))
          {
              for(i=0;i<brklijenata;i++)
              cout<<"Broj racuna: "<<brracuna[i]<<" Ime klijenta:  "<<ime[i]<<" Saldo:  "<<saldo[i]<<endl;
          }
          else
              cout<<"Nema takvih racuna"<<endl;
        }
        else if(izbor==4)
        {
            cin>>brisi;
             int k=0;
            for(i=0;i<brklijenata;i++)
            {
                if(brisi==brracuna[i])
                {
                    k++;
                    for(j=i+1;j<brklijenata;j++)
                    {
                        brracuna[j-1]=brracuna[j];
                        saldo[j-1]=saldo[j];
                        ime[j-1]=ime[j];
                    }
                    brklijenata--;
                    break;
                }
            }
            if(k==0)
             cout<<"Ne postoji taj racun";
        }
        else if(izbor==5)
        {
            sortiranje polje[brklijenata];
            for(i=0;i<brklijenata;i++)
            {
             polje[i]. brracuna1=brracuna[i];
             polje[i].ime1=ime[i];
             polje[i].saldo1=saldo[i];
            }
            sort(polje,polje+brklijenata,isort);
            for(i=0;i<brklijenata;i++)
            cout<<"Broj racuna: "<<polje[i].brracuna1<<" Ime klijenta:  "<<polje[i].ime1<<" Saldo:  "<<polje[i].saldo1<<endl;
        }
        else if(izbor==7)
        {
            cout<<"Hvala sto ste koristili program!"<<endl;
            return 0;
        }
            system("pause");
            system("CLS");
}
    return 0;
}

