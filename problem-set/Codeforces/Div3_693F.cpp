/*
 	* Link: https://codeforces.com/contest/1472/problem/F
 	* Codeforces Round #693 (Div. 3) F - New Year's Puzzle
	 
	원래 아이디어: 처음~첫블록, 끝블록~끝 을 포함한, 블록 사이 거리가 너무 멀면(4 이상)
	그 좌표 차이가 홀수일 때와 짝수일 때 각각 맞는 값으로 처리하여 블록 사이 거리를 충분히 줄이는 것.
	m이 최대 20만이므로 넉넉잡아 절대 전처리 후의 n이 100만을 넘지 못함.
	이후 dp를 돌려 각 블록의 위치에 대한 다음 블록이 완성될 수 있는지를 체크함.
	틀린 이유는 잘 모르겠음..

	정해: 한 블록이 나오면 이 블록에 의해 깨진 블록 공간을 다시 제대로 맞춰줄 다음블록이 있는지 체크하는 것.
	만약 다음 블록이 이 블록과 맞물려 해결될 수 있다면 다음 블록 2개짝으로 넘어가고, 아니라면 틀린 것.
			
	해결될 수 있는 경우 : 두개가 서로 다른 높이에서 거리차가 짝수이거나, 서로 같은 높이에서 거리차가 홀수
	단, 블록을 2개씩 체크하므로 이번 첫블록과 지난 두번째블록 사이가 충돌하는 경우도 고려해줘야함!!
	이건 두 블록이 서로 같은 x좌표에 위치할때 발생.

	풀이 분기점: 큰 문제를 작은 문제로 분해해서 보기? 
	특히나 이 문제처럼 2 X N이면 분해해서 보기 쉬우니까 다양한 경우를 관찰할 필요가 있었던 것 같음..
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pii;
int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<pii> p;
		for(int i = 0; i < m; i++) {
			int r, c;
			cin >> r >> c;
			p.push_back({c, r});
		}
		sort(p.begin(), p.end());
		// x좌표 순으로 정렬. 여기까지는 당연한 전처리.

		// 블록이 홀수개면 절대 못채움.
		if(m % 2) { // 이걸 m & 1로도 표현함.. 홀수면 맨끝이 1이니까.
			cout << "NO\n";
			continue;
		}

		// 블록이 짝수인 것이 보장되면 for문 이렇게 해도 됨.
		bool ans = true;
		for(int i = 0; i < m; i += 2) {
			// 높이가 같은가? ^ 거리차 짝수인가?
			ans = (p[i].y == p[i + 1].y) ^ ((p[i + 1].x - p[i].x) % 2 == 0);
			if(!ans)
				break;
			// 이전 블럭과 겹쳐있는가?
			if(i > 0)
				ans = !(p[i - 1].x == p[i].x);
			if(!ans)
				break;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
}