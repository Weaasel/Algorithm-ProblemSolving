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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int T, n, a, b, c, d, xx1, xx2, yy1, yy2, u, v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		cin >> u >> v >> xx1 >> yy1 >> xx2 >> yy2;
		if ((a > 0 || b > 0) && xx1 == xx2) cout << "NO\n";
		else if ((c > 0 || d > 0) && yy1 == yy2) cout << "NO\n";
		else if (b - a > xx2 - u || a - b > u - xx1) cout << "NO\n";
		else if (d - c > yy2 - v || c - d > v - yy1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
