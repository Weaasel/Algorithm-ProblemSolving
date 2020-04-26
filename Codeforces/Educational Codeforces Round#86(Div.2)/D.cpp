//D - Multiple Testcases	
/*
  n개를 k개 이하씩 나누어 분배할 때 필요한 집합의 최소 개수를 구하는 문제.
  ans = (n-1)/k + 1
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

int n, k, num, c[200001], res = 0;
vector<int> m;

vector<int> ans[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		m.pb(num);
	}
	sort(all(m));
	for (int i = 0; i < k; i++) cin >> c[i];

	for (int i = 1; i <= k; i++) {
		int idx = lower_bound(all(m), i) - m.begin();
		if (idx >= n) continue;
		int cnt = n - idx;
		res = max(res, (cnt - 1) / c[i - 1] + 1);
	}

	int walk = 0;
	for (int i = 0; i < n; i++) {
		ans[walk%res].pb(m[i]);
		walk++;
	}
	cout << res << "\n";
	for (int i = 0; i < res; i++) {
		cout << ans[i].size() << " ";
		for (int p : ans[i]) cout << p << " ";
		cout << "\n";
	}

	return 0;
}
