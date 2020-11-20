//음악프로그램
//BFS, Topology sort
/*
  m명의 pd가 뽑은 리스트에 대해 앞에 있는 프로그램으로부터 뒤에 있는 프로그램으로 간선을 연결하면
  indegree가 0인 프로그램부터 나열해야 하는 위상정렬 문제가 된다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e9+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265
const ll MOD = 998244353;

using namespace std;

int n, m, cnt;
vector<int> adj[1001], res;
int ind[1001];
bool vis[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num, u, v; cin >> num;
		if (num == 0) continue;
		cin >> u;
		for (int j = 0; j < num - 1; j++) {
			cin >> v;
			adj[u].pb(v);
			ind[v]++;
			u = v;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			vis[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		res.pb(u);
		for (int v : adj[u]) {
			if (vis[v]) continue;
			ind[v]--;
			if (ind[v] == 0) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
	if (res.size() != n) cout << 0;
	else {
		for (int r : res) cout << r << "\n";
	}
	return 0;
}
