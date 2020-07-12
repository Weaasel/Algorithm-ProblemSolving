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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int T, n;
int a[10001], val[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		memset(val, 0, sizeof(val));
		for (int i = 0; i < n; i++) cin >> a[i];
		int mn = 0, mx = 0, cnt = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) val[i] = val[i - 1] + 1;
			else if (a[i] < a[i - 1]) val[i] = val[i - 1] - 1;
			else val[i] = val[i - 1];
			mn = min(mn, val[i]);
			mx = max(mx, val[i]);
			if (mx - mn < 4) continue;
			else {
				cnt++;
				val[i] = 0, mn = 0, mx = 0;
			}
		}
		cout << "Case #" << tc << ": " << cnt << "\n";
	}
	return 0;
}
