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
	regex inRegex("\\d+ \\d+ \\d+\n(\\d+ \\d+\n)+(\\d+\n)+");

	ifstream inf("data.in");

	stringstream in;
	in << inf.rdbuf();
	inf.close();

	if (!regex_match(in.str(), inRegex)){
		cerr << "Input didn't match regex!" << endl;
		cout << 0 << endl;
		return 0;
	}

	int N, M, Q;

	in >> N >> M >> Q;

	for (int i = 0; i < N-1; i++){
		int X, Y;
		in >> X >> Y;
	}

	for (int j = 0; j < M; j++){
		int D;
		in >> D;
	}

	for (int k = 0; k < Q; k++){
		int C;
		in >> C;
	}

	in >> ws;
	assertTrue(in.eof());

	cout << 1 << endl;
}
