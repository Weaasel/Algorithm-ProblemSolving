// A - Alarm Clock

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
#define INF 1e18
using namespace std;

ll T, n, a, b, c, d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		if (b >= a) {
			cout << b << "\n";
		}
		else {
			a -= b;
			if (d >= c) cout << -1 << "\n";
			else {
				ll times = (a-1) / (c - d) + 1;
				cout << b + times * c << "\n";
			}
		}
	}
	return 0;
}
