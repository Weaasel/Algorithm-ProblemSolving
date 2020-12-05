//Social Distancing
//Parametric search
/*
  소들의 최소거리를 D로 정하고 이 거리 D가 valid한지에 대한 검사를 앞에서부터 최대한 배치해가며 파라메트릭서치한다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
const ll INF = 1e18 + 7;

using namespace std;

int n, m;
pll range[101010];
ll s[101010], e[101010], res = 1;

bool chk(ll d) {
	ll cnt = n;
	ll prv = -INF;
	for (int i = 0; i < m; i++) {
		ll st = max(prv + d, s[i]);
		if (st > e[i]) continue;
		ll t = (e[i] - st) / d + 1;
		cnt -= t;
		if (cnt <= 0) return true;
		prv = st + (t - 1)*d;
	}
	return cnt <= 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> range[i].x >> range[i].y;
	sort(range, range + m);
	for (int i = 0; i < m; i++) {
		s[i] = range[i].x;
		e[i] = range[i].y;
	}

	ll l = 1, r = INF, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			res = max(res, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << res;
	return 0;
}
