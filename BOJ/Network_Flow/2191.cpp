//들쥐의 탈출
/*
  쥐-구멍 사이에 연결관계만 이어주면 simple bipartite-matching 문제가 된다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2e18
using namespace std;

int n, m, A[101], B[101], cnt;
bool vis[101];
double x, y, s, v, mx[101], my[101], hx[101], hy[101];
vector<int> adj[101];

bool dfs(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj[u]) {
		if (B[v] == -1 || dfs(B[v])) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> v;
	for (int i = 0; i < n; i++) {
		cin >> mx[i] >> my[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> hx[i] >> hy[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((mx[i] - hx[j])*(mx[i] - hx[j]) + (my[i] - hy[j])*(my[i] - hy[j]) <= s * s*v*v) adj[i].pb(j);
		}
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < n; i++) {
		memset(vis, false, sizeof(vis));
		if (dfs(i)) cnt++;
	}
	cout << n - cnt;
	return 0;
}
