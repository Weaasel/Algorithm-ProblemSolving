//인접한 비트의 개수
//dp
/*
  dp[len][cnt][mode] : 전체길의 len에서 인접한 비트쌍이 cnt개인 마지막 비트가 mode인 개수
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
const ll DIV = 1e9 + 7;
using namespace std;

int T, n, k, dp[101][101][2];

int go(int len, int cnt, int mode) {
	if (dp[len][cnt][mode] > -1) return dp[len][cnt][mode];
	if (len <= cnt) return dp[len][cnt][mode] = 0;
	if (cnt == 0) {
		if (mode == 0) return dp[len][cnt][mode] = go(len - 1, cnt, 0) + go(len - 1, cnt, 1);
		else return dp[len][cnt][mode] = go(len - 2, cnt, 0) + go(len - 2, cnt, 1);
	}
	if (mode == 0) {
		return dp[len][cnt][mode] = go(len - 1, cnt, 0) + go(len - 1, cnt, 1);
	}
	else {
		return dp[len][cnt][mode] = go(len - 1, cnt, 0) + go(len - 1, cnt - 1, 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	dp[1][0][1] = 1;
	dp[1][0][0] = 1;
	dp[2][0][1] = 1;
	dp[2][0][0] = 2;
	dp[2][1][0] = 0;
	dp[2][1][1] = 1;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		cout << go(n, k, 0) + go(n, k, 1) << "\n";
	}
	return 0;
}
