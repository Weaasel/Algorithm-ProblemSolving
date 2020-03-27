//E. Tree Queries
//Tree, LCA, Greedy

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

int n, m, k, u, v;
int pre[200001][21];
vector<int> lv(200001, -1);
vector<int> adj[200001];

void make_tree() {
	queue<int> q;
	lv[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int par = q.front(); q.pop();
		for (int chl : adj[par]) {
			if (lv[chl] >= 0) continue;
			pre[chl][0] = par;
			lv[chl] = lv[par] + 1;
			q.push(chl);
		}
	}
	return;
}

void f() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			pre[i][j] = pre[pre[i][j - 1]][j - 1];
		}
	}
}

int lca(int x, int y) {
	if (lv[x] > lv[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i))
			y = pre[y][i];
	}
	if (x == y)return x;
	for (int i = 20; i >= 0; i--) {
		if (pre[x][i] != pre[y][i]) {
			x = pre[x][i];
			y = pre[y][i];
		}
	}
	return pre[x][0];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	lv[1] = 0;
	make_tree();
	f();

	for (int i = 0; i < m; i++) {
		cin >> k;
		vector<int> test(k);
		int leaf = 1;
		for (int j = 0; j < k; j++) {
			cin >> test[j];
			if (lv[test[j]] > lv[leaf]) leaf = test[j];
		}

		int flg = 1;
		for (int j = 0; j < k; j++) {
			int cur_lca = lca(leaf, test[j]);
			if (lv[test[j]] - lv[cur_lca] <= 1) continue;
			else flg = 0;
		}
		if (flg) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
