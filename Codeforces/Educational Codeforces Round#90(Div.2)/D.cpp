//D - Maximum Sum on Even Positions	
/*
  최대 1개의 구간만 reverse 할 수 있다.
  [l, r] 구간을 reverse하면 해당 구간의 홀짝idx가 서로 바뀐다.(짝수개일 경우에)
  
  -> 해당 idx까지 연속한 구간들 중 홀수번째 원소들의 합 - 짝수번째 원소들의 합 을 dp로 저장해서
  그 중 최대인 구간을 고르면 된다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

ll T, n, res;
ll a[200001], dp[200001];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		res = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i % 2 == 0) res += a[i];
		}

		ll mx = -1;
		for (int i = 0; i < n; i++) dp[i] = 0;
		dp[1] = a[1] - a[0];
		for (int i = 3; i < n; i+=2) {
			dp[i] = max(dp[i-2] , 0LL) + a[i] - a[i - 1];
		}
		for (int i = 0; i < n; i++) mx = max(mx, dp[i]);

		for (int i = 0; i < n; i++) dp[i] = 0;
		dp[2] = a[1] - a[2];
		for (int i = 4; i < n; i += 2) {
			dp[i] = max(dp[i - 2], 0LL) + a[i-1] - a[i];
		}
		for (int i = 0; i < n; i++) mx = max(mx, dp[i]);

		cout << res + max(0LL, mx) << "\n";
	}
	return 0;
}
