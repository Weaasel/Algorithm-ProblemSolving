//트리의 지름
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define DIV 1000000007LL
using namespace std;
using pii = pair<int, int>;

int n, u, v, c, midx;
int dist[10010];
vector<pii> adj[10010];

void bfs(int s) {
	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (pii p : adj[v]) {
			if (dist[p.first] > -1) continue;
			dist[p.first] = dist[v] + p.second;
			q.push(p.first);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({ u, c });
	}
	bfs(1);

	for (int i = 1; i <= n; i++) {
		if (dist[i] > dist[midx]) midx = i;
	}
	bfs(midx);

	midx = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > dist[midx]) midx = i;
	}
	cout << dist[midx];
	return 0;
}
