#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long int Long;
const Long MAXD = 100000000000LL;

struct elem{

	__int128 val;
	bool oo;
	elem() : val(0), oo(false) {}
	elem(__int128 x) : val(x), oo(false) {}

	elem operator*( elem b ) const { 
		elem ret = elem();
	
		ret.val = val * b.val;
		if(ret.val > __int128(MAXD) || oo || b.oo ){
			ret.val = 0;
			ret.oo = true;
		}
		return ret; 
	}

};

struct SegTree{

	int n;
	vector<elem> arbol;

	void Init(int ini,int fin,int pos,vector<Long> &vals){
		if(ini == fin){
			arbol[pos] = elem(vals[ini]);
			return;
		}
		int mitad = (ini+fin)/2;
		Init(ini,mitad,pos*2+1,vals);
		Init(mitad+1,fin,pos*2+2,vals);
		arbol[pos] = arbol[pos*2+1] * arbol[pos*2+2];
	}

	SegTree(int N, vector<Long> &vals): n(N), arbol(4*N) {	
		Init(0,n-1,0,vals);
	}

	elem Query(int ini,int fin,int pos,int inir,int finr){
		if(fin < inir || finr < ini) return elem(1);
		if(ini >= inir && fin <= finr) return arbol[pos];
		int mitad = (ini+fin)/2;
		elem izq = Query(ini,mitad,pos*2+1,inir,finr);
		elem der = Query(mitad+1,fin,pos*2+2,inir,finr);
		return izq*der;		
	}

	elem Query(int ini,int fin){
		return Query(0,n-1,0,ini,fin);
	}

};

struct BIT{
	int n;
	vector<int> arbol;

	BIT(int N): n(N), arbol(N+1) {}

	void Update(int pos,int val){
		while(pos <= n){
			arbol[pos] += val;
			pos += (pos&-pos);
		}
	}

	int Query(int pos){
		int ret = 0;
		while(pos){
			ret += arbol[pos];
			pos -= (pos&-pos);
		}
		return ret;
	}

};

int lectura(vector<Long> &flavor){
	try{
		for(int i = 0; i < flavor.size(); i++)
			cin >> flavor[i];					
	} catch(...){
		return 0;
	}
	return 1;
}

int main(){

	Long D;
	int R,M;
	int I,L;	

	optimizar_io(0);

	ifstream fin("data.in");	

	fin >> R >> M;
	
	vector<Long> flavor(R);

	if(lectura(flavor)){
		SegTree producto = SegTree(R,flavor);
		BIT visitado = BIT(R);

		elem reg = elem();
		bool mala = false;
		for(int i = 0; i < M; i ++){
			fin >> I >> L >> D;			
			reg = producto.Query(I-1,L-1);
			if(reg.oo || reg.val != D){
				mala = true;
				break;
			}		
			visitado.Update(I,1);
			visitado.Update(L+1,-1);
		}

		for(int i = 0; i < R; i ++){
			if(!visitado.Query(i+1) && flavor[i] != 1){
				mala = true;
				break;
			}
		}

		if(mala) cout << "0\n";
		else cout << "1\n";

	} else {
		cout << "0\n";
	}


	return 0;
}