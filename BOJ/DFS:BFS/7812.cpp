//중앙 트리
//dfs, tree
/*
  모든 정점에 대해 해당 정점과 다른 모든 정점들 사이의 거리의 합을 구해야 한다.
  root에서부터 퍼뜨린다.
  u: parent
  v: child 일 때 res[child] = res[parent] + (n-2*subs[child]) * w 가 된다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
const ll INF = 1e18 + 7;

using namespace std;

ll n, subs[10101], a[10101];
vector<pll> adj[10101];

ll dfs(int u, int prv) {
	subs[u] = 1;
	ll ret = 0;
	for (auto p : adj[u]) {
		if (p.first == prv) continue;
		ret += dfs(p.first, u);
		ret += p.second*subs[p.first];
		subs[u] += subs[p.first];
	}
	return ret;
}

void go(int u, int prv, ll c) {
	a[u] = a[prv] + (n - subs[u] * 2) * c;
	for (auto p : adj[u]) {
		if (p.first == prv) continue;
		go(p.first, u, p.second);
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			subs[i] = 0, a[i] = 0, adj[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v, w; cin >> u >> v >> w;
			adj[u].pb({ v,w });
			adj[v].pb({ u,w });
		}
		a[0] = dfs(0, -1);
		for (auto p : adj[0]) go(p.first, 0, p.second);
		ll res = INF;
		for (int i = 0; i < n; i++) res = min(res, a[i]);
		cout << res << "\n";
	}

	return 0;
}
