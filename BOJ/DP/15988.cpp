//1, 2, 3 더하기 3
//Dynamic Programming
/*
  원숭이도 나무에서 떨어질 때가 있고, dp문제를 수백 개 풀었어도 메모이제이션을 실수할 때가 있다. 주의하자.
  dp[n] = dp[n-1] + dp[n-2] + dp[n-3] 
*/

#include <bits/stdc++.h>
const int INF = 1e9 + 9;

using namespace std;

int T, n, dp[1010101];

int go(int n) {
	if (dp[n] > -1) return dp[n];
	if (!n) return dp[n] = 1;
	int ret = 0;
	if (n >= 1) ret = (ret + go(n - 1)) % INF;
	if (n >= 2) ret = (ret + go(n - 2)) % INF;
	if (n >= 3) ret = (ret + go(n - 3)) % INF;
	return dp[n] = ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> T;
	while (T--) {
		int n; cin >> n;
		cout << go(n) << "\n";
	}
	return 0;
}
