//합성함수와 쿼리
//DP, sparse table

/*
  a[n][i] : f(n)을 2^i번 반복했을 때의 도착점
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
#define DIV 1000000007LL
#define INF 2e18
#define base 100000
using namespace std;

int m, q, x, n;
int a[200001][21];

int go(int x, int n) {
	for (int i = 20; i >= 0; i--) {
		if (n >= 1 << i) {
			x = a[x][i];
			n -= 1 << i;
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i][0];
	}

	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= m; i++) {
			a[i][j] = a[a[i][j - 1]][j - 1];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> x;
		cout << go(x, n) << "\n";
	}

	return 0;
}
