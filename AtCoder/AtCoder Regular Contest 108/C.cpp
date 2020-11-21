//C - Keep Graph Connected

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

using namespace std;

int n, m, res[101010];
vector<pii> adj[101010];
bool chk[101010], vis[101010];

int par[101010];

int find(int u) {
	if (par[u] == 0) return u;
	return par[u] = find(par[u]);
}
bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[u] = v;
	return true;
}

void dfs(int u, int prv = 0) {
	vis[u] = true;
	for (pii p : adj[u]) {
		int nxt = p.first, c = p.second;
		if (nxt == prv) continue;
		if (vis[nxt]) continue;
		if (res[u] == c) 
			res[nxt] = (c + 1) % n + 1;
		else res[nxt] = c;
		vis[nxt] = true;
		dfs(nxt, u);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		if (merge(u, v)) {
			adj[u].pb({ v,c });
			adj[v].pb({ u,c });
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (par[i] == 0) cnt++;
	if (cnt > 1) return cout << "No", 0;

	//tree 만들면서 뒤에 애가 edge넘버 받게 해
	res[1] = 1;
	dfs(1);
		for (int i = 1; i <= n; i++)
		cout << res[i] << "\n";

	return 0;
}
