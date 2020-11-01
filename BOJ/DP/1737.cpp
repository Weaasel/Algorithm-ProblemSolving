//Pibonacci
//Dynamic Programming
/*
  문제에서 주어진 식은
  1. 0 <= n <= pi 인 n에 대해 dp[n] = 1,
  2. dp[n] = dp[n-1] + do[n-pi] 이다.
  즉 n이 double형으로 들어갈 수 있게 되는 것인데, 오차범위를 생각하면 필요한 수가 너무 많아지기 때문에 map으로 관리하기는 어렵다.
  따라서 dp식을 2차원으로 관리한다.
    dp[n][cnt] = n에서 pi를 cnt 번 뺀 수의 dp값
  이렇게 하면
    dp[n][cnt] = dp[n-1][cnt] + dp[n][cnt+1] 로 표현할 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
#define pi 3.141592
const ll DIV = 1e18;

using namespace std;

int n;
ll dp[1001][330];

ll go(int n, int cnt) {
	double rem = n - pi * cnt;
	if (dp[n][cnt] > 0) return dp[n][cnt];
	if (rem <= pi) return dp[n][cnt] = 1;
	return dp[n][cnt] = (go(n - 1, cnt) + go(n, cnt + 1)) % DIV;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cout << go(n, 0);
	return 0;
}
