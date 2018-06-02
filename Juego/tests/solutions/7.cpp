#include<bits/stdc++.h>
using namespace std;

int main ()
{
     ios_base::sync_with_stdio(0);
   long long  int  a,b,c,d,x,y=0;
   cin>>a;
   for (int i=0;i<a*2;i++)
   {
       cin>>x;
       if(x<0)
       {
           x*=-1;
       }
       y+=x;
   }
   cout<<y;

}
