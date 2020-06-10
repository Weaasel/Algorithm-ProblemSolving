//Counting Haybales
//segment tree with lazy propagation
/*
  세 종류의 쿼리를 처리해야 한다.
  1. 구간에 더하기
  2. 구간의 최소값
  3. 구간의 합
  
  1,3번 쿼리는 구간합구하기2 문제와 동일하다.
  2번 쿼리는 "어떤 구간에 전부 val씩 더하면, 해당 구간의 min값 역시 val이 더해진다."는 논리로 해결 가능하다.
  이에 맞게 lazy배열을 잘 propagate해 나가면 된다.
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

int n, m, sz = 1, l, r;
char mode;
ll val;
ll min_seg[800001], sum_seg[800001], lazy[800001];

void propagate(int node, int nodel, int noder) {
	if (!lazy[node]) return;
	min_seg[node] += lazy[node];
	sum_seg[node] += lazy[node] * (noder - nodel + 1);
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
		min_seg[node] += val;
		sum_seg[node] += val * (noder - nodel + 1);
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
		min_seg[node] = min(min_seg[node * 2], min_seg[node * 2 + 1]);
		sum_seg[node] = sum_seg[node * 2] + sum_seg[node * 2 + 1];
		return;
	}
}

ll min_query(int l, int r, int node, int nodel, int noder) {
	propagate(node, nodel, noder);
	int mid = (nodel + noder) / 2;
	if (l > noder || r < nodel) return INF;
	else if (l <= nodel && noder <= r) return min_seg[node];
	else return min(min_query(l, r, node * 2, nodel, mid), min_query(l, r, node * 2 + 1, mid + 1, noder));
}

ll sum_query(int l, int r, int node, int nodel, int noder) {
	propagate(node, nodel, noder);
	int mid = (nodel + noder) / 2;
	if (l > noder || r < nodel) return 0;
	else if (l <= nodel && noder <= r) return sum_seg[node];
	else return sum_query(l, r, node * 2, nodel, mid) + sum_query(l, r, node * 2 + 1, mid + 1, noder);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (sz <= n) sz *= 2;
	for (int i = 1; i <= n; i++) {
		cin >> val;
		update(i, i, 1, 1, sz, val);
	}
	for (int i = 0; i < m; i++) {
		cin >> mode;
		if (mode == 'M') {
			cin >> l >> r;
			cout << min_query(l, r, 1, 1, sz) << "\n";
		}
		else if (mode == 'P') {
			cin >> l >> r >> val;
			update(l, r, 1, 1, sz, val);
		}
		else {
			cin >> l >> r;
			cout << sum_query(l, r, 1, 1, sz) << "\n";
		}
	}
	return 0;
}
