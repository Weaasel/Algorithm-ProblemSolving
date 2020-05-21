//노트북의 주인을 찾아서
//이분매칭
/*
  simple bipartite matching
*/

#include <iostream>
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
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2e18
#define base 100000
using namespace std;

int n, m, a, b, res, A[101], B[101], vis[101];
vector<int> adj[101];

bool dfs(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj[u]) {
		if (B[v] == 0 || dfs(B[v])) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].pb(b);
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));
		if (dfs(i)) res++;
	}
	cout << res;
	return 0;
}
