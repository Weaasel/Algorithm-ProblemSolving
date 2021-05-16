//토르의 여행
//Tree, Data structure

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const int INF = 1e9 + 7;

using namespace std;

int n, q;
ll a[404040];
map<ll, ll> m[404040]; //i에서 출발한 경로

void go(int idx) {
	if (idx >= (1 << n)) return;
	go(idx * 2);
	go(idx * 2 + 1);
	m[idx][a[idx]]++;
	for (pll p : m[idx * 2]) 
		m[idx][p.x + a[idx]] += p.y;
	for (pll p : m[idx * 2 + 1])
		m[idx][p.x + a[idx]] += p.y;
	return;
}

ll f(int idx, ll d) {
	ll ret = 0;
	if (m[idx].find(d) != m[idx].end()) ret += m[idx][d];
	while (idx > 1) {
		d -= a[idx];
		int sgn = idx % 2; idx /= 2;
		if (d == a[idx]) ret++;
		int tidx = idx * 2 + (1 - sgn);
		if (m[tidx].find(d - a[idx]) != m[tidx].end()) ret += m[tidx][d - a[idx]];
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < (1 << n); i++) cin >> a[i];
	go(1);
	
	cin >> q;
	for (int i = 0; i < q; i++) {
		int idx;
		ll d;
		cin >> idx >> d;
		cout << f(idx, d) << "\n";
	}

	return 0;
}
