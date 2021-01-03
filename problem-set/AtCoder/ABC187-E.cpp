/**
 * Link: https://atcoder.jp/contests/abc187/tasks/abc187_e
 * AtCoder Beginner Contest 187 E - Through Path
 
 * 문제의 방향성 탐색까지는 OK. 구현을 어떻게 하느냐에서 걸려서 못품.
 * 트리에서의 prefix sum 구현의 방향성에 대해 배울 수 있었음
 
 * 트리 하나를 어떤 정점을 기준으로 두 개의 트리로 나눌 수 있는데,
 * 이 때 전체 트리의 루트와 기준정점에 각각 값을 더하고 빼줌으로써 prefix sum 구현 가능
 * 만약 이 조건이 문제에서처럼 연결된 정점으로 주어지는게 아니고, 멀리 떨어진 정점으로 주어질 경우
 * LCA를 찾아야 할 듯. 그러면 난이도가 좀 올라가겠지만 똑같이 구현 가능 
 * 
 * 다른 방법: DFS를 사용하여 Euler tour 경로를 찾아낸 후,
 * 세그먼트 트리에서 적절한 range에 더해주는 방식
 * (lazy propagation을 이용할 수 있으나, 이것도 역시 아래 풀이와 같은 방식으로 구현 가능)
*/

#include <iostream>
#include <vector>
#define MAX_N 200001
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int parent[MAX_N];
ll vertex[MAX_N];
ll answer[MAX_N];
vector<int> graph[MAX_N];
vector<pii> edge(MAX_N);

void dfs_find_parent(int prev, int now) {
    parent[now] = prev;
    for(int child : graph[now])
        if(child != prev) 
            dfs_find_parent(now, child);
}

void dfs_find_answer(int prev, int now, ll v) {
    answer[now] = v;
    for(int child : graph[now])
        if(child != prev)
            dfs_find_answer(now, child, v + vertex[child]);
}
int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

	int N, Q;
	cin >> N;
	for(int i = 1; i <= N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
        edge[i] = {a, b};
	}
    dfs_find_parent(0, 1); // first, find parent. let 1 as root

	cin >> Q;
	while(Q--) {
		int t, e;
        ll x;
		cin >> t >> e >> x;
        
        int a = edge[e].first;
        int b = edge[e].second;
        if(t == 2) swap(a, b);

        if(a == parent[b]) {
            vertex[1] += x;
            vertex[b] -= x;
        } else {
            vertex[a] += x;
        }
    }

    dfs_find_answer(0, 1, vertex[1]);

    for(int i = 1; i <= N; i++)
        cout << answer[i] << "\n";
}