/**
    Fenwick tree (Data Structure)
    @fenwick-tree.cpp
    @author olenmg

    [BOJ] #2042
*/
#include <iostream>
#include <vector>
#define MAX_N 1000000
using namespace std;

typedef long long ll;

int N, M, K;
vector<ll> arr(MAX_N + 1);
vector<ll> tree(MAX_N + 1, 0);

void update(int i, ll diff) {
    while(i <= N) {
        tree[i] += diff;
        i += (i & -i);
    }
}
ll sum(int i) {
    ll ret = 0;
    while(i > 0) {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    M += K;
    while(M--) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            ll c;
            cin >> b >> c;
            update(b, c - arr[b]);
            arr[b] = c;
        } else {
            int b, c;
            cin >> b >> c;
            cout << sum(c) - sum(b - 1) << "\n";
        }
    }
}