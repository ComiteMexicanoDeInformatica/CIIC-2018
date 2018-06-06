#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <random>
#define se second
#define fi first
#define ll long long
using namespace std;

void solucion(string entrada,string salida);

ll arr[100010],MAX_VALUE=1e11,tam,x,rootM,group,subgroup;
vector<ll> primes;
vector< pair<ll,ll> > q;
ll stMax[600010],stMin[600010],maxRange[100010];
set< pair<ll,ll> > use;
vector< string > number;
ll proba[4][4];

ll queryMax(ll s,ll e,ll ini,ll fin,ll nd){
    if(e<s) return -1LL;
    if(ini>e || fin<s) return -1LL;
    if(s<=ini && fin<=e) return stMax[nd];
    ll md=(ini+fin)/2,leftC=nd+nd+1,rightC=nd+nd+2;
    return max( queryMax(s,e,ini,md,leftC) , queryMax(s,e,md+1,fin,rightC) );
}

void updateMax(ll pos,ll val,ll ini,ll fin,ll nd){
    if(ini>pos || fin<pos) return;
    if(ini==fin){
        stMax[nd]=max(stMax[nd],val);
        return;
    }
    ll md=(ini+fin)/2,leftC=nd+nd+1,rightC=nd+nd+2;
    updateMax(pos,val,ini,md,leftC);
    updateMax(pos,val,md+1,fin,rightC);
    stMax[nd]=max(stMax[leftC],stMax[rightC]);
    return;
}

ll queryMin(ll s,ll e,ll ini,ll fin,ll nd){
    if(e<s) return MAX_VALUE;
    if(ini>e || fin<s) return MAX_VALUE;
    if(s<=ini && fin<=e) return stMin[nd];
    ll md=(ini+fin)/2,leftC=nd+nd+1,rightC=nd+nd+2;
    return min( queryMin(s,e,ini,md,leftC) , queryMin(s,e,md+1,fin,rightC) );
}

void updateMin(ll pos,ll val,ll ini,ll fin,ll nd){
    if(ini>pos || fin<pos) return;
    if(ini==fin){
        stMin[nd]=min(stMin[nd],val);
        return;
    }
    ll md=(ini+fin)/2,leftC=nd+nd+1,rightC=nd+nd+2;
    updateMin(pos,val,ini,md,leftC);
    updateMin(pos,val,md+1,fin,rightC);
    stMin[nd]=min(stMin[leftC],stMin[rightC]);
    return;
}

bool outOfRange(ll A_, ll B_){
    return (bool)(A_<0 || A_>=tam || B_<0 || B_>=tam);
}

ll getProduct(ll A_,ll B_){
    ll p_=1LL;
    for(ll i=A_; i<=B_; i++) p_*=arr[i];
    return p_;
}

bool valido(ll L_,ll R_){

    if(use.find({L_,R_})!=use.end()) return false; /// Si ya existe ese rango
    if(outOfRange(L_,R_) || L_>=R_ || R_>maxRange[L_]) return false;
    ll xyz = getProduct(L_,R_);
    if(tam>100 && xyz<8){
        x++;
        if(x>rootM) return false; /// No dar mas raiz de M rangos con producto 1,2,3,5,6 o 7
    }
    if(queryMax(0,L_-1,0,tam-1,0)>R_) return false;       /// Checar si existe un rango que contenga a [ L_ , R_ ]
    if(queryMin(L_+1,R_-1,0,tam-1,0)<R_) return false;    /// Checar si [ L_ , R_ ] contiene algun rango
    return true;
}



