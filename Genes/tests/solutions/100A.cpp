#include "genes.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cstdlib>

using namespace std;
#define forn(i,n) for(int i=0;i<(int)(n);i++)

const int MAX_COST = 1000000000;

struct NodeInformation
{
    int leader; // Every connected component has a designated leader (standard union find)
    int leaderSign; // Either -1 or 1
    long long  K;
    // node_index = leaderSign * leader_index + K
};

void tryScience(int T, int C, int *cost, int *gene1, int *gene2)
{
    cerr << "T: " << T << endl;
    cerr << "C: " << C << endl;

    forn(i,C) assert(0 <= cost[i] && cost[i] <= MAX_COST);
    forn(i,C) assert(1 <= gene1[i] && gene1[i] <= T);
    forn(i,C) assert(1 <= gene2[i] && gene2[i] <= T);
    
    {
        // No combination of genes appears twice
        set<pair<int,int> > geneSet;
        forn(i,C)
        {
            pair<int,int> p(gene1[i] , gene2[i]);
            if (p.first > p.second) swap(p.first, p.second);
            assert(geneSet.find(p) == geneSet.end());
            geneSet.insert(p);
        }
    }
    
    // ============== The Solution Itself ============
    
    forn(i,C)
    {
        // Map to zero-based convention
        gene1[i]--;
        gene2[i]--;
    }
    vector<pair<int,int> > sortedEdges(C);
    forn(i,C) sortedEdges[i] = make_pair(cost[i], i);
    sort(sortedEdges.begin(),sortedEdges.end());
    
    vector<vector<int> > component(T);
    vector<NodeInformation> nodes(T);
    map<int, long long> knownLeaders; // Productivity indexes of component-leaders that we have already determined
    forn(i,T)
    {
        // Initially, each node is the leader of its single-element component.
        nodes[i].leader = i;
        nodes[i].leaderSign = 1;
        nodes[i].K = 0;
        component[i].push_back(i);
    }
    
    // Calculates the value of an already determined index
    #define determined(x) (knownLeaders.find(nodes[x].leader) != knownLeaders.end())
    #define value(x) (nodes[x].leaderSign * knownLeaders[nodes[x].leader] + nodes[x].K)
    
    forn(edgeIndex,sortedEdges.size())
    {
        int g1 = gene1[sortedEdges[edgeIndex].second];
        int g2 = gene2[sortedEdges[edgeIndex].second];
        if (determined(g1) > determined(g2))
            swap(g1,g2);
        if (determined(g2) && !determined(g1))
        {
            cout << g2 << endl;
            long long g1Value = measureBacteria(g1+1,g2+1) - value(g2);
            knownLeaders[nodes[g1].leader] = (g1Value - nodes[g1].K) / nodes[g1].leaderSign;
        }
        else if (!determined(g2))
        {
            int l1 = nodes[g1].leader;
            int l2 = nodes[g2].leader;
            if (l1 != l2)
            {
                // Join
                if (component[l1].size() > component[l2].size())
                {
                    swap(g1,g2);
                    swap(l1,l2);
                }
                // g1's component is now the small component: we write l1 in terms of l2.
                // (M - K1 - K2)/s1 - s2/s1 * l2 =  l1 
                int l1Sign = - nodes[g2].leaderSign / nodes[g1].leaderSign;
                long long l1K    = (measureBacteria(g1+1,g2+1) - nodes[g1].K - nodes[g2].K) / nodes[g1].leaderSign;
                
                // Iterate over l1's component, inserting it into l2's and updating all values accordingly.
                forn(j, component[l1].size())
                {
                    int node = component[l1][j];
                    nodes[node].leader = l2;
                    nodes[node].K += nodes[node].leaderSign * l1K;
                    nodes[node].leaderSign *= l1Sign;
                    component[l2].push_back(node);
                }
            }
            else if (nodes[g1].leaderSign == nodes[g2].leaderSign)
            {
                // Determine the leader's productivity index
                knownLeaders[nodes[g1].leader] = (measureBacteria(g1+1,g2+1) - nodes[g1].K - nodes[g2].K) / (nodes[g1].leaderSign + nodes[g2].leaderSign);
            }
        }
    }

    vector<int> answerI;
    vector<long long> answerV;

    forn(i,T)
    if (determined(i))
        answerI.push_back(i+1), answerV.push_back(value(i));
    report((int)answerI.size(), answerI.data(), answerV.data());
}
