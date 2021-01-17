/**
 * https://www.acmicpc.net/problem/20161 
 * BOJ 20161 왜 동전은 하나씩만 뒤집는 거야
 
 아무리 고민을 해도 못풀겠어서.. 그리고 풀이를 보고도 이해가 잘 안돼서 결국 거의 베끼다시피 하여 제출한 문제 (...)
 아래 링크의 풀이를 보았음.
 https://justicehui.github.io/ps/2020/12/05/CatholicU2020/

 처음에 비트마스킹을 해야겠다고는 떠올림.
 또한 '짝수 개(n)가 바뀔 때 n번의 flip, 홀수 개(n)가 바뀔 때 K - n 번의 flip이 필요하다는 것을 알아냄.
 일단 위 사실을 기반으로 풀면 시간 복잡도가 더 개선이 될 것 같긴 함. 그런데 참고한 풀이는 애초에 반드시 현재 상태에서 한 번만 뒤집는 것을 전제로 함.
 => 그래서 같은 위치에서 여러번 뒤집을 수도 있음.
 풀이가 막혔던 부분은.. 사실 구현 자체가 힘들기도 했고 아래 풀이법 중 2번을 생각하지 못함. 1번도 여러모로 풀이에서 걸림돌이 됐고.
 이렇게 구현이 막히는 문제일수록 1, 2번이 중요한 듯.

 새로 생각해볼 수 있었던 풀이법
 1. 비트 상태가 꼭 정방향일 필요가 없다.
 예를 들어, 동전이 010111 로 놓여있으면 비트는 111010으로 놓아도 된다는 것. 사실 비트까지 010111로 놓아야한다는건 고정관념임.
 코드를 작성하면 알겠지만, 111010으로 놓는 것이 훨씬 연산이 간편하다. 고정관념에 빠지지 말고 반드시 간편한 방향으로 코드를 짜자.

 2. dp의 인덱스로 쓰이는 '현 상태'를 단순히 현재 동전의 상태가 아니라, 현재 동전이 목표 동전상태와 '다른' bit를 1로 저장하는 마스크로 함 (XOR)
 => 다른 사람들의 풀이를 봐도 다 이렇게 함. 상태를 다루는 비트마스킹 DP를 할 때 자주 쓰이는 테크닉인듯 ..?
 이렇게 해서 얻는 장점: 아래 소스코드를 보면 맨 앞 1개가 다음 bit와 동일하면 (mask >> 1)을 다루고 있는 것을 확인할 수 있음.
 아직 보지않은 다음 비트를 반드시 다음 목표 비트와 같은 비트로 쉽게 지정할 수 있음. ( >> 1이면 마지막은 0이고 0은 같음을 나타낸다)

 3. 문제를 단순화
 위에서 말했듯이 아래 풀이는 현재 상태에서 한 번만 뒤집는 것을 전제로 한다.
 처음 내가 풀이를 떠올리려고 했을 때 한 번이 아니라 여러번 뒤집는 것까지 고려하면서 풀었더니 풀이가 너무 복잡해짐.
 그냥 한번에 하나씩 움직이면서 인덱스를 안움직이고 가는 부분까지 고려한다면 풀이가 더 단순화된다.
 이럴 경우 시간복잡도가 살짝은? 증가할 수 있을 것 같기도한데 별 차이도 없을듯
*/
#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int src[101];
int dst[101];
int dist[101][1 << 10];

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> src[i];
    for(int i = 1; i <= N; i++)
        cin >> dst[i];

    for(int i = 0; i < 101; i++)
        for(int j = 0; j < (1 << K); j++)
            dist[i][j] = INF;
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;    
    dist[1][0] = 0;
    pq.push({0, {1, 0}});
    while(!pq.empty()) {
        int v = pq.top().first;
        int idx = pq.top().second.first;
        int bit = pq.top().second.second;
        // bit 변수의 각 비트는 현재 상태가 표현하는 비트가 목표지와 다른지를 나타냄. (즉, 목표지와 XOR된 것)
        pq.pop();

        if(v > dist[idx][bit])
            continue;
        
        //No flip
        if((src[idx] ^ dst[idx]) == bit % 2 && idx + K - 1 < N) {
            if(dist[idx + 1][bit >> 1] > v) {
                dist[idx + 1][bit >> 1] = v;
                pq.push({v, {idx + 1, bit >> 1}});
            }
        }

        int inv_bit = bit;
        for(int i = 0; i < K; i++) inv_bit ^= (1 << i);
        for(int i = 0; i < K; i++) {
            int next = inv_bit ^ (1 << i);
            if(dist[idx][next] > v + 1) {
                dist[idx][next] = v + 1;
                pq.push({v + 1, {idx, next}});
            }
            if((src[idx] ^ dst[idx]) == next % 2 && idx + K - 1 < N) {
                if(dist[idx + 1][next >> 1] > v + 1) {
                    dist[idx + 1][next >> 1] = v + 1;
                    pq.push({v + 1, {idx + 1, next >> 1}});
                }
            }
        }
    }
    int last_bit = 0;
    int last_pos = N - K + 1;
    for(int i = 0; i < K; i++)
        last_bit |= ((src[last_pos + i] ^ dst[last_pos + i]) << i);
    if(dist[N - K + 1][last_bit] < INF) cout << dist[last_pos][last_bit];
    else cout << "-1";
}