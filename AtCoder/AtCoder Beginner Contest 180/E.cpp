//Traveling Salesman among Aerial Cities
//Bitwise DP, Traveling salesman, TSP
/*
  제목에까지 친절하게 알려준 TSP 문제이다.
  간선 비용만 문제 description대로 초기화하면 과거에 짜둔 TSP코드를 재활용할 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
#define INF 1e9
using namespace std;

int n, w[17][17], dp[17][1 << 17];

struct point {
	int x, y, z;
};
point a[17];

int TSP(int current, int visited) {
	int ret = dp[current][visited];
	if (ret != -1) return ret;
	if (visited == (1 << n) - 1) {
		if (w[current][0] != 0) return w[current][0];
		return INF;
	}

	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited & (1 << i) || w[current][i] == 0) continue;
		ret = min(ret, TSP(i, visited | (1 << i)) + w[current][i]);
	}
	return dp[current][visited] = ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			w[i][j] = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) + max(0, a[j].z - a[i].z);
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << TSP(0, 1);
}
