//집 구하기
//dijkstra
/*
  dijkstra 알고리즘을 이용해 최단거리를 구하는 전형적인 문제이다.
  단지 여러 점에서부터 출발한다는 것, 그리고 두 가지 종류의 점에 대해 계산해야 한다는 점 때문에 구현이 조금 귀찮다.
    1. fill 할 때 V index까지 채우려면 V + 1 로 대입해야 하는 점,
    2. 최소거리 정점 번호가 아닌 최소거리를 출력해야 하는 점
  이 두 가지에 대한 실수로 많이 틀렸다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int V, E, M, x, S, y, u, v, w;
vector<pii> adj[10001];
priority_queue<pii> mpq, spq;
bool ismc[10001], isstar[10001];
int mdist[10001], sdist[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	fill(mdist, mdist + V + 1, INF);
	fill(sdist, sdist + V + 1, INF);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].pb({ v,w });
		adj[v].pb({ u,w });
	}
	cin >> M >> x;
	for (int i = 0; i < M; i++) {
		cin >> u;
		ismc[u] = true;
		mdist[u] = 0;
		mpq.push({ 0,u });
	}
	cin >> S >> y;
	for (int i = 0; i < S; i++) {
		cin >> u;
		isstar[u] = true;
		sdist[u] = 0;
		spq.push({ 0,u });
	}
	while (!mpq.empty()) {
		pii p = mpq.top(); mpq.pop();
		int cur = p.second, d = -p.first;
		for (pii np : adj[cur]) {
			int nxt = np.first, w = np.second;
			if (mdist[nxt] > d + w) {
				mdist[nxt] = d + w;
				mpq.push({ -(d + w), nxt });
			}
		}
	}
	while (!spq.empty()) {
		pii p = spq.top(); spq.pop();
		int cur = p.second, d = -p.first;
		for (pii np : adj[cur]) {
			int nxt = np.first, w = np.second;
			if (sdist[nxt] > d + w) {
				sdist[nxt] = d + w;
				spq.push({ -(d + w), nxt });
			}
		}
	}
	int mn = (INF) * 2;
	for (int i = 1; i <= V; i++) {
		if (ismc[i] || isstar[i]) continue;
		if (mdist[i] > x || sdist[i] > y) continue;
		mn = min(mn, mdist[i] + sdist[i]);
	}
	mn == (INF)*2 ? cout<< -1 : cout << mn;
	return 0;
}
