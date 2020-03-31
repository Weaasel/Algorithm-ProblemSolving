//게임 개발
//DFS, DAG, dp, topological sort

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
#define MAX 
#define DIV 1000000
#define INF 2000000000

using namespace std;

int n, m, dp[501], t[501];
vector<int> adj[501];

int go(int u) {
	if (dp[u] > 0) return dp[u];
	int res = t[u], ext = 0;
	for (int v : adj[u]) {
		ext = max(ext, go(v));
	}
	return dp[u] = res + ext;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		while (1) {
			cin >> m;
			if (m == -1) break;
			adj[i].pb(m);
		}
	}

	for (int i = 1; i <= n; i++) cout << go(i) << "\n";
	
	return 0;
}
