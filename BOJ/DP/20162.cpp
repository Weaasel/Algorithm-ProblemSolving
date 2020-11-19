//간식 파티
//Dynamic Programming, LIS
/*
  1000 개 이하의 간식들이 주어지고, 순서대로 먹되 먹은 간식의 값이 단조증가하도록 먹을때, 먹은 간식의 총합의 최대값을 구하는 문제이다.
  마치 n^2 LIS를 하듯이 dp[i]를 i번째를 먹었을 때의 최대값이라고 두자.
  dp[i] = max(dp[j]) + a[i] (j < i, a[j] < a[i]인 j에 대해서만)
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e9+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265
const ll MOD = 998244353;

using namespace std;

int n, a[1001], dp[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[a[0]] = a[0];
	for (int i = 1; i < n; i++) {
		int mx = -1;
		for (int j = 0; j < a[i]; j++) 
			mx = max(mx, dp[j]);
		dp[a[i]] = max(dp[a[i]], mx + a[i]);
	}
	int mx = -1;
	for (int i = 0; i < 100001; i++) mx = max(mx, dp[i]);
	cout << mx;
	return 0;
}
