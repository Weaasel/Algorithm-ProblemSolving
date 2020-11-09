//Guest Student

#include<bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e9 + 7;
const ll DIV = 1e9 + 7;

int t, k, a[7];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> k;
		int cnt = 0;
		for (int i = 0; i < 7; i++) {
			cin >> a[i];
			cnt += a[i];
		}
		if (k%cnt == 0) {
			int res = (k-cnt) / cnt * 7;
			int cand = 20;
			for (int i = 0; i < 7; i++) {
				int wlk = i, tmp = 0, rem = cnt;
				while (rem) {
					rem -= a[wlk];
					tmp++;
					wlk = (wlk + 1) % 7;
				}
				cand = min(cand, tmp);
			}
			cout << res + cand << "\n";
		}
		else {
			int res = k / cnt * 7;
			int cand = 20;
			for (int i = 0; i < 7; i++) {
				int wlk = i, tmp = 0, rem = k - k / cnt * cnt;
				while (rem) {
					rem -= a[wlk];
					tmp++;
					wlk = (wlk + 1) % 7;
				}
				cand = min(cand, tmp);
			}
			cout << res + cand << "\n";
		}
	}

	return 0;
}
