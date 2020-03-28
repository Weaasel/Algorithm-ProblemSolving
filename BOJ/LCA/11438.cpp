//LCA2
//mlogn code for LCA algorithm

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

int n, m, u, v;
int pre[100001][21], lv[100001];
vector<int> adj[100001];

void make_tree(int u) {
	for (int v : adj[u]) {
		if (lv[v] > 0) continue;
		pre[v][0] = u;
		lv[v] = lv[u] + 1;
		make_tree(v);
	}
}

void init_pre() {
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n; j++) {
			pre[j][i] = pre[pre[j][i - 1]][i - 1];
		}
	}
}

int lca(int u, int v) {
	if (lv[u] > lv[v]) swap(u, v);

	for (int i = 20; i >= 0; i--) {
		if (lv[v] - lv[u] < (1 << i)) continue;
		v = pre[v][i];
	}
	if (u == v) return u;
	for (int i = 20; i >= 0; i--) {
		if (pre[u][i] == pre[v][i]) continue;
		u = pre[u][i]; v = pre[v][i];
	}
	return pre[u][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
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
