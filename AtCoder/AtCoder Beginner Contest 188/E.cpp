//E - Peddler	
//dfs, dynamic programming
/*
  mx[u]: u-rooted subtree에서의 최대값.
  u에서 사서 u를 제외한 mx[u]에 판다!
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
const int INF = 2e9;
using namespace std;

ll n, m, res = -INF;
ll mx[202020], r[202020];
vector<int> adj[202020];

void dfs(int u, int prv = 0) {
	if (r[u] > -INF) return;
	ll cmx = -INF;
	for (int v : adj[u]) {
		if (v == prv) continue;
		dfs(v, u);
		cmx = max(cmx, mx[v]);
	}
	r[u] = cmx - mx[u];
	mx[u] = max(mx[u], cmx);
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> mx[i];
		r[i] = -INF;
	}
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
	}
	for (int i = 1; i <= n; i++) dfs(i);
	for (int i = 1; i <= n; i++) res = max(res, r[i]);
	cout << res;

	return 0;
}
