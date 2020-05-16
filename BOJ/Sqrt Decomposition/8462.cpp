//배열의 힘
//Mo's algorithm
//풀이가 13547(수열과 쿼리5)과 동일하다.

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
#define DIV 1000000007LL
#define INF 2e18
using namespace std;

typedef struct query {
	int l, r, idx;
	ll res;
}query;

int n, m, ql, qr, l, r, rt;
ll a[100001], res = 0;

ll cnt[1000001];
vector<query> v;

void go(int nl, int nr) {
	while (nl < l) {
		l--;
		res -= cnt[a[l]] * cnt[a[l]] * a[l];
		cnt[a[l]]++;
		res += cnt[a[l]] * cnt[a[l]] * a[l];
	}
	while (nl > l) {
		res -= cnt[a[l]] * cnt[a[l]] * a[l];
		cnt[a[l]]--;
		res += cnt[a[l]] * cnt[a[l]] * a[l];
		l++;
	}
	while (nr < r) {
		res -= cnt[a[r]] * cnt[a[r]] * a[r];
		cnt[a[r]]--;
		res += cnt[a[r]] * cnt[a[r]] * a[r];
		r--;
	}
	while (nr > r) {
		r++;
		res -= cnt[a[r]] * cnt[a[r]] * a[r];
		cnt[a[r]]++;
		res += cnt[a[r]] * cnt[a[r]] * a[r];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> ql >> qr;
		ql--, qr--;
		query q;
		q.l = ql, q.r = qr, q.idx = i;
		v.pb(q);
	}
	rt = sqrt(n) + 1;
	sort(all(v), [&](query a, query b) {
		if (a.r / rt == b.r / rt) return a.l < b.l;
		return a.r / rt < b.r / rt;
	});

	cnt[a[v[0].l]] = 1, res = a[v[0].l];
	l = r = v[0].l;
	for (int i = 0; i < m; i++) {
		go(v[i].l, v[i].r);
		v[i].res = res;
	}
	
	sort(all(v), [&](query a, query b) {
		return a.idx < b.idx;
	});

	for (auto q : v) {
		cout << q.res << "\n";
	}
	return 0;
}
