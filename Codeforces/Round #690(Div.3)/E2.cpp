//E2 - Close Tuples (hard version)	
//Combinatorics, Two Pointers
/*
  그룹의 가장 큰 수를 고정해 둔다고 생각하자.
  그러면 그 수보다 k 이하 차이나는 수들 중에 m-1 개를 뽑으면 된다.
  이 논리를 two pointer 알고리즘으로 구현한다. 
*/

#include <bits/stdc++.h>
#define ll long long
const ll DIV = 1e9+7;

using namespace std;

ll T, n, m, k, res;
ll a[202020];
ll fact[MAX + 1], inv[MAX + 1];

ll fastpow(ll a, ll pow) {
	if (pow == 0) return 1LL;
	ll ret = fastpow(a, pow / 2);
	ret = (ret*ret) % DIV;
	return pow % 2 == 1 ? (ret*a) % DIV : ret;
}

void init() {
	fact[0] = 1;
	fact[1] = 1;
	for (ll i = 2; i <= MAX; i++) fact[i] = (fact[i - 1] * i) % DIV;
	inv[MAX] = fastpow(fact[MAX], DIV - 2);
	for (ll i = MAX - 1; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % DIV;
}

ll comb(int n, int k) {
	ll res = fact[n];
	res *= inv[k];
	res %= DIV;
	res *= inv[n - k];
	return res % DIV;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	cin >> T;
	while (T--) {
		res = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (m == 1) {
			cout << n << "\n";
			continue;
		}
		sort(a, a + n);
		int l = 0, r = 1;
		while (r < n) {
			if (l == r) r++;
			else if (a[r] - a[l] > k) l++;
			else {
				int cnt = r - l;
				if (cnt >= m - 1) res += comb(cnt, m - 1);
				res %= DIV;
				r++;
			}
		}

		cout << res << "\n";
	}

	return 0;
}
