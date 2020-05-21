//Youtube
//DP, sparse table
/*
  a[n][i] : n에서 시작해서 2^i분이 지났을 때 추천영상
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

int n, m, k;
int a[100001][31], b[100001];

int go(int x, int n) {
	for (int i = 30; i >= 0; i--) {
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
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i][0];
	}

	for (int j = 1; j < 31; j++) {
		for (int i = 1; i <= k; i++) {
			a[i][j] = a[a[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < n; i++) cout << go(b[i], m - 1) << " ";
	return 0;
}
