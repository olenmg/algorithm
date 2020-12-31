/**
    Dijkstra's algorithm    
    @dijkstras-algorithm.cpp
    @author olenmg

    [BOJ] #1753
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 20001
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void dijkstra(int start, int vnum, ll dist[], vector<pii> const (&graph)[MAX_V]) {
	bool visit[MAX_V] = {false};
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for(int i = 1; i <= vnum; i++) dist[i] = INF;
	dist[start] = 0;
	pq.push({0, start});

	while(!pq.empty()) {
		int now = pq.top().second;
		pq.pop();

		if(visit[now])
			continue;
		visit[now] = true;

		for(pii next : graph[now]) {
			int next_v = next.second;
			ll w = (ll)next.first;
			if(!visit[next_v] && dist[next_v] > dist[now] + w) {
				dist[next_v] = dist[now] + w;
				pq.push({dist[next_v], next_v});
			}
		}
	}
	
}
int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);

	int V, E, K;
	ll dist[MAX_V];
	vector<pii> graph[MAX_V];

	cin >> V >> E >> K;
	for(int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
    }

	dijkstra(K, V, dist, graph);
	for(int i = 1; i <= V; i++) {
		if(dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
