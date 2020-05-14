//B - Orac and Models	
/*
  simple dp 문제이다. 시간복잡도에 대해서는 에라토스테네스의 체를 생각하면 제한시간 안에 통과할 수 있음을 알 수 있었다.
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
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

ll T, n, k, a[100001], dp[100001];

ll go(ll nn) {
	if (dp[nn] > -1) return dp[nn];
	ll res = 1;
	for (int i = 2 * nn; i <= n; i += nn) {
		if(a[nn] <a[i]) res = max(res, go(i) + 1);
	}
	return dp[nn] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) dp[i] = -1;
		ll res = -1;
		for (int i = 1; i <= n; i++) {
			res = max(res, go(i));
		}
		cout << res << "\n";
	}
	return 0;
}
