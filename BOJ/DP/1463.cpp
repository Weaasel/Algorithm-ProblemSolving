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
#include <map>
#include <set>
using namespace std;
using ll = long long;

int dp[3][1000001];
int n;
int mmin = 21000000;

void go(int dpv, int value, int cnt) {
	if (cnt > mmin) return;
	if (value == 1) {
		if (cnt < mmin) mmin = cnt;
		return;
	}

	if (value % 3 == 0 ) go(0, value / 3, cnt + 1);
	if (value % 2 == 0) go(1, value / 2, cnt + 1);
	go(2, value - 1, cnt + 1);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	go(0, n, 0);
	cout << mmin;
}
