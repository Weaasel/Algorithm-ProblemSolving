//BAPC 2018 Preliminaries E. Eating Everything Efficiently
//DAG, DP, binary

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
#define INF 200000000000000000
#define MAX_SIZE 4000000

using namespace std;

int n, m, u, v;
double dp[500001], c[500001];

vector<int> adj[500001];

double go(int u) {
	if (dp[u] > -1) return dp[u];
	double ret = c[u];
	for (int v : adj[u]) {
		ret = max({ ret, go(v), c[u] + (double)0.5*go(v) });
	}

	return dp[u] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) cin >> c[i];

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
	}
	cout << fixed;
	cout.precision(7);
	cout << go(0);
}
