//Strongly Connected Component
//SCC, Kosaraju's

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int T, n, m, res;
vector<int> adj[100001], radj[100001];
stack<int> s;
bool vis1[100001], vis2[100001];
int deg[100001], who[100001];
vector<vector<int>> scc;
vector<int> SCC[10101];

void dfs1(int u) {
	vis1[u] = true;
	for (int v : adj[u])
		if (!vis1[v]) dfs1(v);
	s.push(u);
}

void dfs2(int u, int rep) {
	vis2[u] = true;
	who[u] = rep;
	SCC[rep].pb(u);
	for (int v : radj[u])
		if (!vis2[v]) dfs2(v, rep);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		radj[v].pb(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis1[i]) dfs1(i);
	while (!s.empty()) {
		int u = s.top(); s.pop();
		if (!vis2[u]) dfs2(u, u);
	}
	for (int i = 1; i <= n; i++) {
		if (who[i] != i) continue;
		sort(all(SCC[i]));
		scc.pb(SCC[i]);
	}
	sort(all(scc));
	cout << scc.size() << "\n";
	for (auto s : scc) {
		for (int u : s) cout << u << " ";
		cout << "-1\n";
	}
	
	return 0;
}
