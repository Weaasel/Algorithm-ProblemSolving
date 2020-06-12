//스위치
//segment tree with lazy propagation
/*
  어떤 구간의 스위치를 반전시키는 것은
  해당 구간에 존재하는 '켜진 스위치'와 '꺼진 스위치'의 개수가 서로 뒤바뀐다는 말이 된다.
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
const ll INF = 1e18;
using namespace std;

int n, m, sz = 1, l, r, mode;
int seg[400001], lazy[400001];

void propagate(int node, int nodel, int noder) {
	if (!lazy[node]) return;
	seg[node] = (noder - nodel + 1) - seg[node];
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
		seg[node] = (noder - nodel + 1) - seg[node];
		if (nodel != noder) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	else {
		int mid = (nodel + noder) / 2;
		update(l, r, node * 2, nodel, mid, val);
		update(l, r, node * 2 + 1, mid+1, noder, val);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
		return;
	}
}

ll query(int l, int r, int node, int nodel, int noder) {
	propagate(node, nodel, noder);
	int mid = (nodel + noder) / 2;
	if (l > noder || r < nodel) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	else return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (sz <= n) sz *= 2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> mode >> l >> r;
		if (mode == 0) {
			update(l, r, 1, 1, sz, 1);
		}
		else {
			cout << query(l, r, 1, 1, sz) << "\n";
		}
	}
	return 0;
}
