//XOR
//segment tree with lazy propagation
/*
  lazy propagation 연습용 문제다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DIV 1000000007;
#define INF 2e9

using namespace std;

int n, m, sz = 1, mode, l, r, val;
ll seg[2000001], lazy[2000001];

void propagate(int node, int nodel, int noder) {
	if (!lazy[node]) return;
	for (int i = 0; i < (noder - nodel + 1) % 2; i++) seg[node] ^= lazy[node];
	if (nodel != noder) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	lazy[node] = 0;
	return;
}
void update(int l, int r, int node, int nodel, int noder, int val) {
	propagate(node, nodel, noder);
	if (l > noder || r < nodel) return;
	else if (l <= nodel && noder <= r) {
		for (int i = 0; i < (noder - nodel + 1) % 2; i++) seg[node] ^= val;
		if (nodel != noder) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	else {
		int mid = (nodel + noder) / 2;
		update(l, r, node * 2, nodel, mid, val);
		update(l, r, node * 2 + 1, mid + 1, noder, val);
		seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
		return;
	}
}

ll query(int l, int r, int node, int nodel, int noder) {
	propagate(node, nodel, noder);
	int mid = (nodel + noder) / 2;
	if (l > noder || r < nodel) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	else return query(l, r, node * 2, nodel, mid) ^ query(l, r, node * 2 + 1, mid + 1, noder);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (sz <= n) sz *= 2;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		update(i, i, 1, 1, sz, val);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> mode;
		if (mode == 1) {
			cin >> l >> r >> val;
			l++, r++;
			update(l, r, 1, 1, sz, val);
		}
		else {
			cin >> l;
			l++;
			cout << query(l, l, 1, 1, sz) << "\n";
		}
	}
	return 0;
}
