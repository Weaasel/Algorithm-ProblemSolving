//E - Two Round Dances	
//Combinatorics
/*
  주어진 짝수 n에 대해서 크기가 같은 두 그룹으로 나누고 각각의 그룹을 원형으로 배치하는 경우의 수를 구한다.
  그룹을 나누는 경우의 수는 nC(n/2) / 2 이다. 2로 나누는 이유는 (1,2,3,4)를 나눌 때 (1,3), (2,4) == (2,4), (1,3) 이기 때문이다.
  그후 각 그룹을 원형배치 하는 경우의 수는 각각 (n/2-1)! 이다. 원순열이기 때문이다.
  이를 모두 곱하면 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll T, n;
ll res;
ll dp[50][50];

ll nck(int n, int k) {
	if (dp[n][k] > 0) return dp[n][k];
	if (n == k) return dp[n][k] = 1;
	if (k == 0) return dp[n][k] = 1;
	return dp[n][k] = (nck(n - 1, k) + nck(n - 1, k - 1));
}

ll fact(ll n) {
	if (n <= 1) return 1LL;
	else return n * fact(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	res = nck(n, n / 2)*fact(n / 2 - 1)*fact(n / 2 - 1) / 2;
	cout << res << "\n";

	return 0;
}
