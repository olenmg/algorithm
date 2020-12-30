/**
	Bellman-Ford algorithm    
    @bellman-ford-algorithm.cpp
    @author olenmg

    [BOJ] #11657
*/
#include <iostream>
#include <vector>
#define MAX_V 501
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
bool bellman_ford(int start, int vnum, ll dist[], vector<pii> const (&graph)[MAX_V]) {
	for(int i = 1; i <= vnum; i++) dist[i] = INF;
	dist[start] = 0LL;

	for(int i = 1; i < vnum; i++) {
		for(int now = 1; now <= vnum; now++) {
			for(pii next : graph[now]) {
				int next_node = next.first;
				ll w = (ll)next.second;
				if(dist[now] != INF) // EASY TO MISS! (same goes below)
					dist[next_node] = min(dist[next_node], dist[now] + w);
			}
		}
	}
	
	for(int now = 1; now <= vnum; now++) {
		for(pii next : graph[now]) {
			int next_node = next.first;
			ll w = (ll)next.second;
			if(dist[now] != INF && dist[next_node] > dist[now] + w) // (here)
				return false; // cycle exists
		}
	}

	return true; // no cycle
}
int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);

	int V, E; // N, M
	ll dist[MAX_V];
	vector<pii> graph[MAX_V];

	cin >> V >> E;
	for(int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
    }

	if(bellman_ford(1, V, dist, graph)) {
		for(int i = 2; i <= V; i++)
			cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
	} else {
		cout << "-1\n";
	}
}
