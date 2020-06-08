//지하철
//dijkstra
/*
  지하철을 이용해 최소환승/최소비용으로 도착지에 도달하고 싶다.
  
  다익스트라 알고리즘을 이용해 목적지까지의 최소비용을 구한다.
  비용이 크더라도 최소환승을 한 길을 택해야 한다.
  따라서 dist 배열을 2차원으로 해야 한다?
  -> 환승비용 = 비용의 최대값 으로 설정한다. (1,000,000)
  이러면 1차원으로 dist를 표현 가능하다.
  마지막에 환승횟수 = dist/1,000,000, 교통비용 = dist % 1,000,000 으로 decoding 가능하다.
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
#define DIV 1000000007;
#define INF 2e9

using namespace std;

int n, m, a[1001], adj[1001][1001];
int dist[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	fill(dist, dist + n, INF);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	priority_queue<pii> pq; //{cost, num}, edge 최대 1000,000 임.
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int d = -p.first, cur = p.second;
		if (d > dist[cur]) continue;
		dist[cur] = d;
		for (int i = 0; i < n; i++) {
			if (adj[cur][i] == 0) continue;
			int newd = d + adj[cur][i];
			if (a[cur] != a[i]) newd += 1000000;
			if (newd < dist[i]) {
				pq.push({ -newd, i });
			}
		}
	}
	int d = dist[m];
	cout << dist[m] / 1000000 << " " << dist[m] % 1000000;
	return 0;
}
