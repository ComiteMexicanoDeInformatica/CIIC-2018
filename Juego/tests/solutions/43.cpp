#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int arreglo[1000];
int maximo=0,a;

void bruta(int x)
{
    if(x==a)
    {
        return ;
    }
    for(int i=0;i<a;i++)
    {
        arreglo[i+x]*=-1;
    }
    int actmax=0;
    for(int i=0;i<a*2;i++)
    {
        actmax+=arreglo[i];
    }
    maximo=max(actmax,maximo);
    bruta(x+1);
    for(int i=0;i<a;i++)
    {
        arreglo[i+x]*=-1;
    }
    for(int i=0;i<a*2;i++)
    {
        actmax+=arreglo[i];
    }
    maximo=max(actmax,maximo);
    bruta(x+1);
}

int main(){
	cin>>a;
	for(int i=0;i<a*2;i++)
    {
        cin>>arreglo[i];
    }
    bruta(0);
    cout<<maximo;

}
