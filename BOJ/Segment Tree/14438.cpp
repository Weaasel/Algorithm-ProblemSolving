//minimum seg tree
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
#define INF 2000000000
using namespace std;

int n, q, num, sz, seg[400000];
int mode, a, b;

void init() {
	sz = 1;
	while (sz < n) sz *= 2;
	for (int i = 1; i <= 2 * sz; i++) seg[i] = INF;

}

void update(int idx, int val) {
	idx += sz - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
	}
	return;
}

int query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (nodel > r || noder < l) return INF;
	else if (l <= nodel && noder <= r) return seg[node];
	else return min(query(l, r, node * 2, nodel, mid), query(l, r, node * 2 + 1, mid + 1, noder));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	init();

	for (int i = 1; i <= n; i++) {
		cin >> num;
		update(i, num);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> mode >> a >> b;
		if (mode == 1) {
			update(a, b);
		}
		else {
			cout << query(a, b, 1, 1, sz) << "\n";
		}
	}

	return 0;
}
