/**
    Kruskal's algorithm    
    @kruskals-algorithm.cpp
    @author olenmg

    [BOJ] #1197
*/
#include <iostream>
#include <queue>
#define MAX_NODE 10001
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipi;

// Union-find
int parent[MAX_NODE];
int level[MAX_NODE];
int find(int u) {
	return parent[u] == u ? u : parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if(u == v)
		return;
	if(level[u] > level[v])
		swap(u, v);
	if(level[u] == level[v])
		level[v]++;
	parent[u] = v;
}

int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);

	int V, E;
	priority_queue<pipi, vector<pipi>, greater<pipi>> pq;

	cin >> V >> E;
	for(int i = 1; i <= V; i++)
		parent[i] = i;
	for(int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		pq.push({C, {A, B}});
	}

	// Kruskal's algorithm
	int answer = 0;
	while(!pq.empty()) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();

		if(find(u) == find(v))
			continue;
		merge(u, v);
		answer += w;
	}
	cout << answer;
}