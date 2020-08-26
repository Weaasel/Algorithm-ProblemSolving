//BAPC 2016 Preliminaries I - Rock Band
//dfs

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
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int m, s, u, v, a;

vector<int> f[1000001];
vector<int> adj[1000001];
bool vis[1000001];
vector<int> res;

void dfs(int u) {
	if (vis[u]) return;
	vis[u] = true;
	res.pb(u);
	for (int v : adj[u]) {
		dfs(v);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> s;

	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= s; j++) {
			cin >> a;
			f[i].pb(a);
			if (j > 1) adj[f[i][j - 1]].pb(f[i][j - 2]);
		}
	}

	for (int i = 0; i < m; i++) {
		dfs(f[i][0]);
	}

	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int u : res) cout << u << " ";

	return 0;
}
