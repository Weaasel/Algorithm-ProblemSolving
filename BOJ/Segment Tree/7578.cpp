//공장
/*
  나보다 앞에 나온 수들 중 나보다 큰 값을 세는 형식의 basic한 seg tree 유형.
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

int n, num, sz, seg[2000000];
int A[1000001];

ll res;

void init() {
	sz = 1;
	while (sz < n) sz *= 2;
}

void update(int idx, int val) {
	idx += sz - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
	return;
}

int query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (nodel > r || noder < l) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	else return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	init();

	for (int i = 1; i <= n; i++) {
		cin >> num;
		A[num] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> num;
		int idx = A[num];
		res += query(idx, n, 1, 1, sz);
		update(idx, 1);
	}
	cout << res;
	return 0;
}
