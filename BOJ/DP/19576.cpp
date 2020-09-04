//약수
/*
  핵심은 남길 수 있는 수를 최대한 남기고 나머지를 바꾸는 전략이다.
  남길 수들은 서로가 약수-배수인 관계로 커져야 한다.
  배열을 크기순으로 정렬한 상태에서 마치 LIS를 진행하듯이 최대 약수-배수 수열의 길이를 찾으면 된다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, res, a[5001], dp[5001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] % a[j]) continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	cout << n - res;
	return 0;
}
