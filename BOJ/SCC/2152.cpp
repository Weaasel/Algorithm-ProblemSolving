//여행계획 세우기
//SCC, DAG dp
/*
  SCC를 구성해두고 S->T 로 향하는 DAG dp를 짜면 된다.
  child에서 여러 parent들을 거친 경로 중 하나를 선택하므로,
  dp[child] = max(dp[child], dp[parent] + SCC[child].size()) 라는 식을 세울 수 있다.
*/

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

const int mx = 10001;
int n, m, S, T;
vector<int> adj[mx], radj[mx], sadj[mx], sradj[mx];
stack<int> s;
bool vis1[mx], vis2[mx];
int deg[mx], who[mx], dp[mx];
vector<int> SCC[mx];

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

void sdfs(int u) {
	vis1[u] = true;
	for (int v : sadj[u]) {
		deg[v]++;
		if (!vis1[v]) sdfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> S >> T;
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

	for (int u = 1; u <= n; u++) {
		for (int v : adj[u]) {
			if (who[u] == who[v]) continue;
			sadj[who[u]].pb(who[v]);
		}
	}
	memset(vis1, false, sizeof vis1);
	sdfs(who[S]);

	queue<int> q;
	q.push(who[S]);
	dp[who[S]] = SCC[who[S]].size();
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : sadj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
			dp[nxt] = max(dp[nxt], dp[cur] + (int)SCC[who[nxt]].size());
		}
	}

	cout << dp[who[T]];
	return 0;
}
