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
map<pair<int,int>,int> par,vacio;
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
    REP(tres,0,5)
    {
        par=vacio;
        x=ya;
        ya++;
        k1=vac;
        while(x)
        {
            k1.push_back((x%10)+'0');
            x/=10;
        }
        reverse(k1.begin(),k1.end());
        k=k1;
        k1=k3+k;
        k1.push_back('.');
        k1.push_back('i');
        k1.push_back('n');
       // k1.push_back('o');
       // k1.push_back('u');
      //  k1.push_back('t');
        fstream troy;
        troy.open (k1.c_str(),fstream::out);

           a=rand()%100000009;
           a*=987654321;
           a%=100000;
           a++;
           troy<<a<<endl;
           REP(i,0,a*2)
           {
                if(i!=0)
                {
                    troy<<" ";
                }
                b=rand()%100000009;
                b*=987654321;
                b%=1000;
                b++;
                int trast=1;
                if(trast==1)
                    b*=-1;
                troy<<b;
           }
           troy<<endl;

    }
}
