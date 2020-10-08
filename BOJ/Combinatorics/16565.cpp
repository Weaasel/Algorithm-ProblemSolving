//N포커
//Combinatorics, inclusion-exclusion principle
/*
  N장의 카드를 뽑을 때
  포카드 1쌍을 얻는 경우 - 2쌍을 얻는 경우 + 3쌍을 얻는 경우 ... 를 구하면 된다.
  포카드 i쌍을 얻는 경우의 수는
  13Ci * (52-4i)C(N-4i) 이다.
*/

#include <iostream>
using namespace std;

const int MOD = 10007;
int n, k, res, sgn = 1;
int dp[55][55];

int nck(int n, int k) {
	if (dp[n][k] > 0) return dp[n][k];
	if (n == k) return dp[n][k] = 1;
	if (k == 0) return dp[n][k] = 1;
	return dp[n][k] = (nck(n - 1, k) + nck(n - 1, k - 1)) % MOD;
}

int main() {
	cin >> n;
	for (int i = 1; i <= 13; i++) {
		if (n - 4 * i < 0) break;
		res += (nck(13, i)*nck(52 - 4 * i, n - 4 * i)*sgn)%MOD;
		sgn *= -1;
		res += MOD;
		res %= MOD;
	}
	cout << res;
	return 0;
}
