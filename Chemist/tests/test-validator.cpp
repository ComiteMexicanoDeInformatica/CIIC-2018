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

#define assertTrue(p)\
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

int main(int argc, char *argv[]){
	regex inRegex("\\d+ \\d+\n(\\d+ \\d+ \\d+\n)+");

	ifstream inf("data.in");

	stringstream inbuf;
	inbuf << inf.rdbuf();

	string input = inbuf.str();
	inf.close();

	if (!regex_match(input, inRegex)){
		cerr << "Input didn't match regex!" << endl;
		cout << 0 << endl;
		return 0;
	}

	istringstream in(input);

	long long R, M;

	in >> R >> M;

	assertTrue(1 <= R && R <= 100000);
	assertTrue(1 <= M && M <= R);

	set<pii> seen;
	vector<pii> e(2*R);

	for (int i = 0; i < M; i++){
		long long I, L, D;
		in >> I >> L >> D;

		assertTrue(1 <= I && I <= R);
		assertTrue(1 <= L && L <= R);
		assertTrue(I <= L);

		assertTrue(1 <= D && D <= 100000000000LL);

		e[2*i] = pii(I, L);
		e[2*i+1] = pii(L, I);

		// no repeats
		assertTrue(seen.insert(pii(I, L)).snd);
	}

	in >> ws;
	assertTrue(in.eof());

	sort(e.begin(), e.end());

	multiset<int> s;

	for (auto x: e){
		bool open = x.fst <= x.snd;

		if (open){
			auto it = s.upper_bound(x.snd);

			// no strict containment.
			assertTrue(it == s.end());

			if (x.fst != x.snd)
				s.insert(x.snd);
		} else if (x.fst != x.snd)
			s.erase(s.find(x.fst));
	}

	cout << 1 << endl;
}
