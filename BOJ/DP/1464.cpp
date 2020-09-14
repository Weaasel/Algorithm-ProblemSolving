//뒤집기 3
//String, dp
/*
  각 index까지 처리했을 때의 사전순으로 가장 앞선 문자열을 저장해두자.
  그것을 dp[index]라고 하면, 
  index까지 봤을 때 사전순으로 가장 앞선 문자열은 dp[index], 가장 뒤에 있는 문자열은 reverse(dp[index]) 일 것이다.
  우리는 dp[index+1]이 될 수 있는 후보들을 추릴 수 있다.
  1. mn + s[index+1]
  2. s[index+1] + mn (mx + s[index+1]을 뒤집었다고 생각하면 편하다)
  이 둘중에 작은 값으로 고르면 된다.
  사실 이렇게 생각하니 dp배열 없이 그리디로도 된다.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int sz;
string s, mn, c1, c2;
string dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	sz = s.size();
	dp[0] = s[0];
	for (int i = 1; i < sz; i++) {
		mn = dp[i - 1];
		c1 = s[i] + mn;
		c2 = mn + s[i];
		dp[i] = min(c1, c2);
	}
	cout << dp[sz - 1];
	return 0;
}
