//UNIST는 무엇의 약자일까?
//Dynamic Programming
/*
  dp[i][j]: i번째 문자열까지 봤을 때 "UNIST"의 j번째 문자까지 표현한 가지수
  i번째 문자열의 앞에서부터 몇개의 문자까지 사용할 것인지,
  "UNIST"의 몇 번째 문자부터 표현할 것인지를 정하고 해당하는 dp값에 더해준다.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string a[101010];
const string unist = " UNIST";
ll dp[101010][6];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	dp[0][0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) { //i번째 string에서
		for (int cnt = 0; cnt <= 5; cnt++) { //앞에서부터 몇개 쓸건지
			for (int st = 1; st + cnt <= 6; st++) { //표현할 문자의 start
				if (a[i].substr(0, cnt) == unist.substr(st, cnt)) {
					dp[i][st + cnt - 1] += dp[i - 1][st - 1];
					dp[i][st + cnt - 1] %= INF;
				}
			}
		}
	}
	cout << dp[n][5];
	return 0;
}
