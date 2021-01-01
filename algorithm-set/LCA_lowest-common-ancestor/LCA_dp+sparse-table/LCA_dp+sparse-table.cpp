/**
    LCA finding (with sparse table)
    @LCA_dp+sparse-table.cpp
    @author olenmg

    [BOJ] #11438
*/
#include <iostream>
#include <vector>
#define MAX_NODE 100001
using namespace std;

vector<int> graph[MAX_NODE];
int ancestor[MAX_NODE][20]; // sparse table (2^19 > MAX_NODE)
int level[MAX_NODE];

void find_ancestor(int parent, int now) {
    level[now] = level[parent] + 1;
    ancestor[now][0] = parent;

    for(int i = 1; i < 20; i++)
        ancestor[now][i] = ancestor[ancestor[now][i - 1]][i - 1];

    for(int child : graph[now])
        if(child != parent)
            find_ancestor(now, child);
}
int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N;
	for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    level[0] = -1;
    find_ancestor(0, 1);

	cin >> M;
    while(M--) {
        int u, v;
        cin >> u >> v;
        
        if(level[u] > level[v])
            swap(u, v);
        int diff = level[v] - level[u];
        for(int i = 0; i < 20; i++)
            if(diff & (1 << i))
                v = ancestor[v][i];

        int answer = u;
        if(u != v) {
            for(int i = 19; i >= 0; i--) {
                if(ancestor[u][i] != ancestor[v][i]) {
                    u = ancestor[u][i];
                    v = ancestor[v][i];
                }
            }
            answer = ancestor[u][0];
        }
        cout << answer << "\n";
    }
}