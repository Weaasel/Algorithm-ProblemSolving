//보석 줍기
//dp, top-down

#include <iostream>
#include <cstdio>
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
#define MAX 
#define DIV 1000000
#define INF 2000000000

using namespace std;

int n, m, a[100001], dp[100001], num, res;

int go(int n) {
	if (dp[n] > -INF) return dp[n];
	if (n == m) {
		dp[n] = a[n];
		return dp[n];
	}
	return dp[n] = max(go(n - 1) + a[n] - a[n - 1], a[n] - a[n - m]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) dp[i] = -INF;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		a[i] = a[i - 1] + num;
	}

	res = go(n);
	res = max(res, 0);
	for (int i = m; i < n; i++) res = max(res, dp[i]);
	cout << res;

	return 0;
}