int main()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<unsigned long long> getR(20, 100000);
    std::uniform_int_distribution<unsigned long long> porcentaje(1, 10000);
    std::uniform_int_distribution<unsigned long long> getNumber(1, MAX_VALUE);

    primes.push_back(2);
    primes.push_back(2);
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    std::uniform_int_distribution<unsigned long long> getPos(0, primes.size()-1);

    number.push_back("1");
    number.push_back("2");
    number.push_back("3");

    proba[1][1]=8000;
    proba[1][2]=9900;

    proba[2][1]=5000;
    proba[2][2]=9500;

    proba[3][1]=2000;
    proba[3][2]=9000;

    for (long long CASO=0; CASO<42; ++CASO)
    {
        x=0;
        ofstream in;
        stringstream ss;
        if(CASO%3LL==0LL){
                group++;
                subgroup=0;
        }
        subgroup++;
        ss << group;
        string str = ss.str();
        in.open("case"+str+"." + number[subgroup-1]+".in");
        ll mod=MAX_VALUE;
        if(CASO<20) mod=10000;
        if(CASO<5) mod=20;

        ll R=(getR(gen)%mod)+1,M;
        std::uniform_int_distribution<unsigned long long> getM(1, R);
        do{ M = getM(gen); }while(M<2); tam = R;
        if(CASO>32){
            R=M=tam=100000;
        }
        rootM = sqrt(M);
        /// Generar el arreglo sobre el cual trabajara el caso
        /// Para caseN.1.in hay 80% de 1's, 19% de 2,3,5,7 y 1% de cualquier numero
        /// Para caseN.2.in hay 50% de 1's, 45% de 2,3,5,7 y 5% de cualquier numero
        /// Para caseN.3.in hay 20% de 1's, 70% de 2,3,5,7 y 10% de cualquier numero
        for(ll i=0; i<R; i++)
        {
            ll ppp = porcentaje(gen);

            ll testcase = 1;
            if(ppp<proba[subgroup][2]) testcase++;
            if(ppp<proba[subgroup][1]) testcase++;

            if(testcase==1){
                arr[i]=getNumber(gen);
            }
            if(testcase==2){
                arr[i]=primes[getPos(gen)];
            }
            if(testcase==3){
                arr[i]=1;
            }
        }

        /// Para cada posicion i determinar el mayor indice j tal que el producto del rango [ i , j ] sea menor o igual a 10^{11} O( R )
        ll prod=1LL,sig=0LL;
        for(ll i=0; i<R; i++)
        {
            bool band=true;

            while(band)
            {
                if(sig>=R){
                    maxRange[i]=R-1;
                    band=false;
                    continue;
                }
                ll prod_=prod*arr[sig];
                if(prod_>0 && prod_<=MAX_VALUE)
                {
                    prod=prod_;
                    sig++;
                }
                else
                {
                    maxRange[i]=sig-1;
                    prod/=arr[i];
                    band=false;
                }
            }
        }

        /// ST de maximos y minimos fines (de rango) de entre todos los rangos en el inicio i, para validar en O(lg R) que agregar
        /// un nuevo rango no este contenido en ningun otro pero pueda ser prefijo o sufijo
        for(ll i=0; i<600010; i++){
            stMax[i]=-1;
            stMin[i]=MAX_VALUE;
        }

        std::uniform_int_distribution<unsigned long long> iniRange(0, R-1);
        use.clear(); q.clear();
        while(M--){

             ll s_,e_,cont=0;
             do{
                s_=iniRange(gen);
                std::uniform_int_distribution<unsigned long long> finRange(min(s_+1,R-1), maxRange[s_]);
                e_=finRange(gen);
                cont++;
             }while(!valido(s_,e_) && cont<=10000);
             if(cont>10000) break;
             use.insert({s_,e_});
             q.push_back({s_,e_});
             updateMax(s_,e_,0,R-1,0);
             updateMin(s_,e_,0,R-1,0);
        }

        ll maxDif = -1,pos__,sumoOfSize=0;
        in << R << " " << q.size() <<"\n";
        random_shuffle(q.begin(),q.end());
        for(ll i=0; i<q.size(); i++){
                in << q[i].fi << " " << q[i].se << " " << getProduct(q[i].fi,q[i].se) << "\n";
                if(q[i].se-q[i].fi+1>maxDif){
                    maxDif=q[i].se-q[i].fi+1;
                    pos__=i;
                }
                sumoOfSize+=q[i].se-q[i].fi+1;
        }

        in.close();
        solucion("case"+str+"." + number[subgroup-1]+".in", "case"+str+"." + number[subgroup-1]+".out");
    }
    return 0;
}


void solucion(string entrada,string salida)
{
    /**inicia la redirección de cin y cout. NO BORRAR**/
    std::ifstream in(entrada);
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out(salida);
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    /**termina la redirección de cin y cout**/

    /**la solución del problema**/

}
