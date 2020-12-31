/**
	Floyd-Warshall algorithm    
    @floyd-warshall-algorithm.cpp
    @author olenmg

    [BOJ] #11404
*/
#include <iostream>
#include <vector>
#define MAX_V 101
#define INF 987654321
using namespace std;

typedef long long ll;
void floyd_warshall(int vnum, int graph[][MAX_V]) {
	for(int stopover = 1; stopover <= vnum; stopover++) {
		for(int i = 1; i <= vnum; i++) {
			for(int j = 1; j <= vnum; j++) {
				graph[i][j] = min(graph[i][j], graph[i][stopover] + graph[stopover][j]);
			}
		}
	}
}
int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);

	int V, E; // n, m;
	int graph[MAX_V][MAX_V];
	cin >> V >> E;
	for(int i = 1; i <= V; i++)
		for(int j = 1; j <= V; j++)
			graph[i][j] = (i == j ? 0 : INF);

	for(int i = 0; i < E; i++) {
		int u, v, w; // a, b, c
		cin >> u >> v >> w;
		graph[u][v] = min(graph[u][v], w); 
    }

	floyd_warshall(V, graph);
	for(int i = 1; i <= V; i++) {
		for(int j = 1; j <= V; j++)
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << " ";
		cout << "\n";
	}
}
