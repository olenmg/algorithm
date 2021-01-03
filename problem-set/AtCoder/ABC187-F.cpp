/**
 * Link: https://atcoder.jp/contests/abc187/tasks/abc187_f
 * AtCoder Beginner Contest 187 F - Close Group
 
 * 손도 못 댄듯.. 접근 방법을 못찾음
 
 * 1. N이 작다면 ? -> bit masking / brute force 부터 생각
 * 2. 이 문제는 해설을 보고도 좀 헷갈렸던게 비트마스킹을 edge로 하지 않고 vertex로 했다는거
 * vertex로 하면 해당 vertex들을 다 잇는 선이 graph에 존재하냐 안하냐로 single component 판별이 가능
 * 즉, vertex로만 dp를 돌리면서 그 vertex 다 잇는 edge가 존재하면 single component로 판단하는거임
 * 3. single component까지만 판단하고 그 이후로는 single component 여러개가 존재하는지 판별하면서 합치는 식의 DP
 * 
 * 또 배운점은, 비트마스킹으로 부분집합 판별이 가능
 * 기준 mask인 i에 대하여 j = (j - 1) & i 를 하면 모든 부분집합을 볼 수 있다. 
 * 모든 마스크에 대하여 각 마스크의 부분집합 판별은 C(N, K) * (2^N)의 합 즉, (1+2)^N = 3^N의 시간복잡도를 갖는다.
 * ** https://cp-algorithms.com/algebra/all-submasks.html 참조
*/

#include <iostream>
#define MAX_N 19
#define INF 987654321
using namespace std;

int dp[1 << MAX_N];
int graph[MAX_N][MAX_N];
int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    for(int i = 0; i < (1 << N); i++) {
        // i 마스크의 '1' 표시있는 vertex들이 다 연결되어있다고 가정하는 것.
        dp[i] = 1;

        // 근데 만약 다 연결되어있어야할 edge가 연결 안되어있으면 이건 못만드는거니까 INF로 설정
        // 다 연결되어있는지 naive하게 N^2의 시간복잡도로 체크해줌
        for(int j = 0; j < N; j++) 
            if(i & (1 << j))
                for(int k = j + 1; k < N; k++)
                    if((i & (1 << k)) && !graph[j + 1][k + 1])
                        dp[i] = INF;
        
        // 연결이 다 되었다면 당연히 이번 dp값은 1이겠으나, 연결이 안되어있다면?
        // 이걸 나눠서 연결할 수 있는지 확인해본다. mask(j) | mask(i ^ j) = mask[i]임. (j와 i^j는 중복없음)
        // dp[j]와 dp[i ^ j]는 모두 i의 부분집합에 대한 dp이니까 당연히 이전 i에서 탐색되었을 것
        for(int j = (i - 1) & i; j; j = (j - 1) & i)
            dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
    }
    cout << dp[(1 << N) - 1];
}