//Peaceful Rooks
//dfs, cycle check
/*
  룩의 위치가 (r,c)로 주어질 때, 이 룩을 한번의 이동으로 main diagonal 위에 올리려면 (r,r) 혹은 (c,c)로 이동시켜야 한다.
  그리고 (c, c')의 존재가 이를 막는다. 따라서 이런 룩들을 directed graph로 연결하면
  chain을 이루는 룩들을 순차적으로 이동시키는 것이 최적임을 알 수 있는데,
  cycle을 형성하는 경우에는 최소한 하나의 룩은 두 번 이동시켜야 이 cycle을 풀 수 있다.
  그리고 문제의 특성상 한 룩이 여러 사이클에 포함되는 경우는 없음을 알 수 있다. (정점의 max indegree, outdegree가 모두 1이다)
  따라서 사이클의 개수를 세어 주고, 원래 main diagonal 위에 있는 개수만큼 빼주면 된다.
*/

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int T, n, m, sz, c1, c2;
vector<int> adj[101010];
int rc[101010][2];
bool vis[101010], cur[101010];

bool is_cycle(int u) {
	vis[u] = true;
	cur[u] = true;
	bool ret = false;
	for (int v : adj[u]) {
		if (cur[v]) return true;
		if (!vis[v]) ret |= is_cycle(v);
	}
	cur[u] = false;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			rc[i][0] = 0;
			rc[i][1] = 0;
			vis[i] = false;
			cur[i] = false;
			c1 = c2 = 0;
		}
		for (int i = 1; i <= m; i++) {
			int r, c; cin >> r >> c;
			if (r == c) c2++;
			else {
				rc[r][0] = i;
				rc[c][1] = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!rc[i][0] || !rc[i][1]) continue;
			adj[rc[i][0]].pb(rc[i][1]);
		}
		for (int i = 1; i <= n; i++) 
			if (!vis[i] && is_cycle(i)) c1++;
		
		cout << m + c1 - c2 << "\n";
	}
	return 0;
}
