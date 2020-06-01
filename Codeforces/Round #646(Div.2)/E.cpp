//E - Tree Shuffling
/*
  
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 1e9

using namespace std;

ll a[200001], b[200001], c[200001];
vector<int> adj[200001];
int n, u, v, f[200001][2];
bool vis[200001];

void dfs1(int u, int prev, ll preva) {
	if (b[u] != c[u]) {
		if (b[u] == 0) f[u][0] = 1;
		else f[u][1] = 1;
	}
	vis[u] = true;
	preva = min(preva, a[u]);
	a[u] = preva;
	for (int v : adj[u]) {
		if (vis[v] || v == prev) continue;
		dfs1(v, u, preva);
		f[u][0] += f[v][0];
		f[u][1] += f[v][1];
	}
	return;
}

ll solve(int u, int prev){
	ll res = 0, l = 0, r = 0;
	for (int v : adj[u]) {
		if (v == prev) continue;
		res += solve(v, u);
		if (f[v][0] > f[v][1]) l += f[v][0] - f[v][1];
		else r += f[v][1] - f[v][0];
	}
	if (b[u] != c[u]) {
		if (b[u] == 0)l++;
		else r++;
	}
	res += 2LL*min(l, r)*a[u];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(vis, false, sizeof(vis));
	dfs1(1, -1, a[1]);
	if (f[1][0] != f[1][1]) cout << -1;
	else cout << solve(1, -1);
	return 0;
}
