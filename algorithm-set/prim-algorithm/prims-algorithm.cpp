/**
    Prim's algorithm    
    @prims-algorithm.cpp
    @author olenmg

    [BOJ] #1197
*/
#include <iostream>
#include <queue>
#define MAX_NODE 10001
using namespace std;

typedef pair<int, int> pii;

int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);

	int V, E;
	vector<pii> graph[MAX_NODE];

	cin >> V >> E;
	for(int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({C, B});
		graph[B].push_back({C, A});
	}

	// Prim's algorithm
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 1});

	bool visit[MAX_NODE] = {false};
	int answer = 0;

	while(!pq.empty()) {
		int now = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if(visit[now])
			continue;
		visit[now] = true;

		answer += w;
		for(pii next : graph[now])
			if(!visit[next.second])
				pq.push(next);
	}
	cout << answer;
}