//D. increment of coins
//Dynamic Programming
/*
  내가알던 abc의 D난이도가 아니다ㅠㅠ
  3종류의 코인을 각각 a,b,c개씩 갖고 시작하고, 한번의 operation에서는 a+b+c개의 코인중 하나를 랜덤하게 뽑아 그 코인과 같은 색의 코인을 1개 추가한다. 셋 중 어느 하나라도 100개가 되면 끝난다.
  이때, operation 총 횟수의 기대값은?
  dp[i][j][k]: i,j,k개씩 가지고 시작했을 때 operation 기대값
  으로 정의하면 simple dp로 풀린다.
  dp(i, j, k) 상태에서 1번 수행하면 dp(i+1, j, k), dp(i, j+1, k), dp(i, j, k+1) 중 한 상태로 가게 되고,
  각각의 상태고 가게 될 확률은 i/(i+j+k) 이런 식이다.
  따라서 각 상태의 기대값은 1 + (다음 상태 기대값들의 합) 이 된다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

using namespace std;

int a, b, c;
double dp[101][101][101];

double go(int a, int b, int c) {
	if (a == 100 || b == 100 || c == 100) return dp[a][b][c] = 0;
	if (dp[a][b][c] > -1) return dp[a][b][c];
	double ret = 1, tot = a + b + c;
	ret += a * go(a + 1, b, c) / tot;
	ret += b * go(a, b + 1, c) / tot;
	ret += c * go(a, b, c + 1) / tot;
	return dp[a][b][c] = ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> a >> b >> c;
	printf("%.7lf", go(a, b, c));

	return 0;
}
