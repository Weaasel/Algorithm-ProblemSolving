//ACM Craft
//Bfs, Topological Sort
/*
  간단한 위상정렬 문제이다.
  입력받은 그래프를 정뱡향으로 연결해 두고 topological order로 순회한다.
  edge (u, v) 에 대해 생각하면 v 건물을 지으려면 u 건물을 짓고 지어야 하므로
  v 건물을 짓는 데에 걸리는 총 시간은 max(u들의 시간) + v짓는데에 걸리는 시간이 된다.
*/

#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;

int T;
int n, k, w, d[1010], ind[1010], ans[1010];
vector<int >adj[1010];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			ind[i] = 0;
			ans[i] = 0;
			adj[i].clear();
		}
		for (int i = 1; i <= n; i++) cin >> d[i];
		for (int i = 0; i < k; i++) {
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			ind[v]++;
		}
		cin >> w;
		queue<int> q;
		for (int i = 1; i <= n; i++) if(!ind[i]) q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			ans[u] += d[u];
			for (int v : adj[u]) {
				ans[v] = max(ans[v], ans[u]);
				ind[v]--;
				if (!ind[v]) q.push(v);
			}
		}
		cout << ans[w] << "\n";
	}
	return 0;
}
