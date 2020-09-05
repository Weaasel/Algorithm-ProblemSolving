//Kosaraju
/*
  정방향 간선, 역방향 간선을 모두 저장한다.
  정방향 dfs한번으로 한 정점의 dfs가 끝날 때 stack에 넣는다.
  stack에서 하나씩 빼며 역방향 dfs를 진행하고, SCC의 representer가 될 정점으로 who배열에 기록해둔다.
  그 후 정방향 간선을 순회하며 Component representer끼리의 간선으로 다시한번 넣어준다.
  이 코드에서는 indegree가 0인 component의 개수를 구하므로 실제로 넣진 않고 deg에 업데이트만 다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define pb push_back
using namespace std;

int T, n, m, res;
vector<int> adj[100001], radj[100001];
stack<int> s;
bool vis1[100001], vis2[100001];
int deg[100001], who[100001];

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
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		init();
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
			for (int j : adj[i]) {
				if (who[i] != who[j]) deg[who[j]]++;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (who[i] == i && deg[i] == 0) res++;
		}
		cout << res<<"\n";
	}
	return 0;
}
