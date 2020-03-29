//연세워터파크
//dp, deque

#include <iostream>
#include <cstdio>
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
#define pll pair<ll, ll>
#define MAX 
#define DIV 1000000
#define INF 10000000000000000

using namespace std;

ll n, d, arr[200001], dp[200001];
deque<pll> dq;

ll go() {
	dp[0] = arr[0]; dq.push_back({ 0, dp[0] });
	for (int i = 1; i < n; i++) {
		while (!dq.empty() && dq.front().first < i - d)dq.pop_front();
		dp[i] = max(arr[i], dq.front().second + arr[i]);
		while (!dq.empty() && dq.back().second < dp[i]) dq.pop_back();
		dq.push_back({ i, dp[i] });
	}
	ll mx = -INF;
	for (int i = 0; i < n; i++) mx = max(dp[i], mx);
	return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << go();
}
