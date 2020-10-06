//최대 정사각형
//Dynamic Programming
/*
  dp배열 정의
  dp[i][j]: (i,j)를 포함하는 가장 큰 정사각형의 크기
  이렇게 하면
  dp[i][j]는 dp[i-1][j], dp[i-1][j-1], dp[i][j-1]의 정보에서 받아올 수 있다.
  만약 이 3개가 전부 2이고 a[i][j]가 1이라면 dp[i][j]는 3인 것이다.
  ***
  ***
  **(i,j) 인 상황일 것이다.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

int n, m;
int a[1001][1001], dp[1001][1001], ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> n >> m;
		ans = 0;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = 0;
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!a[i][j]) continue;
				dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
