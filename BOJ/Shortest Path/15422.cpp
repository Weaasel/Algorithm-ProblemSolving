// Bumped!
// Dijkstra with 2-layer

/*
  그래프와 source, destination vertex가 주어진다.
  source to destination 까지의 최단 경로를 구하는 문제이기 때문에 dijkstra algorithm을 떠올릴 수 있다.
  
  한가지 특징은, cost가 0 인 비행기 경로들 중에 한 번은 이용할 수 있다는 점이다.
  이 조건 때문에 dist배열을 2차원으로 잡고 flight 이용여부에 따라 각 vertex까지의 거리를 따로 저장했다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 1e15
using namespace std;

int n, m, f, s, t, u, v, c;

ll dist[2][50001];
vector<pii> adj[50001];
vector<int> fadj[50001];

void dijkstra(int s) {
	priority_queue<pair<ll, pll>> pq;
	dist[0][s] = 0;
	for (pii p : adj[s]) {
		pq.push({ -p.second, {p.first, 0} });
		dist[0][p.first] = p.second;
	}
	for (int v : fadj[s]) {
		pq.push({ 0, {v, 1} });
		dist[1][v] = 0;
	}
	while (!pq.empty()) {
		auto tmp = pq.top(); pq.pop();
		ll cur = tmp.second.first, f = tmp.second.second;
		ll d = -tmp.first;
		if (dist[f][cur] < d) continue;
		if (!f) {
			for (int v : fadj[cur]) {
				int nxt = v, w = 0;
				if (dist[f + 1][nxt] > d + w) {
					dist[f + 1][nxt] = d + w;
					pq.push({ -dist[f + 1][nxt],{ nxt,f + 1} });
				}
			}
		}
		for (auto p : adj[cur]) {
			int nxt = p.first, w = p.second;
			if (dist[f][nxt] > d + w) {
				dist[f][nxt] = d + w;
				pq.push({ -dist[f][nxt],{ nxt,f } });
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> m >> f >> s >> t;
	for (int i = 0; i < 2; i++) for (int j = 0; j <= n; j++) dist[i][j] = INF;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });
	}
	for (int i = 0; i < f; i++) {
		cin >> u >> v;
		fadj[u].push_back(v);
	}
	dijkstra(s);
	cout << min(dist[0][t], dist[1][t]);
	return 0;
}
