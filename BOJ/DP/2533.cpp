//사회망 서비스
//TreeDP

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define pb push_back
#define ll long long
#define MAX 

using namespace std;

int n, u, v;
vector<int> adj[1000001];
int dp[2][1000001], par[1000001], vis[1000001];

int go(int mode, int u) {
	if (dp[mode][u] >= 0) return dp[mode][u];
	int res = 0;
	if (mode == 1) {
		for (int v : adj[u]) {
			if (par[u] == v) continue;
			res += min(go(0, v), go(1, v));
		}
		return dp[mode][u] = res + 1;
	}
	else {
		for (int v : adj[u]) {
			if (par[u] == v) continue;
			res += go(1, v);
		}
		return dp[mode][u] = res;
	}
}
void make_par() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 1;
		for (int v : adj[u]) {
			if (vis[v]) continue;
			par[v] = u;
			q.push(v);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	make_par();
	cout << min(go(1, 1), go(0, 1));
}
