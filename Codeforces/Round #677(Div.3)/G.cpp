//G - Reducing Delivery Cost	
//Shortest Path, Greedy
/*
  어떤 edge(a -- b)의 cost를 0으로 만들었다고 가정하자.
  두 점 u, v 간의 최단경로 d[u][v]는 다음과 같이 수정된다.
    d[u][v] = min(d[u][v], d[u][a] + d[b][v], d[u][b] + d[a][v])
    (기존경로를 그대로 사용하는 경우, a--b 엣지를 이용하는 경우이다.)
    
  이것을 관찰하면 최초에 모든 d[u][v]들을 초기화해 두고, -> 모든 점에 대해 dijkstra algorithm을 사용
  한 edge씩 0으로 만들어보는 시뮬레이션을 O(k)에 할 수 있다.
  전체 시간복잡도는 O(nmlogn + mk) 가 된다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e18

using namespace std;

ll T, n, m, k;
ll res, d[1001][1001];
vector<pll> adj[1001];
vector<pii> q;

void init() {
	res = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			d[i][j] = INF;
		}
	}
}

void dijk(ll st) {
	priority_queue<pll> pq;
	pq.push({ st,0 });
	while (!pq.empty()) {
		pll cur = pq.top(); pq.pop();
		int now = cur.first;
		ll curd = -cur.second;
		for (auto next : adj[now]) {
			int nxt = next.first;
			if (d[st][nxt] > curd + next.second) {
				d[st][nxt] = curd + next.second;
				pq.push({ nxt, -d[st][nxt] });
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> k;
	init();
	for (int i = 0; i < m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].pb({ v,c });
		adj[v].pb({ u,c });
	}
	for (int i = 0; i < k; i++) {
		int u, v; cin >> u >> v;
		q.pb({ u,v });
	}
	for (int i = 1; i <= n; i++) dijk(i);

	for (int u = 1; u <= n; u++) {
		for (pll p : adj[u]) {
			ll tmp = 0;
			int v = p.first;
			for (pii qq : q) {
				int s = qq.first, e = qq.second;
				tmp += min({ d[s][e], d[s][u] + d[v][e], d[s][v] + d[u][e] });
			}
			res = min(res, tmp);
		}
	}
	cout << res;
	return 0;
}
