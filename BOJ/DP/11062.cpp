//카드 게임
//DP
/*
  구간 [l, r] 에서 l, r 번째 카드 중 하나를 가져가야 한다.
  내 차례일 때는 미래에 최대의 효용을 가져다주는 선택을 하면 되고,
  상대 차례일 때는 미래에 최대의 효용을 가져다주는 선택을 구간 [l, r] 의 합에서 뺀 것이 내가 가져갈 수 있는 효용이 된다.
  이 3가지 정보를 담은 3차원 dp를 짜면 된다.
*/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ii = pair<int, int>;
using lint = long long;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define pb(v) push_back(v)
const int MOD = 1e9 + 7, mxn = 100010;

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, n, a[1001], dp[1001][1001][2], psum[1001];

int go(int l, int r, int type) {
	if (l == r) {
		if (!type) return dp[l][r][type] = a[l];
		else  dp[l][r][type] = 0;
	}
	if (dp[l][r][type] > -1) return dp[l][r][type];
	if (!type) {
		return dp[l][r][type] = max(go(l + 1, r, 1) + a[l], go(l, r - 1, 1) + a[r]);
	}
	else {
		return dp[l][r][type] = psum[r]-psum[l-1] - max(go(l + 1, r, 1) + a[l], go(l, r - 1, 1) + a[r]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> tc;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		memset(psum, 0, sizeof(psum));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			psum[i] = psum[i - 1] + a[i];
		}
		cout << go(1, n, 0) << "\n";
	}

	return 0;
}
