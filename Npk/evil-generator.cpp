#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int N, P, K, S, sq;

int main(){
	scanf("%d", &N);

	P = 2;
	K = sq = sqrt(N);

	S = N/3;

	vector<int> nodes, e(N+1);
	nodes.reserve(N-1);

	e[S] = 2;

	vector<pii> edges;
	edges.reserve(N-1);

	for (int i = 1; i < S; i++)
		nodes.push_back(i);
	for (int i = S+1; i <= N; i++)
		nodes.push_back(i);

	for (int i = 0; i < nodes.size(); i += sq){
		int k = min(sq, (int)nodes.size() - i);

		for (int j = 0; j < k; j++)
			e[nodes[i+j]] = j % 2 ? 1 : 3;

		for (int j = 0; j < k-1; j++)
			edges.emplace_back(nodes[i+j], nodes[i+j+1]);

		edges.emplace_back(nodes[i+k-1], S);
	}

	printf("%d %d %d\n", N, P, K);

	for (int i = 1; i <= N; i++)
		printf("%d%c", e[i], i < N ? ' ' : '\n');

	for (auto ee: edges)
		printf("%d %d\n", ee.first, ee.second);
}
