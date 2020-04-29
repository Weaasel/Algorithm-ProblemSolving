//중앙값 측정
/*
  seg tree에 counting이 들어갈 때, 주어진 등수의 값이 얼마냐? 라는 find 쿼리를 해결하는 문제.
  find 함수의 구현이 복잡하지 않다.
  
  표현하고 싶은 rank가 왼쪽, 아래쪽 노드 중 어디에 속하는지 판단하고 leaf 노드에 다다를 때까지 내리는 이다.
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

int n, k, sz, a[250001], seg[65537 * 4];

ll res = 0;

void update(int idx, int val) {
	idx += sz - 1;
	seg[idx] += val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
	return;
}

void init() {
	sz = 1;
	while (sz < 65537) sz *= 2;
}

int query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (nodel > r || noder < l) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	else return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

int find(int rank) {
	int idx = 1;
	while (idx < sz) {
		if (seg[idx * 2] >= rank) idx = idx * 2;
		else {
			rank -= seg[idx * 2];
			idx = idx * 2 + 1;
		}
	}
	return idx - sz + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]++;
	}
	for (int i = 1; i <= k; i++) {
		update(a[i], 1);
	}
	for (int i = k + 1; i <= n; i++) {
		res += find((k + 1) / 2);
		update(a[i - k], -1);
		update(a[i], 1);
	}
	res += find((k + 1) / 2);
	res -= n - k + 1;
	cout << res;
	return 0;
}
