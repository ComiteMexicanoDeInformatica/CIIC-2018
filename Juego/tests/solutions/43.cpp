#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	int N;

	scanf("%d", &N);
	if(N<=20)
    {

	vector<int> v(2*N);

	for (int i = 0; i < 2*N; i++)
		scanf("%d", &v[i]);

	int same = 0, opp = 0;

	for (int i = 0; i < N; i++){
		same += abs(v[i] + v[i+N]);
		opp += abs(v[i] - v[i+N]);
	}

	printf("%d\n", max(same, opp));
    }
    else
    {
        cout<<-1;
    }
}
