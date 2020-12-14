//트리 색칠하기
/*
  기본 뼈대는 다음과 같다.
  dp[i][col]: i번째 노드를 col 색으로 칠할 때 i노드를 root로 가지는 subtree 총 비용의 최소값
  이렇게 하면 식이 간단해진다.
  dp[i][col] = cost[col] + sum of dp[child][col']: child들을 root로 하는 subtree들의 최소비용을 합칠건데 col이 아닌 색으로 칠해야 함.
  
  여기까진 좋은데 정점도 10만 색도 10만개라 난감하다.
  적당한 증명을 통해 실제로 사용하는 색은 log(100,000) 개라는 사실을 알 수 있다(고 한다).

  T(i): i번째 색까지 사용해야 optimal인 tree의 크기라고 정의하면
  T(1) = 1 (obviously)
  T(i) >= T(i-1) + T(i-2) + ... + T(1)
  i번째 색을 써야하는 노드 주변의 노드들이 1 ~ i-1 번째 색까지 사용했어야 해당 노드에 i번째 색을 사용할 조건이 된다.
  이 개수들을 각각의 주변노드를 root로 하는 tree로 생각하면 위의 식을 얻을 수 있다. (Koosaga는 천재다.)
  
  따라서 T(n)은 exponential하게 증가한다.
*/

#include <bits/stdc++.h>
#define pb push_back
#define ll long long
const ll INF = 1e18 + 7;
using namespace std;

int n, u, v, lv[100001];
vector<int> adj[100001];
ll dp[100001][30], a[100001];

void dfs(int u, int par) {
	for (int v : adj[u]) {
		if (v == par) continue;
		lv[v] = lv[u] + 1;
		dfs(v, u);
	}
	return;
}

ll go(int u, int col) {
	if (dp[u][col] > 0) return dp[u][col];
	ll res = a[col];
	for (int v : adj[u]) {
		if (lv[v] < lv[u]) continue;
		ll mn = INF;
		for (int i = 0; i < min(30,n); i++) {
			if (i == col) continue;
			mn = min(mn, go(v, i));
		}
		res += mn;
	}
	return dp[u][col] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < n; i++) a[i] = i+1;
	lv[1] = 1;
	dfs(1, -1);
	ll res = INF;
	for (int i = 0; i < min(n, 30); i++) {
		res = min(res, go(1, i));
	}
	cout << res;
	return 0;
}
