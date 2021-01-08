//F - Strange Housing	
//Dfs tree, greedy
/*
  주어진 graph가 connected component가 아니라면 답은 NO다.
  이외의 모든 경우는 다음의 그리디한 해법으로 해결 가능하다.
  1. root(1번 노드)에 선생님을 배치하고 dfs 시작
  2. 해당 노드 기준 back edge node들 중 하나라도 선생님이 배치되어 있으면 배치안함
  3. else 선생님 
*/

//1D
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
const int INF = 1e9 + 7;
using namespace std;
//getline(cin, s);

int T, n, m;
int col[303030];
vector<int> adj[303030];
vector<int> res;
bool flg;

void dfs(int u) {
	int ret = 1;
	for (int v : adj[u]) {
		if (col[v] == 1) ret = 2;
	}
	col[u] = ret;
	if (ret == 1) res.pb(u);
	for (int v : adj[u]) {
		if (col[v]) continue;
		dfs(v);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		res.clear();
		flg = true;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			col[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		for (int i = 1; i <= n; i++) if (!col[i]) flg = false;
		if (!flg) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << res.size() << "\n";
			for (int r : res) cout << r << " ";
			cout << "\n";
		}
	}
	return 0;
}
