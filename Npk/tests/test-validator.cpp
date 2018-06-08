#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>
#include <set>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef pair<int,int> pii;

#define assertTrue(p) \
	{ const bool pv = p;\
	if (!pv) {\
		cerr << "Assertion failure! Expected true." << endl;\
		cerr << "Expression: " << #p << endl;\
		cout << 0 << endl; exit(0);\
	}}

#define assertEqual(p, q)\
	{ const auto &pv = p; const auto &qv = q;\
	if (pv != qv) {\
		cerr << "Assertion failure!" << endl;\
		cerr << #p << " != " << #q << endl;\
		cerr << pv << " != " << qv << endl;\
		cout << 0 << endl; exit(0);\
	}}

struct lit {
	char c;
	lit(char c) : c(c) {}
};

istream& operator >> (istream &in, lit target){
	char c;
	in >> c;
	assertEqual(c, target.c);
	return in;
}

class UnionFind {
	vector<int> _id;

public:
	UnionFind(int N) : _id(N) {
		iota(_id.begin(), _id.end(), 0);
	}

	int id(int x){
		if (x == _id[x]) return x;
		return _id[x] = id(_id[x]);
	}

	void join(int x, int y){
		_id[id(x)] = id(y);
	}
};

int N, P, K;
vector<int> e;
vector<pii> edges;

bool isTree(){
	UnionFind uf(N+1);

	for (pii e: edges){
		if (uf.id(e.fst) == uf.id(e.snd))
			return false;
		uf.join(e.fst, e.snd);
	}

	return true;
}

int main(int argc, char *argv[]){
	ifstream inf("data.in");

	stringstream in;
	in << inf.rdbuf();
	inf.close();

	in >> noskipws;

	in >> N >> lit(' ') >> P >> lit(' ') >> K >> lit('\n');

	assertTrue(1 <= N && N <= 500000);
	assertTrue(1 <= K && K <= N+1);
	assertTrue(1 <= P && P <= 1000000000);

	e.reserve(N+1);
	edges.reserve(N-1);

	for (int i = 1; i <= N; i++){
		int x;
		in >> x >> lit(i < N ? ' ' : '\n');
		e[i] = x;

		assertTrue(1 <= e[i] && e[i] <= 1000000000);
		assertTrue(e[i] != P);
	}

	for (int i = 0; i < N-1; i++){
		int X, Y;
		in >> X >> lit(' ') >> Y >> lit('\n');

		assertTrue(1 <= X && X <= N);
		assertTrue(1 <= Y && Y <= N);

		if (X > Y) swap(X, Y);

		edges.emplace_back(X, Y);
	}

	// check there's nothing left to read
	in.get();
	assertTrue(in.eof());

	assertTrue(isTree());

	string caseName(argv[1]);

	if (caseName.find("line") != string::npos){
	} else if (caseName.find("tree") != string::npos){
	} else {
	}

	cout << 1 << endl;
}
