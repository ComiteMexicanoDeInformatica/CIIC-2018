#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long int Long;
typedef vector<int> Lista;
typedef vector<Lista> Lista2D;

struct Arbol{

	Long res;
	int N, P, K;			
	Lista2D aris;	
	vector<bool> muerto;
	Lista hijos,cubeta,valor;

	Arbol(int n, int p, int k):N(n),P(p),K(k),aris(n),muerto(n),hijos(n),cubeta(n+1), valor(n), res(0) {}	

	void AgregarArista(int u,int v){
		aris[u].push_back(v);
		aris[v].push_back(u);
	}

	void Busca(int u,int pad){		
		int v;
		hijos[u] = 1;
		for(int i = 0 ; i < aris[u].size() ; i ++){
			v = aris[u][i];
			if(!muerto[v] && v != pad){
				Busca(v,u);
				hijos[u] += hijos[v];
			}
		}		
	}

	void Camino(int u, int pad, int cnt, int flag){
		if(valor[u] < P) cnt++;

		if(flag == 1) cubeta[cnt]++;			
		else if(flag == 0){
			if(cnt < K) res += Long(cubeta[K-1-cnt]);
		} else
			cubeta[cnt]--;		

		for(int i = 0; i < aris[u].size(); i ++){
			int v = aris[u][i];
			if(v == pad || muerto[v]) continue;
			Camino(v,u,cnt,flag);
		}
	}	


	void BuscaCentroides(int u){		
		Busca(u,u);
		int v;
		int act = u , pad = u;
		bool valido = true;

		do{
			valido = true;
			for(int i = 0 ;  i < aris[act].size() ; i++){
				v = aris[act][i]; 
				if(muerto[v] || v == pad) continue;
				if(hijos[v] > hijos[u]/2){
					valido = false;
					pad = act;
					act = v;				
					break;
				}
			}
		}while(!valido);

		u = act;		
		muerto[u] = true;
		for(int i = 0 ;  i < aris[u].size() ; i ++){
			v = aris[u][i];
			if(!muerto[v]) BuscaCentroides(v);
		}

		muerto[u] = false;		
		int primero = valor[u] < P ? 1 : 0;
		cubeta[primero]++;
		for(int i = 0; i < aris[u].size(); i++){
			v = aris[u][i];
			if(muerto[v]) continue;
			Camino(aris[u][i],u,0,0);
			Camino(aris[u][i],u,primero,1);
		}			
		Camino(u,u,0,2);
	}	

	void BuscaCentroides(){
		BuscaCentroides(0);
	}
	
};

int main(){
	
	int u, v;
	int N, P, K;

	optimizar_io(0);

	cin >> N >> P >> K; 

	Arbol A(N,P,K);

	for(int i = 0; i < N; i ++)
		cin >> A.valor[i];

	for(int i = 0; i < N-1; i ++){
		cin >> u >> v;
		u--, v--;
		A.AgregarArista(u,v);
	}

	A.BuscaCentroides();

	cout << A.res << '\n';

	return 0;
}