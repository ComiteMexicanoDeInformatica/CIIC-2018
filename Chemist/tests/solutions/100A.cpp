#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long int Long;

struct rango{

	int L,R;
	Long val;

	rango() : L(0), R(0), val(0) {}
	rango(int l, int r,int v) : L(l) , R(r), val(v) {}
	bool operator<(const rango &b) const {
		if(L == b.L) return R < b.R;
		return L < b.L;
	}

};


int main(){

	Long m;
	int R,M;
	int L,D;

	cin >> R >> M;
	set<rango> nuevos;
	vector<Long> sol(R,1);
	for(int i = 0; i < M; i ++){
		cin >> L >> D >> m;
		nuevos.insert(rango(L,D,m));
	}


	Long g;
	rango act,sig;	
	while(nuevos.size() > 1){
		auto it = nuevos.begin();
		act = *it;
		sig = *(++it);
		if(sig.L <= act.R){
			if(sig.L == act.L){				
				nuevos.erase(it);
				if(sig.R != act.R){
					sig.L = act.R+1;
					sig.val /= act.val;					
					nuevos.insert(sig);
				}
			} else {
				nuevos.erase(it);
				nuevos.erase(--it);
				g = __gcd(act.val,sig.val);
				sol[act.L-1] = act.val / g;
				act.val = g;
				act.L = sig.L;
				nuevos.insert(act);
				if(act.R != sig.R){
					sig.L = act.R+1;
					sig.val /= g;
					nuevos.insert(sig);
				}
			}			
		} else {
			nuevos.erase(--it);
			sol[act.L-1] = act.val;			
		}
	}

	act = *nuevos.begin();
	sol[act.L-1] = act.val;

	for(int i = 0; i < R; i ++){
		if(i) cout << ' ';
		cout << sol[i] ;
	}
	cout << '\n';

}
