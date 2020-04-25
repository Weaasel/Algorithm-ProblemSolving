//Mowing the lawn
//DP, deque

/*
  n개의 수가 주어지고, 연속한 수를 골라서 그 합을 최대로 만드는 문제이다.
  고를 수 있는 연속한 수의 최대값은 k개이다. 즉 k개의 연속한 수를 고르면, 그 다음 한개는 무조건 건너뛰어야 한다.
  
  나는 "건너 뛸 수"를 골라서 전체 합에서 빼는 방식으로 해결했다.
  
  dp[i] : a[i]를 포함하며 조건에 만족하도록 뽑은 수들의 합의 최소값.
  즉 dp[i] = min(dp[i-k-1] ~ dp[i-1]) + a[i] 이다. 
  (이렇게 되면 [i-k, i-1] 구간의 수를 고른다, [i-k-1, i-1] 구간의 수를 고른다, ... 와 같은 의미가 된다)
  
  이 작업이 O(n * k) 만큼의 시간이 걸리므로, 이를 최적화하기 위해 최대 k개 구간의 원소를 담고 있을 min deque을 구현하면
  O(n)에 해결 가능하다.
  
  이렇게 dp배열을 만들고,
  dp[n-k] ~ dp[n] 중 최소값을 전체 sum에서 빼면 우리가 원하는 값을 구할 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define INF 2000000000000000000
using namespace std;

ll n, k, a[100001], dp[100001], sum = 0, mn = INF;
deque<pll> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= k + 1; i++) {
		dp[i] = a[i];
		while (!dq.empty() && dq.back().first > dp[i]) dq.pop_back();
        dq.pb({ dp[i], i });
	}
	for (int i = k + 2; i <= n; i++) {
		while (!dq.empty() && i - dq.front().second > k + 1) dq.pop_front();
		dp[i] = dq.front().first + a[i];
		while (!dq.empty() && dq.back().first > dp[i]) dq.pop_back();
		dq.push_back({ dp[i], i });
	}

	for (int i = n; i >= 0 && i >= n - k; i--) {
		mn = min(mn, dp[i]);
	}
	cout << sum - mn;
	return 0;
}
