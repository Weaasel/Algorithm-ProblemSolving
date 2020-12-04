//Cereal
//Ad-hoc
/*
  뒤에서부터 답을 만들어간다.
  새로운 소가 추가되었을 때 가장 선호하는 먹이를 먹을 수 있으면 주고 끝내면 된다. 이 때는 먹을 수 있는 소가 한마리 늘어난다.
  만약 이미 먹힌 상태라면 우선순위가 이번 소에 있으므로 먹이를 뺏어서 준다. 이 때 뺏긴 소가 두번째 선호하는 먹이를 먹을 수 있으면
  먹을 수 있는 소는 1마리 늘어난 것이고 아니라면 그대로일 것이다.
  뺏어서 주는 과정을 재귀적인 함수로 구현한다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
const int INF = 1e9 + 7;

int n, m;
int f[101010], s[101010], a[101010];
int res[101010], r;

int go(int cow, int meal) {
	int nxt = a[meal];
	a[meal] = cow;
	if (s[nxt] == meal) return 0;
	else {
		if (a[s[nxt]] == -1) {
			a[s[nxt]] = nxt;
			return 1;
		}
		else if (a[s[nxt]] < nxt) return 0;
		else return go(nxt, s[nxt]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(a, -1, sizeof(a));
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> f[i] >> s[i];
	for (int i = n - 1; i >= 0; i--) {
		if (a[f[i]] == -1) {
			a[f[i]] = i;
			r++;
		}
		else {
			r += go(i, f[i]);
		}
		res[i] = r;
	}

	for (int i = 0; i < n; i++) cout << res[i] << "\n";
	return 0;
}
