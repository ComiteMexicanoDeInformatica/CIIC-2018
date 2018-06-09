#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long int Long;
typedef vector<int> Lista;
typedef vector<Lista> Lista2D;

struct Arbol{

	Long res;
	int N,P,K;
	Lista valor;
	Lista2D aris;

	Arbol(int n,int p,int k): N(n), P(p), K(k),valor(n), aris(n), res(0) {}

	void AgregarArista(int u,int v){
		aris[u].push_back(v);
		aris[v].push_back(u);	
	}

	void Cuenta(int origen,int u,int p,int cnt){
		if(valor[u] < P) cnt++;
		if(cnt == K-1 && u >= origen) res++;
		for(int i = 0; i < aris[u].size(); i++){
			int v = aris[u][i];
			if(v == p) continue;
			Cuenta(origen,v,u,cnt);
		}
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

	for(int i = 0; i < N; i ++)
		A.Cuenta(i,i,i,0);
	

	cout << A.res << '\n';

	return 0;
}