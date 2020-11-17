//오렌지 출하
//Dynamic Programming
/*
  dp[i]: i번째 오렌지까지 출하하는 최소비용으로 정의하자.
  한 상자에 최대 M개까지 넣을 수 있으므로
  dp[i] = min(dp[i-M] + (마지막 상자에 i-M+1~i번째 넣기), dp[i-M+1] + (마지막 상자에 i-M+2~i번째 넣기), ...) 로 구할 수 있고,
  시간복잡도는 O(NM)이다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e18+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265

const ll mod = 1e9 + 7;

using namespace std;

ll dp[20202], a[20202], n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		ll mx = a[i], mn = a[i], cnt;
		for (int j = i - 1; j >= 0; j--) {
			if (i - j > m) break;
			mx = max(mx, a[j + 1]);
			mn = min(mn, a[j + 1]);
			cnt = i - j;
			dp[i] = min(dp[i], dp[j] + k + cnt * (mx - mn));
		}
	}
	cout << dp[n];

	return 0;
}
