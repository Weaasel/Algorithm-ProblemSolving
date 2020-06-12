//플로이드
//shortest path, floyd warshall
/*
  정석적인 플로이드 와샬 해법으로 풀린다.
  vertex의 개수가 100개라, dijkstra * 100번으로 풀어도 될 것 같다.
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
const ll INF = 1e9;

using namespace std;

int n, m, u, v, c, cost[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cost[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		cost[u][v] = min(cost[u][v], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == INF) cout << "0 ";
			else cout << cost[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
