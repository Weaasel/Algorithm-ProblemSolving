//H - Binary Median	

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
#define DIV 100000LL
#define INF 1e9

using namespace std;

int T, n, m;
string s;
vector<ll> v;
ll conv(string s) {
	ll res = 0, pow = 1;
	for (int i = m - 1; i >= 0; i--) {
		if (s[i] == '1') res += pow;
		pow *= 2LL;
	}
	return res;
}
void print(ll a) {
	vector<char> v(m);
	for (int i = 0; i < m; i++) {
		v[i] = '0';
		if (a >= 1LL << (m - 1 - i)) {
			v[i] = '1';
			a -= 1LL << (m - 1 - i);
		}
	}
	for (int i = 0; i < m; i++) cout << v[i];
	cout << "\n";
	return;
}

bool chk(ll a) {
	ll th = ((1LL << m) - n - 1) / 2;
	ll res = a;
	res -= upper_bound(all(v), a) - v.begin();
	return th > res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.pb(conv(s));
		}
		sort(all(v));
		ll l = 0, r = 1LL << 61;
		while (l <= r) {
			ll mid = (l + r) / 2;
			if (chk(mid)) l = mid + 1;
			else r = mid - 1;
		}
		print(l);
	}
	return 0;
}
