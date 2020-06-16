//동전 바꿔주기
//dynamic programming
/*
  dp[i][j]를 i번째 동전까지 봤을 때 표현할 수 있는 j원의 가지수로 정의한다.
  그러면,
  dp[i][j] = dp[i-1][j- nth price] + dp[i-1][j - 2 * nth price] + ... 이라는 식을 얻게 된다.
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
#define DIV 1000000007;
const ll INF = 1e9;

using namespace std;
int T, k;
int p[101], n[101], dp[101][10001];

int go(int cnt, int price) {
	if (dp[cnt][price] > -1) return dp[cnt][price];
	if (cnt == 0) return dp[cnt][price] = 0;
	int res = 0, a = p[cnt], b = n[cnt];

	for (int i = 0; i <= min(b, price / a); i++) {
		res += go(cnt - 1, price - i * a);
	}
	return dp[cnt][price] = res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> k;
	for (int i = 1; i <= k; i++) cin >> p[i] >> n[i];
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= T; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1;
	cout << go(k, T);
	return 0;
}
