//카드 구매하기2
//Dynamic Programming
/*
  n장의 카드를 사기 위해 필요한 최소 금액은
  1,2,3...k장의 카드를 살 수 있는 선택지가 있을 때 
  1장을 사고 n-1장을 최소금액으로 구매, 2장을 사고 n-2장을 최소금액으로 구매, ... 하는 방법들 중 최소비용을 택해 구매하면 된다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, dp[1001], p[1001];

int go(int n) {
	if (n == 0) return dp[n] = 0;
	if (n < 0) return INF;
	if (dp[n] > -1) return dp[n];
	int ret = INF;
	for (int i = 1; i <= n; i++) 
		ret = min(ret, go(n - i) + p[i]);
	
	return dp[n] = ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	memset(dp, -1, sizeof(dp));
	cout << go(n);
	return 0;
}
