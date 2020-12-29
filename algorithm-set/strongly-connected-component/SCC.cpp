/**
    Strongly Connected Component(SCC) 
    @SCC.cpp
    @author olenmg

    [BOJ] #2150
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX_NODE 10001
using namespace std;

vector<int> graph[MAX_NODE];

int cnt;
int dfsn[MAX_NODE];
bool finish[MAX_NODE];

int SCC[MAX_NODE]; 
// SCC array isn't used in this problem.
// But this may be useful in many other problems.
int totalSCC;
vector<vector<int>> SCCList; 

stack<int> s;
int dfs(int now) {
	dfsn[now] = ++cnt;
	s.push(now);
	
	int result = dfsn[now];
	for(int next : graph[now]) {
		if(dfsn[next] == 0)
			result = min(result, dfs(next));
		else if(!finish[next])
			result = min(result, dfsn[next]);
	}

	if(result == dfsn[now]) {
		vector<int> curSCC;
		while(!s.empty()) {
			int t = s.top();
			s.pop();

			finish[t] = true;
			curSCC.push_back(t);
            SCC[t] = totalSCC;

			if(t == now)
				break;
		}
		sort(curSCC.begin(), curSCC.end());
		SCCList.push_back(curSCC);
		totalSCC++;
	}
	return result;
}

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }
    for(int i = 1; i <= V; i++)
      if(dfsn[i] == 0)
        dfs(i);
    sort(SCCList.begin(), SCCList.end());

    cout << totalSCC << "\n";
    for(vector<int> v : SCCList) {
      for(int i : v)
        cout << i << " ";
      cout << "-1\n";
    }
}