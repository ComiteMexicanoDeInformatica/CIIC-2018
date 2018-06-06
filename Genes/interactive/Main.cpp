#include "genes.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

map<pair<int,int>,int> testCaseCosts;
vector<long long> testCaseIndexes;

vector<bool> reportable;
vector<vector<int>> adj;

int testCaseT, optK;
long long testCaseTotalCost = 0, optCost;

void score(double x){
	cout << x << endl;
	exit(0);
}

vector<bool> color;
vector<bool> visited;

bool reportabledfs(int x, bool c = false){
	if (visited[x])
		return color[x] != c;

	color[x] = c;
	visited[x] = true;

	for (auto y: adj[x])
		if (reportabledfs(y, !c))
			return true;

	return false;
}

void paint(int x){
	if (reportable[x]) return;

	visited[x] = reportable[x] = true;
	optK++;

	for (auto y: adj[x])
		paint(y);
}

void findReportable(){
	reportable = vector<bool>(testCaseT+1);
	color = vector<bool>(testCaseT+1);
	visited = vector<bool>(testCaseT+1);

	for (int i = 1; i <= testCaseT; i++)
		if (!visited[i] && reportabledfs(i))
			paint(i);
}

long long measureBacteria(int gene1, int gene2)
{
	if (gene1 < 1 || gene1 > testCaseT ||
		gene2 < 1 || gene2 > testCaseT)
	{
		cerr << "Out of range genes (" << gene1 << "," << gene2 << ")" << endl;
		score(0);
	}
	pair<int,int> p(gene1,gene2);
	if (testCaseCosts.find(p) == testCaseCosts.end())
	{
		cerr << "Impossible to produce bacteria (" << gene1 << "," << gene2 << ")" << endl;
		score(0);
	}
	testCaseTotalCost += testCaseCosts[p];
	return testCaseIndexes[gene1-1] + testCaseIndexes[gene2-1];
}

void report(int K, int *kinds, long long *values)
{
	if (K != optK){
		cerr << "Didn't find the correct number of genes!" << endl;
		cerr << "Expected: " << optK << endl;
		cerr << "Found: " << K << endl;
		score(0);
	}

	vector<bool> visited(testCaseT+1, false);

	for (int i = 0; i < K; i++){
		if (visited[kinds[i]]){
			cerr << "Duplicated kind: " << kinds[i] << endl;
			score(0);
		}

		visited[kinds[i]] = true;

		if (testCaseIndexes[kinds[i]-1] != values[i]){
			cerr << "Invalid value for kind: " << kinds[i] << endl;
			cerr << "Expected: " << testCaseIndexes[kinds[i]-1] << endl;
			cerr << "Got: " << values[i] << endl;
			score(0);
		}
	}

	for (int i = 1; i <= testCaseT; i++){
		if (!visited[i] && reportable[i]){
			cerr << "Kind missing from report: " << i << endl;
			score(0);
		}
	}
	
	cerr << "Expected optimal cost: " << optCost << endl;

	if (testCaseTotalCost < optCost){
		cerr << "Contestant found a better cost?!: "
		     << testCaseTotalCost << endl;
		exit(1);
	} else if (testCaseTotalCost > optCost){
		cerr << "Contestant gave non-optimal query cost: " << testCaseTotalCost << endl;
		score(0);
	}

	score(1);
}

int main()
{
	cin >> testCaseT;
	adj = vector<vector<int>>(testCaseT+1);

	int C; cin >> C;

	cerr << "T = " << testCaseT << endl;
	cerr << "C = " << C << endl;

	vector<int> gene1(C), gene2(C), cost(C);
	forn(i,C)
	{
		cin >> gene1[i] >> gene2[i] >> cost[i];

		testCaseCosts[make_pair(gene1[i],gene2[i])] = cost[i];
		testCaseCosts[make_pair(gene2[i],gene1[i])] = cost[i];

		adj[gene1[i]].push_back(gene2[i]);
		adj[gene2[i]].push_back(gene1[i]);
	}

	findReportable();

	testCaseIndexes.resize(testCaseT);
	forn(i,testCaseT) cin >> testCaseIndexes[i];

	cin >> optCost;
	
	tryScience(testCaseT, C, cost.data(), gene1.data(), gene2.data());

	cerr << "report was never called!" << endl;
	score(0);
}
