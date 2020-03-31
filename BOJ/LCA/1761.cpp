//정점들의 거리
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

int n, m, u, v, c;
int pre[40001][18], dist[40001][18], lv[40001];
vector<pii> adj[40001];

void make_tree(int u) {
	for (pii pv : adj[u]) {
		int v = pv.first;
		if (lv[v] > 0) continue;
		pre[v][0] = u;
		lv[v] = lv[u] + 1;
		dist[v][0] = pv.second;
		make_tree(v);
	}
}

void init_pre() {
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			pre[j][i] = pre[pre[j][i - 1]][i - 1];
			dist[j][i] = dist[j][i - 1] + dist[pre[j][i - 1]][i - 1];
		}
	}
}

int lca(int u, int v) {
	if (lv[u] > lv[v]) swap(u, v);
	
	int res = 0;

	for (int i = 17; i >= 0; i--) {
		if (lv[v] - lv[u] < (1 << i)) continue;
		res += dist[v][i];
		v = pre[v][i];
	}
	if (u == v) return res;
	for (int i = 17; i >= 0; i--) {
		if (pre[u][i] == pre[v][i]) continue;
		res += dist[u][i] + dist[v][i];
		u = pre[u][i]; v = pre[v][i];
	}
	return res + dist[u][0] + dist[v][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> c;
		adj[u].pb({ v, c }); adj[v].pb({ u, c });
	}
	dist[1][0] = 0;
	lv[1] = 1;
	make_tree(1);
	init_pre();

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cout << lca(u, v) << "\n";
	}
	return 0;
}
