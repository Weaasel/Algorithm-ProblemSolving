//Running Routes
/*
  문제 해석은 원의 교차하지 않는 현들의 최대집합 이라고 생각하면 편하다.
  
  핵심은 이 문제를 2차원 dp로 해결할 수 있다는 점인데,
  '파일 합치기', '행렬 곱셈' 문제 등과 같은 유형의 2차원 n^3 dp이다.
  
  이게 되는 이유는 한 구간을 둘로 나눴을 때, 그 두 구간 사이의 현은 포함시킬 수가 없기 때문이다.
  예컨대, 두 구간 사이의 현을 쓰게 되면 원래 쓰던 현들 중에 못 쓰는 현이 생긴다.
  구현상으론 특별할 것은 없다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
#define INF 1e9
using namespace std;

int n, adj[501][501], dp[501][501];

int go(int l, int r) {
	if (dp[l][r] > -1) return dp[l][r];
	if (r == l) return dp[l][r] = 0;
	if (r - l == 1) return dp[l][r] = adj[l][r];
	if (r - l == 2) return dp[l][r] = max({ adj[l][l + 1], adj[l][l + 2], adj[l + 1][l + 2] });
	dp[l][r] = max({ go(l+1, r), go(l, r-1), go(l+1, r-1) + adj[l][r] });
	for (int k = l; k < r; k++) {
		dp[l][r] = max(dp[l][r], go(l, k) + go(k + 1, r));
	}
	return dp[l][r];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> adj[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << go(1, n);
}
