//하늘에서 떨어지는 1, 2, ..., R-L+1개의 별
//Segment tree with Lazy Propagation
/*
  쿼리로 주어지는 [L, R] 구간에 1,2,3,...,R-L+1 을 더해야 한다.
  L~R에 +1, R+1에 -(R-L+1) 을 해두고 prefix sum을 하면 올바른 답을 구할 수 있다.
  prefix sum은 online이므로 seg tree의 힘을 빌린다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

using namespace std;

ll n, q, sz = 1, a[101010];
ll seg[400001], lazy[400001];

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

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	n++;
	for (; sz < n; sz <<= 1);
	for (int i = 0; i < q; i++) {
		int type; cin >> type;
		if (type == 1) {
			int l, r; cin >> l >> r;
			update(l, r, 1, 1, sz, 1);
			update(r + 1, r + 1, 1, 1, sz, -(r - l + 1));
		}
		else {
			int idx; cin >> idx;
			cout << query(1, idx, 1, 1, sz) + a[idx] << "\n";
		}
	}
	return 0;
}
