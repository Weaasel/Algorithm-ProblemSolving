#include <iostream>
#define ll long long
#define MOD 1000000007
#define MAX 4000000

using namespace std;

ll fact[MAX + 1], inv[MAX + 1];

ll fastpow(ll a, ll pow) {
	if (pow == 0) return 1LL;
	ll ret = fastpow(a, pow / 2);
	ret = (ret*ret) % MOD;
	return pow % 2 == 1 ? (ret*a) % MOD : ret;
}

void init() {
	fact[0] = 1;
	fact[1] = 1;
	for (ll i = 2; i <= MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
	inv[MAX] = fastpow(fact[MAX], MOD - 2);
	for (ll i = MAX - 1; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

ll nck(int n, int k) {
	ll res = fact[n];
	res *= inv[k];
	res %= MOD;
	res *= inv[n - k];
	return res % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	int n, k;
	cin >> n >> k;
	cout << comb(n, k);
}
