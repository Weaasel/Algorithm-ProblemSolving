//Research Productivity Index
//확률, dp, greedy
/*
  n개의 논문이 있다. 각 논문별로 accepted될 확률이 주어지고,
  a: accepted된 논문 수
  s: submit한 총 논문 수
  라고 할 때, a^(a/s)를 maximize하는 문제다.
  
  일단 같은 수의 논문을 낸다고 하면 최대한 확률이 높은 논문들을 내는 게 이득이다.
  따라서 몇 개의 논문을 낼 때가 가장 기대값이 높은지만 따지면 된다.
  
  dp[s][a] : s개의 논문을 냈을 때 a개가 accepted될 확률
  로 잡으면, s개의 논문을 냈을 때의 총점은
  1^(1/s) * dp[s][1] + 2^(2/s) * dp[s][2] + ... 로 계산 가능하다.
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
#define all(v) (v).begin(), (v).end()
using namespace std;

int n;
double dp[101][101];

bool cmp(double a, double b) {
	return a > b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<double> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
		pos[i] /= 100.0;
	}

	sort(all(pos), cmp);
	dp[0][0] = 1 - pos[0];
	dp[0][1] = pos[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] * (1.0 - pos[i]);
			else dp[i][j] = dp[i - 1][j] * (1.0 - pos[i]) + dp[i - 1][j - 1] * pos[i];
		}
	}
	double res = 0;
	for (int i = 0; i < n; i++) {
		double tmp = 0;
		for (int j = 0; j <= i + 1; j++) {
			if (j == 0) continue;
			tmp += dp[i][j] * pow((double)j, (double)j / (i+1));
		}
		res = max(res, tmp);
	}

	printf("%.7lf", res);
	return 0;
}
