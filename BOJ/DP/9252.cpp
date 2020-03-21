//LCS2
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;
char str1[1001], str2[1001];
int dp[1002][1002], l1, l2;
stack<char> s;
void f() {
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}
int main() {
	cin >> str1 >> str2;
	l1 = strlen(str1), l2 = strlen(str2);
	f();
	
	int cur = dp[l1][l2], rwalk = l1, cwalk = l2;
	while (cur > 0) {
		while (dp[rwalk - 1][cwalk] == cur) rwalk--;
		while (dp[rwalk][cwalk - 1] == cur) cwalk--;
		s.push(str1[rwalk - 1]);
		rwalk--;
		cwalk--;
		cur--;
	}
	cout << dp[l1][l2] << "\n";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}
