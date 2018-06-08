#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

typedef pair<int,int> pii;

int main(){
	std::random_device rd;
	std::mt19937 gen(rd());

	int N, M;
	string strategy;

	cin >> N >> M >> strategy;

	cout << N << ' ' << M << endl;

	vector<pii> edges;

	if (strategy == "random"){
		std::uniform_int_distribution<> p(1, N);
		for (int i = 0; i < M/4; i++){
			int a = p(gen), b;
			do b = p(gen); while (a == b);
			if (a > b) swap(a, b);
			edges.emplace_back(a, b);
		}
	} else if (strategy == "treeplus"){
		assert(M >= 2*N);

		for (int i = 2; i <= N; i++){
			std::uniform_int_distribution<> p(1, i-1);
			edges.emplace_back(p(gen), i);
		}

		std::uniform_int_distribution<> p(1, N);
		for (int i = 1; i <= N; i++){
			int a = p(gen), b;
			do b = p(gen); while (a == b);
			if (a > b) swap(a, b);
			edges.emplace_back(a, b);
		}
	} else {
		cerr << "Invalid strategy." << endl;
		assert(false);
	}

	std::uniform_int_distribution<> conn(0, edges.size()-1);
	for (int i = 0; i < M; i++){
		int e = conn(gen);
		cout << edges[e].first << ' ' << edges[e].second << endl;
	}
}
