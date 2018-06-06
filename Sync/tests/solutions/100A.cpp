#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

#define fst first
#define snd second

struct edge {
	int node, s, e;

	edge(int node, int s, int e) :
		node(node), s(s), e(e) {}
};

const int maxn = 5010;

int N, M;
vector<edge> adj[maxn];
map<pii, int> last;

int ans[maxn], t[maxn];

int dijkstra(int s){
	fill(t, t+N, M);

	t[s] = 0;

	static priority_queue<pii, vector<pii>, greater<pii>> q;

	q.push(pii(0, s));

	while (!q.empty()){
		auto curr = q.top(); q.pop();

		if (t[curr.snd] > curr.fst)
			continue;

		for (auto e: adj[curr.snd]){
			if (e.e < curr.fst)
				continue;

			int tt = max(curr.fst, e.s);

			if (tt >= t[e.node])
				continue;

			t[e.node] = tt;

			q.push(pii(tt, e.node));
		}
	}

	for (int i = 0; i < N; i++)
		if (t[i] < M)
			ans[i]++;
}

int main(){
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;

		auto it = last.find(pii(x,y));

		if (it != last.end()){
			adj[x].push_back(edge(y, it->snd, i));
			adj[y].push_back(edge(x, it->snd, i));
			last.erase(it);
		} else last[pii(x,y)] = i;
	}

	for (auto p: last){
		int x = p.fst.fst;
		int y = p.fst.snd;
		adj[x].push_back(edge(y, p.snd, M));
		adj[y].push_back(edge(x, p.snd, M));
	}

	for (int i = 0; i < N; i++)
		dijkstra(i);

	for (int i = 0; i < N; i++)
		printf("%d\n", ans[i]);
}
