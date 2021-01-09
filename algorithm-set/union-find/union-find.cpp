/**
    Union-find (Data strcture)
    @code union-find.cpp
    @author olenmg

    [BOJ] #1717
*/
#include <iostream>
#define MAX_N 1000000
using namespace std;

int parent[MAX_N + 1];
int level[MAX_N + 1];

int getParent(int u) {
    return u == parent[u] ? u : parent[u] = getParent(parent[u]);
}

void merge(int u, int v) {
    u = getParent(u);
    v = getParent(v);

    if(u == v)
        return;
    if(level[u] > level[v])
        swap(u, v);
    else if(level[u] == level[v])
        level[v]++;
    parent[u] = v;
}

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
        parent[i] = i;
	while(m--) {
		int op, a, b;
		cin >> op >> a >> b;
		if(op == 0) 
            merge(a, b);
		else 
            cout << (getParent(a) == getParent(b) ? "YES" : "NO") << "\n";
	}
}