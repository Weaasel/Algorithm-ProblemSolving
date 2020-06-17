//작업
//DAG, DP
/*
  DAG를 이용한 DP 전형적인 형태의 문제이다.
  내 작업 완료시간 =  (하위작업들 중 가장 늦게 끝나는 작업 + 내 작업시간)
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;
int n, k, par, c[10001], dp[10001];
vector<int> adj[10001];

int go(int u) {
	if (dp[u] > -1) return dp[u];
	int res = 0;
	for (int v : adj[u]) {
		res = max(res, go(v));
	}
	return dp[u] = c[u] + res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> par;
			adj[par].pb(i);
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) ret = max(ret, go(i));
	cout << ret;
	return 0;
}
