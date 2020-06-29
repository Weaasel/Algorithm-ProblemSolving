//소가 길을 건너간 이유 7
//dijkstra
/*
  3칸씩 건널 때 마다 거리가 갱신되기 때문에,
  그래프의 연결관계 자체를 3번 이동한 점과의 관계로 이어버린다.
  그리고 다익스트라를 돌려서 각 점으로의 최단거리를 계산한다.
  마지막에는 (n,n)으로부터 거리 2 이하인 점들로부터 받아오는 최단거리들을 비교해야 한다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+15
const ll DIV = 1e9 + 7;
using namespace std;

ll n, t;
ll a[101][101], dist[101][101];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			dist[i][j] = INF;
		}
	}
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	priority_queue<pair<ll, pll>> pq;
	dist[1][1] = 0;
	pq.push({ 0, {1, 1} });
	while (!pq.empty()) {
		pair<ll, pll> p = pq.top(); pq.pop();
		pll xy = p.second; ll d = -p.first;
		ll r = xy.first, c = xy.second;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					ll dxx = dx[i] + dx[j] + dx[k], dyy = dy[i] + dy[j] + dy[k];
					ll nr = r + dxx, nc = c + dyy;
					if (nr<1 || nr>n) continue;
					if (nc<1 || nc>n) continue;
					if (dist[nr][nc] > d + a[nr][nc] + 3 * t) {
						dist[nr][nc] = d + a[nr][nc] + 3 * t;
						pq.push({ -dist[nr][nc], {nr, nc} });
					}
				}
			}
		}
	}
	ll res = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (abs(n - i) + abs(n - j) > 2) continue;
			res = min(res, dist[i][j] + t * (abs(n - i) + abs(n - j)));
		}
	}
	cout << res;
	return 0;
}
