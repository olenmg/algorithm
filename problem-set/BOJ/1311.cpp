/**
 * https://www.acmicpc.net/problem/1311
 * BOJ 1311 할 일 정하기 1
 
 매우 대표적인 비트마스킹DP 문제.
 전형적인 문제인만큼 어떤 방식이 어떻게 쓰였는지 잘 기억해야함.

 1. 순서가 없는 것에 순서를 정한다.
 - 1번째 사람~N번째 사람 순으로 차례대로 할 일을 정한다.
 - 현재 보고 있는 마스크에서 set된(1인) 비트수를 세고, 비트의 수가 k개이면 이제 k+1번째 사람이 할 일을 정하는 것이다.
 - 이렇게 순서를 정해둔다고 해도 결국 정답은 똑같다. (p번째 일을 1번 사람이 할 수도 있고 n번 사람이 할 수도 있음)

 2. 현재 마스크에 1개의 비트를 더 set한 수는 뒤에서 탐색하기 때문에 결국 순서대로 탐색해도 관계가 없다.
 - 예를 들어 101100이라는 수는 001100, 000100, 001000 등 덜 set된 수보다 반드시 뒤에서 탐색된다.
 - 따라서 for 0 to 2^N 으로 반복문을 돌려도 상관이 없는 것이다.

 3. dp[0] = 0 유념. 문제의 조건에 맞게 초기값을 제시해야 한다.
*/

#include <iostream>
#define INF 987654321
using namespace std;

int N;
int dp[1 << 20];
int cost[20][20];

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> cost[i][j];

    for(int i = 1; i < (1 << N); i++)
        dp[i] = INF;
    dp[0] = 0;
    for(int i = 0; i < (1 << N); i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++)
            if(i & (1 << j))
                cnt++;
        for(int j = 0; j < N; j++)
            if((i & (1 << j)) == 0)
                dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cost[cnt][j]);
    }
    cout << dp[(1 << N) - 1];
}