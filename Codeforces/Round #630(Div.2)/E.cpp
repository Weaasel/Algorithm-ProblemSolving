//E. Height All the Same

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
#define DIV 998244353LL
#define INF 2000000000

using namespace std;

ll n, m, l, r, a, b;

ll go(ll n, ll pow) {
	if (n%DIV == 0) return 0;
	if (pow == 0) return 1LL;
	ll tmp = go(n, pow / 2);
	ll res = (tmp * tmp) % DIV;
	if (pow % 2 == 1) return (n*res) % DIV;
	else return res % DIV;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> l >> r;
	a = (r - l + 1) / 2;
	b = (r - l + 1) - (r - l + 1) / 2;
	ll pow = (n*m) % (DIV - 1);
	if (n*m % 2 == 1) {
		cout << (go(a + b, pow)) % DIV;
	}
	else {
		ll res = go(a + b, pow);
		res += go(abs(a - b), pow);
		res %= DIV;
		res *= go(2, DIV - 2);
		cout << res % DIV;
	}
	return 0;
}
