//구간합 구하기2
//segment tree with lazy propagation
/*
  lazy를 얹은 기본적인 합 세그 트리이다.
  한가지 주의할 점은 update에 쓰이는 val을 long long type으로 선언해 주어야 한다는 점 정도.
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

int n, m, k, sz=1, mode, l, r;
ll seg[4000001], lazy[4000001], val;

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
	cin >> n >> m >> k;
	while (sz <= n) sz *= 2;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		update(i, i, 1, 1, sz, val);
	}
	for (int i = 0; i < m + k; i++) {
		cin >> mode;
		if (mode == 1) {
			cin >> l >> r >> val;
			update(l, r, 1, 1, sz, val);
		}
		else {
			cin >> l >> r;
			cout << query(l, r, 1, 1, sz) << "\n";
		}
	}
	return 0;
}
