//just small case
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

int T, n, q, s, k, l, last, r, d[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		vector<int> res;
		cin >> n >> q;
		for (int i = 1; i < n; i++) cin >> d[i];
		for (int i = 0; i < q; i++) {
			cin >> s >> k;
			l = s, r = s, last = s;
			for (int j = 0; j < k - 1; j++) {
				if (l == 1) {
					r++, last = r;
				}
				else if (r == n) {
					l--; last = l;
				}
				else if (d[l - 1] > d[r]) {
					r++, last = r;
				}
				else {
					l--; last = l;
				}
			}
			res.pb(last);
		}
		cout << "Case #" << tc << ": ";
		for (int i : res) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
