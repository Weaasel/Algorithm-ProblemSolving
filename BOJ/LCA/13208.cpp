//승현이와 승현이
//LCA, MST, Disjoint Set

/*
  정점의 개수가 500개 제한, 한 턴에 한 명씩만 움직일 수 있다는 조건이 유효하다.
  이 조건을 통해 두 사람의 위치 (u, v)를 하나의 node로 보고 이 state간의 이동을 edge로 볼 수 있게 된다.
*/

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

int n, m, q, u, v, c, s, e;
int C[501];
int pre[250001][21], mx_e[250001][21], lv[250001];
vector<pii> adj[250001];
vector<pair<int, pii>> pre_adj;
vector<int> raw_adj[501];

int par[250001];

int idx(int r, int c) {
	return (r-1) * n + c;
}

int unionfind(int a) {
	if (par[a] < 0) return a;
	return par[a] = unionfind(par[a]);
}

bool unioning(int a, int b) {
	a = unionfind(a);
	b = unionfind(b);
	if (a == b) return false;
	par[a] += par[b];
	par[b] = a;
	return true;
}

void make_tree(int u) {
	for (pii pv : adj[u]) {
		int v = pv.first;
		if (lv[v] > 0) continue;
		pre[v][0] = u;
		mx_e[v][0] = pv.second;
		lv[v] = lv[u] + 1;
		make_tree(v);
	}
}

void init_pre() {
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n * n; j++) {
			pre[j][i] = pre[pre[j][i - 1]][i - 1];
			mx_e[j][i] = max(mx_e[j][i - 1], mx_e[pre[j][i - 1]][i - 1]);
		}
	}
}

int lca(int u, int v) {
	int res = 0;
	if (lv[u] > lv[v]) swap(u, v);

	for (int i = 20; i >= 0; i--) {
		if (lv[v] - lv[u] < (1 << i)) continue;
		res = max(res, mx_e[v][i]);
		v = pre[v][i];
	}
	if (u == v) return res;
	for (int i = 20; i >= 0; i--) {
		if (pre[u][i] == pre[v][i]) continue;
		res = max({ res, mx_e[u][i], mx_e[v][i] });
		u = pre[u][i]; v = pre[v][i];
	}
	return max({ res, mx_e[u][0], mx_e[v][0] });;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		raw_adj[u].pb(v); raw_adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			u = idx(i, j);
			for (int ni : raw_adj[i]) {
				v = idx(ni, j);
				pre_adj.pb({ max(C[i] * C[j], C[ni] * C[j]), { u,v } });
			}
			for (int nj : raw_adj[j]) {
				v = idx(i, nj);
				pre_adj.pb({ max(C[i] * C[j], C[i] * C[nj]), { u,v } });
			}
		}
	}

	//sort adj by its cost
	sort(pre_adj.begin(), pre_adj.end());

	//make MST
	memset(par, -1, sizeof(par));
	for (int i = 0; i < pre_adj.size(); i++) {
		pii uv = pre_adj[i].second;
		u = uv.first, v = uv.second, c = pre_adj[i].first;
		if (unioning(u, v)) {
			adj[u].pb({ v, c }); adj[v].pb({ u, c });
		}
	}

	lv[1] = 1;
	make_tree(1);
	init_pre();

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> s >> e;
		cout << lca(idx(s, e), idx(e, s)) << "\n";
	}

	return 0;
}
