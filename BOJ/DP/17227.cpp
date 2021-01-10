//그래서 팩 주냐?
//Dynamic Programming on DAG
/*
  dp[u][type]: u번 정점을 type 차례에 선택했을 때 최소 정색 횟수
  로 정의하고 DAG dp를 잘 돌려주자.
  만약 내차례때 밟았다면 상대방은 다음 정점들 중 내가 정색을 가장 많이 할 정점으로 갈 것이다.
  그런데 나는 비용 1을 써서 정점을 하나씩 막을 수 있다.
  만약 상대 차례때 밟았다면 나는 다음 정점들 중 최소 정색이 필요한 정점으로 이동하면 된다.
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
const int INF = 1e9 + 7;
using namespace std;

int n, m, res = INF;
int in[101010];
pii dp[101010]; //x: 내차례일때 선택, y: 니차례일때 선택

vector<int> adj[101010];

pii go(int u) {
	if (dp[u].x > -1 && dp[u].y > -1) return dp[u];
	vector<int> vv;
	int mn = INF, mx = INF; //mn: 내가고르면, mx: 니가고르면
	int sz = adj[u].size();
	for (int v : adj[u]) {
		pii p = go(v);
		mx = min(mx, p.x);
		vv.pb(p.y);
	}
	sort(all(vv));
	for (int i = 0; i < sz; i++)
		mn = min(mn, vv[i] + sz - 1 - i);
	return dp[u] = { mn, mx };
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		in[v]++;
	}

	for (int i = 1; i <= n; i++) {
		dp[i].x = -1;
		dp[i].y = -1;
	}

	dp[n].x = 0;
	dp[n].y = INF;

	for (int i = 1; i <= n; i++) 
		if (in[i] == 0) res = min(res, go(i).x);
    if(res==INF) cout<<-1;
	else cout << res;

	return 0;
}
