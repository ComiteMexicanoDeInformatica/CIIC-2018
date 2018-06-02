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
    int  a,b,c,d;
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
long long int gcd(long long int a,long long int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool operator <(const cost &a,const cost &b)
{
    return a.a<b.a;
}
///Apartir de aqui normalmente inician mis codigos , si es que me estas espiando <3
///From here normally my code starts, thats if you are stalking me <3


string k;
string vac,resulta;
long long int troy[1000000];
int main ()
{
     ios_base::sync_with_stdio(0);
//    memset(tablero,-1,sizeof(tablero));
    //freopen ("test.in","r",stdin);
    //freopen ("1.in","w",stdout);
    int  z,mal=INF,s=INF,a1=0,b1=0,c1,x1,y1,t=-INF,res=0,e=-1,f;
   long long  int  a,b,c,d,x,y=0;
   cin>>a;
   REP(i,0,a*2)
   {
       cin>>x;
       y+=x;
   }
   cout<<y;

}
