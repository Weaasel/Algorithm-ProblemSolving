//작은 새
//Dynamic programming with deque
/*
  dp[i]: i번째 나무에 도달했을 때 느끼는 피로감의 최소 횟수
  dp[i]의 값은 dp[i-k], dp[i-k+1], ... dp[i-1] 에서 i번째 나무로 뛰었을 때 최소인 횟수로 정해진다.
  이 연산을 k개의 구간에 대해서만 진행하므로 덱을 이용한 슬라이딩 윈도우 구현이 가능하다.
  
  우선순위
    1. 횟수가 적은 것이 무조건 좋다. 높이가 아주 낮은 나무여서 다음 나무로 넘어갈 때 횟수가 커진다고 해도 본전이다.
    2. 횟수가 같다면 나무의 높이가 높은 것이 좋다. 설명은 필요 없다.
    3. 횟수와 나무의 높이가 같다면 가까운 나무가 좋다. 먼 나무는 먼저 사라진다.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
const ll INF = 2e9 + 10;
const int MOD = 100003;

using namespace std;

int n, q, k, a[1010100];
pii dp[1010100];
deque<pii> dq;

void solve(int k) {
	dq.clear();
	dp[0] = { 0,0 };
	dq.pb(dp[0]);
	for (int i = 1; i < n; i++) {
		while (!dq.empty() && dq.front().second + k < i) dq.pop_front();
		pii prv = dq.front();
		dp[i] = { prv.first + (a[prv.second] <= a[i]), i };
		while (!dq.empty()) {
			if (dq.back().first > dp[i].first) dq.pop_back();
			else if (dq.back().first == dp[i].first && a[dq.back().second] <= a[dp[i].second]) dq.pop_back();
			else break;
		}
		dq.pb(dp[i]);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> k;
		solve(k);
		cout << dp[n - 1].first << "\n";
	}

}
