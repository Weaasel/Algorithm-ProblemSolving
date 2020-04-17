//PPC 2019 - Pineapple Advertising

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

int n, m, q, u, v;
vector<int> adj[200001];
bool chk[200001];
bool vis[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 0; i < q; i++) {
		cin >> u;
		if (chk[u]) {
			cout << "0\n";
			continue;
		}
		int res = 0;
		chk[u] = true;
		for (int v : adj[u]) {
			if (vis[v]) continue;
			res++;
			vis[v] = true;
		}
		if (!vis[u]) {
			vis[u] = true;
			res++;
		}
		cout << res << "\n";
	}

	return 0;
}
