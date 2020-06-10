//XOR
//segment tree with lazy propagation
/*
  XOR 연산을 해야하는 구간 쿼리를 lazy propagation으로 어떻게 처리할까?
  우선 구간 [l, r]에 전부 k를 XOR해야 한다면,
  전체구간의 값은 (r-l+1)%2 만큼만 k를 XOR하면 될 것이다.(0 or 1)
  그리고 아래에 내려줄 때는, lazy[child] 에 k만큼 XOR해주면 된다.(XOR은 누적시킬수 있기 때문에)
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

int n, m, sz=1, mode, l, r, val;
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
		update(l, r, node * 2 + 1, mid+1, noder, val);
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
			cin >> l >> r;
			l++, r++;
			cout << query(l, r, 1, 1, sz) << "\n";
		}
	}
	return 0;
}
