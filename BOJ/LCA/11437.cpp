//LCA
//naive code for LCA algorithm

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
int pre[50001], lv[50001];
vector<int> adj[50001];

void make_tree(int u) {
	for (int v : adj[u]) {
		if (lv[v] > 0) continue;
		pre[v] = u;
		lv[v] = lv[u] + 1;
		make_tree(v);
	}
}

int lca(int u, int v) {
	if (lv[u] > lv[v]) swap(u, v);
	int dist = lv[v] - lv[u];
	for (int i = 0; i < dist; i++) {
		v = pre[v];
	}
	if (u == v) return u;
	while (u != v) {
		u = pre[u], v = pre[v];
	}
	return u;
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
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		cout << lca(u, v) << "\n";
	}
	return 0;
}

