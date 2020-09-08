//Unique Solution
/*
  max matching == n 을 만족하는 연결관계가 유일한지 판단하는 문제이다.
  adj를 왼쪽부터 넣고 오른쪽부터 넣고 각각 돌리고 비교했을 때 같은 결과를 내는지 확인하면 
*/

#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
#define pb push_back
using namespace std;

int n, a, cnt;
vector<int> adj[2001], adj2[2001];
int A[2001], B[2001], vis[2001], res[2001];

bool dfs1(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj[u]) {
		if (B[v] == -1 || dfs1(B[v])) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}

bool dfs2(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj2[u]) {
		if (B[v] == -1 || dfs2(B[v])) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		vector<int> v;
		for (int j = 0; j < a; j++) {
			int u; cin >> u;
			v.pb(u);
		}
		for (int j = 0; j < a; j++) {
			adj[i].pb(v[j] + 1000);
			adj[v[j] + 1000].pb(i);
			adj2[i].pb(v[a - j - 1] + 1000);
			adj2[v[a - j - 1] + 1000].pb(i);
		}
	}

	cnt = 0;
	memset(A, -1, sizeof A);
	memset(B, -1, sizeof B);
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			memset(vis, false, sizeof vis);
			if (dfs1(i)) cnt++;
		}
	}
	if (cnt != n) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++) res[i] = A[i];

	cnt = 0;
	memset(A, -1, sizeof A);
	memset(B, -1, sizeof B);
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			memset(vis, false, sizeof vis);
			if (dfs2(i)) cnt++;
		}
	}
	bool flg = true;
	for (int i = 1; i <= n; i++) {
		if (A[i] != res[i]) flg = false;
	}
	if (cnt == n && flg) {
		cout << "1\n";
		for (int i = 1; i <= n; i++) cout << res[i] - 1000 << " ";
	}
	else cout << -1;
	return 0;
}
