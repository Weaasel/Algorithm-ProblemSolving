//도로 네트워크
//LCA

#include <iostream>
#include <cstdio>
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
#define INF 2000000000

using namespace std;

int n, m, u, v, c, r, res, tmp;
int pre[100001][18], mx_e[100001][18], mn_e[100001][18], lv[100001];
vector<pii> adj[100001];

void make_tree(int u) {
	for (pii pv : adj[u]) {
		int v = pv.first;
		if (lv[v] > 0) continue;

		pre[v][0] = u;
		mx_e[v][0] = pv.second;
		mn_e[v][0] = pv.second;

		lv[v] = lv[u] + 1;
		make_tree(v);
	}
}

void init_pre() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 18; j++) {
			mn_e[i][j] = INF;
		}
	}
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			pre[j][i] = pre[pre[j][i - 1]][i - 1];
			mx_e[j][i] = max(mx_e[j][i - 1], mx_e[pre[j][i - 1]][i - 1]);
			mn_e[j][i] = min(mn_e[j][i - 1], mn_e[pre[j][i - 1]][i - 1]);
		}
	}
}

pii lca(int u, int v) {
	int res_mn = INF, res_mx = 0;
	if (lv[u] > lv[v]) swap(u, v);

	for (int i = 17; i >= 0; i--) {
		if (lv[v] - lv[u] < (1 << i)) continue;
		res_mn = min(res_mn, mn_e[v][i]);
		res_mx = max(res_mx, mx_e[v][i]);
		v = pre[v][i];
	}
	if (u == v) return { res_mn, res_mx };
	for (int i = 17; i >= 0; i--) {
		if (pre[u][i] == pre[v][i]) continue;
		res_mn = min({ res_mn, mn_e[u][i], mn_e[v][i] });
		res_mx = max({ res_mx, mx_e[u][i], mx_e[v][i] });
		u = pre[u][i]; v = pre[v][i];
	}
	res_mn = min({ res_mn, mn_e[u][0], mn_e[v][0] });
	res_mx = max({res_mx, mx_e[u][0], mx_e[v][0]});
	return { res_mn, res_mx };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> c;
		adj[u].pb({ v,c }); adj[v].pb({ u,c });
	}
	lv[1] = 1;
	mx_e[1][0] = 0;
	mn_e[1][0] = INF;

	make_tree(1);
	init_pre();

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		pii ans = lca(u, v);
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
