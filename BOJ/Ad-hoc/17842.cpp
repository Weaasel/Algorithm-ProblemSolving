//버스 노선
//Ad-hoc, dfs
/*
  주어진 트리에서 몇 개의 선을 그어 모든 정점을 커버하고 싶을 때 최소한으로 필요한 선의 개수를 구하는 문제.
  일단 모든 리프를 위한 선이 있어야 한다.
  그리고 하나의 선으로 2개의 리프를 커버할 수 있다.
  따라서 (리프의 개수+1)/2 개의 선이 필요하다.
*/

#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const ll INF = 1e9 + 7;
using namespace std;

int n, cnt, s;
vector<int> adj[202020];

void dfs(int u, int prv = -1) {
	int lvs = 0;
	for (int v : adj[u]) {
		if (v == prv) continue;
		lvs++;
		dfs(v, u);
	}
	if (!lvs) cnt++;
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	if (n == 2) return cout << 1, 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < n; i++) if (adj[i].size() >= 2) {
		s = i;
		break;
	}
	dfs(s);
	cout << (cnt + 1) / 2;
	return 0;
}
