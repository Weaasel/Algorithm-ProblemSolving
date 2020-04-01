//Mountaineers
//LCA, MST, Kruskal

/*
  인접한 정점 u, v 사이의 edge cost는 max(height[u], height[v]) 로 결정된다.
  
  이 edge들을 가지고 MST를 만들었을 때 모든 u,v 쌍에 대해 max edge cost를 minimize 할 수 있다는 것을 증명할 수 있다.
    귀류법. if another path exists: MST를 만들 때 그 edge가 먼저 포함되었어야 함.
  
  주의할 점은 출발점과 도착점이 같은 경우에 자기 자신의 높이를 출력해야 한다는 점이다.
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

int n, m, q, u, v, c, a1, b1, a2, b2;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}, h[501][501];
int pre[250001][21], mx_e[250001][21], lv[250001];
vector<pii> adj[250001];
vector<pair<int, pii>> raw_adj;

int par[250001];

int idx(int r, int c) {
	return r * m + c + 1;
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
		for (int j = 1; j <= n * m; j++) {
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
		res = max(res, mx_e[u][i]);
		res = max(res, mx_e[v][i]);
		u = pre[u][i]; v = pre[v][i];
	}
	return max({ res, mx_e[u][0], mx_e[v][0] });;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> h[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			u = idx(i, j);
			for (int k = 0; k < 4; k++) {
				v = idx(i + dx[k], j + dy[k]);

				if (i + dx[k] < 0 || i + dx[k] >= n) continue;
				if (j + dy[k] < 0 || j + dy[k] >= m) continue;

				raw_adj.pb({ max(h[i][j], h[i + dx[k]][j + dy[k]]), { u, v } });
			}
		}
	}

	//sort adj by its cost
	sort(raw_adj.begin(), raw_adj.end());

	//make MST
	memset(par, -1, sizeof(par));
	for (int i = 0; i < raw_adj.size(); i++) {
		pii uv = raw_adj[i].second;
		u = uv.first, v = uv.second, c = raw_adj[i].first;
		if (unioning(u, v)) {
			adj[u].pb({ v, c }); adj[v].pb({ u, c });
		}
	}

	lv[1] = 1;
	make_tree(1);
	init_pre();

	for (int i = 0; i < q; i++) {
		cin >> a1 >> b1 >> a2 >> b2;
		if (a1 == a2 && b1 == b2) cout << h[a1 - 1][b1 - 1] << "\n";
		else cout << lca(idx(a1 - 1, b1 - 1), idx(a2 - 1, b2 - 1)) << "\n";
	}

	return 0;
}
