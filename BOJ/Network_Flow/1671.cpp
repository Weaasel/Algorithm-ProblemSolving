//상어의 저녁식사
//Bipartite matching
/*
  한 상어는 최대 두마리의 상어를 잡아먹을 수 있으므로, A집합에 한 상어를 두 마리씩 넣어둔다.
  모든 능력치가 같은 상어끼리는 서로 잡아먹을 수 없으므로, 이에 대해 그냥 우선순위를 정해줘 버린다.
  이렇게 하면 단순 이분매칭 문제로 환원된다.
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
#define INF 1e9
#define base 100000
using namespace std;

int n, A[101], B[51], vis[101], a[51], b[51], c[51], res;
vector<int> adj[101];

bool dfs(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj[u]) {
		if (B[v] == 0 || dfs(B[v])) {
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
	cin >> n;
	res = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] >= a[j] && b[i] >= b[j] && c[i] >= c[j]) {
				if (a[i] == a[j] && b[i] == b[j] && c[i] == c[j] && i <= j) continue;
				adj[i].pb(j);
				adj[i + n].pb(j);
			}
		}
	}
	for (int i = 1; i <= 2*n; i++) {
		memset(vis, false, sizeof(vis));
		if (dfs(i)) res--;
	}
	cout << res;

	return 0;
}
