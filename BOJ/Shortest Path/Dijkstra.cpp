#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>

const int INF = 1e9+7;

using namespace std;

int n, m, s;
int dist[20202];
vector<pii> adj[20202];

void dijkstra(int s) {
	dist[s] = 0;
	priority_queue<pii> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int cur = p.second, curd = -p.first;
		if (dist[cur] < curd) continue;
		for (pii np : adj[cur]) {
			int nxt = np.first, d = np.second;
			if (dist[nxt] <= curd + d) continue;
			dist[nxt] = curd + d;
			pq.push({ -dist[nxt],nxt });
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> s;
	fill(dist+1, dist + n + 1, INF);

	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({ v,c });
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}
