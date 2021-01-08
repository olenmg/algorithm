/**
    Segment tree (Data Structure)
    @segment-tree.cpp
    @author olenmg

    [BOJ] #2042
*/
#include <iostream>
#include <vector>
#include <cmath>
#define MAX_N 1000000
#define MAX_NODE (1 << ((int)ceil(log2(MAX_N)) + 1))
using namespace std;

typedef long long ll;
vector<ll> tree(MAX_NODE);
vector<ll> arr(MAX_N);

ll init(int node, int s, int e) {
    if(s == e)
        return tree[node] = arr[s];
    int mid = (s + e) / 2;
    return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

void update(int node, int t, int s, int e, ll diff) {
    if(t < s || t > e)
        return;
    tree[node] += diff;
    if(s != e) {
        int mid = (s + e) / 2;
        update(node * 2, t, s, mid, diff);
        update(node * 2 + 1, t, mid + 1, e, diff);
    }
}

ll sum(int node, int s, int e, int l, int r) {
    if(l <= s && e <= r)
        return tree[node];
    else if(s > r || e < l)
        return 0;
    int mid = (s + e) / 2;
    return sum(node * 2, s, mid, l, r) + sum(node * 2 + 1, mid + 1, e, l, r);
}
int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    init(1, 0, N - 1);

    M += K;
    while(M--) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            ll c;
            cin >> b >> c;
            update(1, b - 1, 0, N - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        } else {
            int b, c;
            cin >> b >> c;
            cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
}