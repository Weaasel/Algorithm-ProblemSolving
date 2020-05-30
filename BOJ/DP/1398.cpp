//동전 문제
/*
  0 ~ 99원까지만 dp로 표현하면, 100단위로 greedy하게 표현이 가능하다.
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
#define INF 1e9
using namespace std;

vector<ll> coin;
ll T, n, dp[101];
void init() {
	for (int i = 1; i <= 100; i++) dp[i] = INF;
	for (int i = 1; i <= 100; i++) {
		if (i >= 1) dp[i] = min(dp[i], dp[i - 1] + 1);
		if (i >= 10) dp[i] = min(dp[i], dp[i - 10] + 1);
		if (i >= 25) dp[i] = min(dp[i], dp[i - 25] + 1);
	}
	return;
}

ll solve(ll n) {
	ll res = 0;
	while (n > 0) {
		res += dp[n % 100];
		n /= 100;
	}
	return res;
}

int main() {
	cin >> T;
	init();
	while (T--) {
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}
