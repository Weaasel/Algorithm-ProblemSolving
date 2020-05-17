// C - Count Triangles	

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
#define INF 2e9
using namespace std;

ll a, b, c, d, res;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	for (int x = a; x <= b; x++) {
		ll yl = max(d + 1 - x, b);
		if (yl <= c) res += (d + 1 - c)*(c - yl + 1);

		ll yr = min(d - x, c);
		yl = max(b, c - x + 1);
		if (yr >= yl) {
			res += (x - c)*(yr - yl + 1);
			res += (yr + yl)*(yr - yl + 1) / 2;
		}
	}
	cout << res;
	return 0;
}
