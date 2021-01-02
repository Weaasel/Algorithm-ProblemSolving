//I번은 쉬운 문제
//SCC, dfs
/*
  주어진 그래프에서 최소한의 정점을 시작으로 순회하여 모든 정점을 커버해야 하는 문제이다. 모든 정점을 scc로 묶고 DAG 그래프로 만든 상태에서
  indegree == 0인 정점의 개수가 최소한으로 필요한 개수이다.
  그리고 주어진 t[i]들 중 각 root scc에 속하는 정점이 적어도 1개 이상 존재해야 한다.
  이는 모든 t[i]들을 기준으로 dfs를 해서 전체가 커버되는지 확인하면 해결된다.
*/

#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const int INF = 1e9 + 7;
using namespace std;
//getline(cin, s);

int T, n, m, res, t[202020];
vector<int> adj[202020], radj[202020];
stack<int> s;
bool vis[202020], vis1[202020], vis2[202020];
int deg[202020], who[202020];
bool flg;

void init() {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		radj[i].clear();
		vis1[i] = false;
		vis2[i] = false;
		deg[i] = 0;
		res = 0;
	}
}

void dfs(int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v]) dfs(v);
	return;
}

void dfs1(int u) {
	vis1[u] = true;
	for (int v : adj[u])
		if (!vis1[v]) dfs1(v);
	s.push(u);
}

void dfs2(int u, int rep) {
	vis2[u] = true;
	who[u] = rep;
	for (int v : radj[u])
		if (!vis2[v]) dfs2(v, rep);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	init();

	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		radj[v].pb(u);
	}

	cin >> T;
	for (int i = 0; i < T; i++) cin >> t[i];
	for (int i = 0; i < T; i++) if (!vis[t[i]]) dfs(t[i]);
	for (int i = 1; i <= n; i++) if (!vis[i]) flg = true;

	for (int i = 1; i <= n; i++)
		if (!vis1[i]) dfs1(i);
	while (!s.empty()) {
		int u = s.top(); s.pop();
		if (!vis2[u]) dfs2(u, u);
	}

	for (int i = 1; i <= n; i++) {
		for (int j : adj[i]) {
			if (who[i] != who[j]) deg[who[j]]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (who[i] == i && deg[i] == 0) res++;
	}
	
	if (flg) cout << -1;
	else cout << res;
	return 0;
}
