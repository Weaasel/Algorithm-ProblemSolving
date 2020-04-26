//C - Yet Another Counting Problem

/*
  [l, r] 구간에 대해 무언가를 구할 때,
  f(r) - f(l-1) 식으로 구현하는 간단한 기법을 놓쳐 어렵게 구현한 문제.
*/

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
#define MAX 4001
#define DIV 1000000007LL
#define INF 2000000000000000000
using namespace std;

ll T, a, b, q, l, r;

ll chk[40001];

ll gcd(ll x, ll y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x%y);
}

ll solve(ll l, ll r) {
	ll lcm = (a * b / gcd(a, b));
	ll res = 0;
	ll tmp = r - l + 1;

	if (l%lcm != 0) {
		res += chk[lcm - 1] - chk[l%lcm - 1];
		l += lcm - (l%lcm);
	}
	if (r%lcm != lcm - 1) {
		res -= chk[lcm - 1] - chk[r%lcm];
		r += lcm - 1 - (r%lcm);
	}
	if (r > l) res += ((r - l + 1) / lcm) * chk[lcm - 1];
	return tmp - res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> q;
		memset(chk, false, sizeof(chk));
		ll lcm = a * b / gcd(a, b);

		for (int i = 0; i < lcm; i++) {
			if ((i%a) % b == (i%b) % a) {
				chk[i] = 1;
			}
			if (i > 0) chk[i] += chk[i - 1];
		}
		vector<ll> res;
		for (int i = 0; i < q; i++) {
			cin >> l >> r;
			res.pb(solve(l, r));
		}
		for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
		cout << "\n";
	}
	return 0;
}
