//레드 블루 스패닝 트리
//union find
/*
  정확히 k개의 blue 간선으로 스패닝 트리를 만들 수 있는 지 여부를 출력해야 한다.
  반대로, 어떨 때 만들 수 없을까?
  1. 무조건 k개보다 많은 blue 간선을 써야 하는 경우
    red 간선만으로 연결한 그래프의 컴포넌트 개수가 k+1개보다 크면 k개의 blue 간선으로 스패닝 트리를 만들 수 없다.
  2. 사이클 이슈로 k개의 blue 간선을 쓸 수 없는 경우
    blue 간선만으로 연결한 그래프의 컴포넌트 개수가 n-k개보다 큰 경우 (k개 미만의 간선이 쓰였다는 뜻이다.)
  남은 것은 구현.
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define pb push_back
using namespace std;

int n, m, k, rcnt, bcnt;
int par[1010];
vector<pii> R, B;

int find(int u) {
	if (par[u] < 0) return u;
	return par[u] = find(par[u]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	while (1) {
		memset(par, -1, sizeof(par));
		R.clear(); B.clear();
		rcnt = 0, bcnt = 0;

		cin >> n >> m >> k;
		if (!n && !m && !k) break;
		for (int i = 0; i < m; i++) {
			char c; int u, v; cin >> c >> u >> v;
			if (c == 'R') R.pb({ u,v });
			else B.pb({ u,v });
		}
		for (pii p : R) merge(p.x, p.y);
		for (int i = 1; i <= n; i++) if (par[i] < 0) rcnt++;
		memset(par, -1, sizeof(par));
		for (pii p : B) merge(p.x, p.y);
		for (int i = 1; i <= n; i++) if (par[i] < 0) bcnt++;
		if (rcnt > k + 1 || bcnt > n - k) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}
