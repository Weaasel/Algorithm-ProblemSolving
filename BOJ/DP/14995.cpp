//Horror Film Night
//dp

/*
  simple dp로 해결할 수 있는 문제다.
  연속한 구간의 개수를 택하는 greedy한 방식도 가능하다.
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
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

int k, num;
bool chk1[1000001];
bool chk2[1000001];
int dp[3][1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num;
		chk1[num] = true;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num;
		chk2[num] = true;
	}
	if (chk1[0] && chk2[0]) dp[0][0] = 1;
	else if (chk1[0]) dp[1][0] = 1;
	else if (chk2[0]) dp[2][0] = 1;
	for (int i = 1; i < 1000000; i++) {
		dp[0][i] = dp[0][i - 1];
		dp[1][i] = dp[1][i - 1];
		dp[2][i] = dp[2][i - 1];
		if (chk1[i] && chk2[i]) {
			dp[0][i] = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1] }) + 1;
		}
		if (chk1[i]) dp[1][i] = max({dp[0][i - 1], dp[2][i - 1] }) + 1;
		if (chk2[i]) dp[2][i] = max({dp[0][i - 1], dp[1][i - 1] }) + 1;
	}

	cout << max({ dp[0][999999], dp[1][999999], dp[2][999999] });
	return 0;
}
