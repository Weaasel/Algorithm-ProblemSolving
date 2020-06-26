//소가 길을 건너간 이유8
//DP, LCS-like
/*
  dp[i][j] : 왼쪽길의 i번째와 오른쪽길의 j번째까지 봤을 때 놓을 수 있는 횡단보도의 최대 개수
  LCS를 update하듯이
  dp[i][j] = max(dp[i-1][j], max[i][j-1])로 이전 단계에서 받아오고,
  만약 i-j 를 이을 수 있다면 dp[i-1][j-1]+1 까지 함께 비교해준다.
  총 3개의 점에서 받아온 값들 중 최대값으로 업데이트한다.
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
#define INF 1e15
using namespace std;

int n, a[1001], b[1001], dp[1001][1001];

int go(int i, int j) {
	if (dp[i][j] > -1) return dp[i][j];
	if (i == 0 || j == 0) return dp[i][j] = 0;
	int res = max(go(i - 1, j), go(i, j - 1));

	if (abs(a[i] - b[j]) <= 4) res = max(res, go(i - 1, j - 1) + 1);
	return dp[i][j] = res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	cout << go(n, n);
	return 0;
}
