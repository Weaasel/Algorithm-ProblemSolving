/*
  By Kőnig's theorem, |max matching| = |minimum vertex cover|
  
  mvc에 포함되는 vertex들을 구하는 방법은,
    1. A집합에서 matching에 포함되지 않은 vertex를 X에 넣는다.
    2. alternating path를 타고 X를 키운다. (여기서 alternating path란, B->A로 갈 때는 matching에 포함된 edge만을 이용한다.)
    3. mvc = (A-X) U (B intersect X) 이다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;

int n, m, t;
vector<int> adj[2001];
int A[1001], B[2001], vis[2001];

bool dfs(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj[u]) {
		if (B[v] == -1 || dfs(B[v])) {
			B[v] = u;
			A[u] = v;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		while (t--) {
			int j;
			cin >> j;
			adj[i].pb(1000 + j);
			adj[1000 + j].pb(i);
		}
	}

	int cnt = 0;
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			memset(vis, false, sizeof(vis));
			if (dfs(i)) cnt++;
		}
	}
	memset(vis, false, sizeof(vis));
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = true;
		for (int v : adj[u]) {
			if (B[v] == -1 || vis[v]) continue;
			if (vis[B[v]]) continue;
			vis[v] = true;
			q.push(B[v]);
		}
	}
	vector<int> resA, resB;
	for (int i = 1; i <= n; i++) if (!vis[i]) resA.pb(i);
	for (int i = 1001; i <= 1000 + m; i++) if (vis[i]) resB.pb(i-1000);
  return 0;
}
