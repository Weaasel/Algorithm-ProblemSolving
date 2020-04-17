//주사위 게임
/*
  n개의 사탕을 얻기 위해 주사위를 던져야할 횟수의 기대값을 f(n)이라 하자.
  f(n) = 1 + (f(n-1) + f(n-2) + ... + f(n-6))/6 이 성립한다.
*/

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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int n;
double dp[1000001];

double go(int n) {
	if (n <= 0) return 0;
	if (dp[n] > -1) return dp[n];
	double res = 1;
	for (int i = 1; i <= 6; i++) {
		res += go(n - i) / 6;
	}
	return dp[n] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	printf("%.9lf", go(n));
	return 0;
}
