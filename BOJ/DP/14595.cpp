//동방 프로젝트(Large)
//Dynamic programming, prefix sum, sweeping
/*
 결국 남아있는 방의 개수라는 것은 (남아있는 벽의 수 + 1) 과 같다.
 현재 1~n번 방 사이사이를 연결하는 n-1개의 벽이 있고, a~b번 방을 합친다는 말은 방a ~ 방b-1 을 없앤다는 말과 같다.
 따라서, (a,b)로 들어오는 쿼리에 대해 p[a]--, p[b]++을 해주고, 마지막에 부분합 스위핑을 진행하며 값이 0이상인, 즉 지워진 적이 없는 벽의 개수만 세어준다.
*/

#include <iostream>
using namespace std;

int n, m;
int p[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int ans = 0;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		p[a]--;
		p[b]++;
	}
	for (int i = 1; i < n; i++) {
		p[i] += p[i - 1];
		if (p[i] >= 0) ans++;
	}
	cout << ans + 1;
}
