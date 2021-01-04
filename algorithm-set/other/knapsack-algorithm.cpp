/**
    Knapsack algorithm
    @knapsack-algorithm.cpp
    @author olenmg

    [BOJ] #12865

    For solving backpack problem. This algorithm is based on DP.
    dp[i][j] means max value of backpack with usable weight of w when only 1 ~ i-th item can be stored.
    dp[i][j] = max(with i-th item, without i-th item) 

    배낭 문제 해결을 위한 DP 기반 알고리즘.
    dp[i][j]는 i번째 물건까지 넣을 수 있일 때 가용무게 j인 배낭의 최대 가치.
    dp[i][j] = max(i번째 물건을 넣을 때, i번째 물건을 넣지 않을 때) 로 구현된다.
    헷갈렸던 점은 dp[i][j - 1]은 고려하지 않아도 되는가였는데, 
    i번째 물건을 넣지 않는 경우는 가용무게 j - 1 < j이므로 당연히 dp[i - 1][j]가 당연히 더 클 것이고,
    i번째 물건을 넣는 경우도 가용무게가 j - 1 < 이므로 dp[i][j - 1] < dp[i - 1][j - w[i]] + v[i] 임이 자명하다. 

    특별한건 없는데 가끔 헷갈릴 때가 있어서 넣음.
*/
#include <iostream>
using namespace std;

int N, K;
int w[101], v[101];
int dp[101][100001];

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> w[i] >> v[i];
    for(int i = 1; i <= N; i++) { // things
        for(int j = 0; j <= K; j++) { // weight
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[N][K];
}