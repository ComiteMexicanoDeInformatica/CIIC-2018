#include <cstdio>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

typedef pair<int,int> pii;

int main(){
	int N, M;

	scanf("%d %d %*d", &N, &M);
	printf("%d %d\n", N, M);

	vector<pii> v(N-1);

	for (int i = 0; i < N-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		if (x >= y) swap(x, y);

		v[i] = pii(x, y);
	}

	for (int i = 0; i < M; i++){
		int x;
		scanf("%d", &x);
		printf("%d %d\n", v[x-1].fst, v[x-1].snd);
	}
}
