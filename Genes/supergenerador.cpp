//#define _GLIBCXX_USE_C99 1
#include <cstdlib>
#include<iostream>
#include<numeric>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<set>
#include <random>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000 // 2 billion
typedef  long long  ll;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
#define PI 3.14159265
typedef map<string,int> msi;
#define REP(i, a, b) \
for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
///Estructura y como hacer que sirva con map,set,etc.

struct cosa
{
    int words;
    int next[26];
};
struct cost
{
    long long int a,b,c;
};

struct q
{
    int a;
    string b;
};
//int car[1000000];

//int arr1[10]= {-1,-1,-1,0,0,1,1,1};
//int arr2[10]= {-1,0,1,-1,1,-1,0,1};
int aa1[10]= {-1,1,0,0};
int aa2[10]= {0,0,-1,1};
//char cosa[10]= {'a','b','c','d','e'};
///LEER CON ESPACIOS SEA BUFFER CHAR[1000] scanf ("%[^\n]%*c", buffer);
///char k ='"';
int alfa,beta;
//int act;
char buffer[10];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


bool operator <(const cost &a,const cost &b)
{
    return a.c < b.c;
}
///Apartir de aqui normalmente inician mis codigos , si es que me estas espiando <3
///From here normally my code starts, thats if you are stalking me <3
string k;
string k1;
string vac;
string k3;
map<pair<int,int>,int> existe,vacio;
cost memo[1000000];
int main ()
{
    char prof='A';
    ios_base::sync_with_stdio(0);
  //  freopen ("1.in","r",stdin);
    //freopen ("20.in","w",stdout);
    long long   int  x=0,z,mal=INF,s=0,a1=0,b1=0,c1,x1,y1,t=-INF,res=0,e,f;
    long long   int  a,b,c,d,y=1,ya=1;
    cin>>k3;
    ///k3 es hard,easy,etc
    srand(time(NULL));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> Trand(1,50000),Crand(1,200000),Vrand(1,1000000);
    pair<int,int> genes;
    REP(tres,0,2)
    {
        existe=vacio;
        x=ya;
        ya++;
        k1=vac;
        while(x)
        {
            k1.push_back((x%10)+'0');
            x/=10;
        }
        reverse(k1.begin(),k1.end());
        k=k3;
        k+=k1;
        k1=k;
        k1.push_back('.');
        k1.push_back('i');
        k1.push_back('n');
       // k1.push_back('o');
       // k1.push_back('u');
      //  k1.push_back('t');
        fstream troy;
        troy.open (k1.c_str(),fstream::out);

           t=Trand(gen);
           c=Crand(gen);
        c=t;
           uniform_int_distribution<> GEN(1,t);
           int gen1=0,gen2=0,costo=Vrand(gen);
           troy<<t<<" "<<c<<endl;
           REP(i,0,c)
           {
                if(i!=0)
                {
                    troy<<endl;
                }
                gen1=0;
                gen2=0;
                costo=Vrand(gen);
                //costo=0;
                while(gen1==gen2)
                {
                    gen1=GEN(gen);
                    gen2=GEN(gen);
                    if(gen1==gen2)
                    {
                        continue ;
                    }
                   gen2=gen1+(rand()%2);
                   if(gen2>c)
                    continue ;

                    genes.first=gen1;
                    genes.second=gen2;
                    if(existe[genes]!=0)
                    {
                        gen2=gen1;
                    }
                    else
                    {
                        existe[genes]=1;
                        genes.first=gen2;
                        genes.second=gen1;
                        existe[genes]=1;
                        troy<<gen1<<" "<<gen2<<" "<<costo;
                        break;
                    }
                }
           }
           troy<<endl;
           REP(i,0,t)
           {
               if(i!=0)
               {
                   troy<<" ";
               }
               costo=Vrand(gen);
               if(rand()%2==0)
                costo*=-1;
               troy<<costo;
           }
           troy<<endl;
           costo=Vrand(gen);
           troy<<costo<<endl;

    }
}
