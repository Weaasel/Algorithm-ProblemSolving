//Time is Mooney

/*
  여행의 길이가 최대 1000을 넘을 수 없다는 가정 하에
  그래프dp 문제.
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define MAX 4001
#define DIV 1000000007LL
#define INF 2000000000000000000
using namespace std;

ll N, M, C, m[1001], u, v, ans = 0;
ll dp[1001][1001];

pii adj[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) cin >> m[i];
	for (int i = 0; i < M; i++) {
		cin >> adj[i].first >> adj[i].second;
	}
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= N; j++) dp[i][j] = -INF;
	dp[0][1] = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < M; j++) {
			pii t = adj[j];
			int from = t.first, to = t.second;
			if(dp[i-1][from] != -INF) dp[i][to] = max(dp[i][to], dp[i-1][from] + m[to]);
		}
		ans = max(ans, dp[i][1] - C * i*i);
	}
	cout << ans;
	return 0;
}
