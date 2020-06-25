//녹색 옷 입은 애가 젣다지?
//shortest path, dijkstra, 차원 줄이기
/*
  해당 점으로 가는 비용을 해당 점의 값이라고 하면, 0,0에서 n-1,n-1로 가는 최단거리를 구하는 문제가 된다.
  인접한 4개의 점과 자기자신간에 edge를 이어주고 vertex number도 부여한 다음 dijkstra를 진행한다.
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
#define INF 1e+9
const ll DIV = 1e9 + 7;
using namespace std;

int n, a[126][126], dist[17000], res,tc;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
int getidx(int r, int c) {
	return r*n + c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		tc++;
		cin >> n;
		if (n == 0) break;
		vector<pii> adj[17000];
		fill(dist, dist + 17000, INF);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni >= n) continue;
					if (nj < 0 || nj >= n) continue;
					adj[getidx(i, j)].pb({ getidx(ni,nj),a[ni][nj] });
				}
			}
		}
		dist[0] = a[0][0];
		priority_queue<pii> pq;
		pq.push({ -dist[0], 0 });
		while (!pq.empty()) {
			pii p = pq.top(); pq.pop();
			int cur = p.second, d = -p.first;
			for (pii np : adj[cur]) {
				int nxt = np.first, nxtd = np.second;
				if (dist[nxt] > d + nxtd) {
					dist[nxt] = d + nxtd;
					pq.push({ -(d + nxtd), nxt });
				}
			}
		}
		cout << "Problem " << tc << ": " << dist[getidx(n - 1, n - 1)] << "\n";
	}
	return 0;
}
