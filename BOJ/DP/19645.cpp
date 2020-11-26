//햄최몇?
//Dynamic Programming, knapsack problem
/*
  세명에게 햄버거를 나눠주는 일을 두명에게 나눠주는 일로 바꿔보자.
  어차피 나머지 한 명의 효용은 (전체효용 - 두명의 효용) 이므로,
  분배에 대한 state를 chk[2500][2500]으로 표현할 수 있다.
  그럼 이 문제는 (0,0) ~ (2500,2500) 까지의 state들에 대해 나눠주는 것이 가능한지 묻는
  knapsack problem이 된다.
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[50], res, s;
bool chk[2501][2501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	chk[0][0] = true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int idx = 0; idx < n; idx++) {
		for (int i = 2500; i >= 0; i--) {
			for (int j = 2500; j >= 0; j--) {
				if (i - a[idx] >= 0 && chk[i - a[idx]][j]) chk[i][j] = true;
				if (j - a[idx] >= 0 && chk[i][j - a[idx]]) chk[i][j] = true;
			}
		}
	}
	for (int i = 0; i <= 2500; i++) {
		for (int j = 0; j <= 2500; j++) {
			int cand = s - i - j;
			if (!chk[i][j] || cand > i || cand > j) continue;
			res = max(res, cand);
		}
	}
	cout << res;
	return 0;
}
