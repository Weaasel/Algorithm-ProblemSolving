//양팔저울
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int n, m, a;
vector<int> chu;

char dp[31][100001];
char go(int cnt, int a) {
	if (cnt == 0) return dp[cnt][a] = 'N';
	if (dp[cnt][a] > 0) return dp[cnt][a];

	if (a == chu[cnt - 1] + 60000) return dp[cnt][a] = 'Y';

	if (a - chu[cnt - 1] >= 0 && a - chu[cnt - 1] <= 100000) {
		if (go(cnt - 1, a - chu[cnt - 1]) == 'Y') return dp[cnt][a] = 'Y';
	}

	if (a + chu[cnt - 1] >= 0 && a + chu[cnt - 1] <= 100000) {
		if (go(cnt - 1, a + chu[cnt - 1]) == 'Y') return dp[cnt][a] = 'Y';
	}
	
	if (a >= 0 && a <= 100000) {
		if (go(cnt - 1, a) == 'Y') return dp[cnt][a] = 'Y';
	}

	return dp[cnt][a] = 'N';
}

bool cmp(int a, int b) {
	return a < b ? false : true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		chu.push_back(a);
	}
	sort(chu.begin(), chu.end(), cmp);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		cout << go(n, a + 60000) << " ";
	}
	return 0;
 }
