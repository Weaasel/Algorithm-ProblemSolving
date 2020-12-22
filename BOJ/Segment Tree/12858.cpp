//Range GCD
//Segment Tree with Lazy Propagation, mathematics
/*
  주어진 구간에 동일한 값을 더하는 연산, 구간에 있는 수들의 gcd를 구하는 연산을 수행해야 한다.
  
  gcd(a1, a2, a3, ...an) = gcd(a1, a2-a1, a3-a2, a4-a3, ... , an - an-1) 의 성질을 이용한다.
  유클리드 호제법을 이용한 증명을 해보길 바란다.
  
  이러면 시작점이 몇인지, 인접한 수들간의 차이가 몇인지만 유지하고 있으면 된다.
  각 인덱스의 정확한 값을 유지하는 자료구조는 segment tree with lazy propagation을 활용한다.
  인접한 수들간의 차이는 구간에 수를 더할 때 양 끝의 경계값만이 달라지므로,
  gcd segment tree를 활용한다.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, q, sz = 1, A[101010];
ll seg[400001], lazy[400001], diff[400001];

ll gcd(ll a, ll b) {
	if (a < 0 || b < 0) return gcd(abs(a), abs(b));
	if (a < b) swap(a, b);
	if (!b) return a;
	return gcd(b, a%b);
}

void init() {
	sz = 1;
	while (sz < n) sz *= 2;
}

void propagate(int node, int nodel, int noder) {
	if (!lazy[node]) return;
	seg[node] += lazy[node] * (noder - nodel + 1);
	if (nodel != noder) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
	return;
}

void update(int l, int r, int node, int nodel, int noder, ll val) {
	propagate(node, nodel, noder);
	if (l > noder || r < nodel) return;
	else if (l <= nodel && noder <= r) {
		seg[node] += val * (noder - nodel + 1);
		if (nodel != noder) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (nodel + noder) / 2;
	update(l, r, node * 2, nodel, mid, val);
	update(l, r, node * 2 + 1, mid + 1, noder, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	return;
}

ll query(int l, int r, int node, int nodel, int noder) {
	propagate(node, nodel, noder);
	if (l > noder || r < nodel) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	int mid = (nodel + noder) / 2;
	return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

void gcd_update(int idx, ll val) {
	idx += sz - 1;
	diff[idx] += val;
	while (idx > 1) {
		idx /= 2;
		diff[idx] = gcd(diff[2 * idx], diff[2 * idx + 1]);
	}
	return;
}

ll gcd_query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (nodel > r || noder < l) return 0;
	else if (l <= nodel && noder <= r) return diff[node];
	else return gcd(gcd_query(l, r, node * 2, nodel, mid) , gcd_query(l, r, node * 2 + 1, mid + 1, noder));
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		update(i, i, 1, 1, sz, A[i]);
	}
	for (int i = 1; i < n; i++) 
		gcd_update(i, A[i + 1] - A[i]);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 0) {
			if (a == b) cout << query(a, a, 1, 1, sz) << "\n";
			else {
				ll g = gcd_query(a, b - 1, 1, 1, sz);
				cout << gcd(g, query(a, a, 1, 1, sz)) << "\n";
			}
		}
		else {
			update(a, b, 1, 1, sz, t);
			if (a > 1) gcd_update(a - 1, t);
			if (b < n) gcd_update(b, -t);
		}
	}
	return 0;
}
