//D - Multiset	
/*
  세그먼트 트리에서의 kth element 찾기 문제로 환원 가능했던 문제.
  memory limit이 28MB이고, n이 1,000,000 이하이기 때문에,
  seg tree 배열을 int type으로 잡으면 통과하고, long long tpye으로 잡으면 통과하지 못하는 이상한 문제였다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 1e9
#define eps 1e-9
#define PI 3.14159265
using namespace std;

int n, q, a, k, sz = 1;
int seg[4000001];
void update(int idx, int val) {
	idx += sz - 1;
	seg[idx] += val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
	return;
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
	cin >> n >> q;
	while (sz < n) sz *= 2;
	for (int i = 0; i < n; i++) {
		cin >> a;
		update(a, 1);
	}

	for (int i = 0; i < q; i++) {
		cin >> k;
		if (k > 0) update(k, 1);
		else {
			int val = find(-k);
			update(val, -1);
		}
	}
	int res = -1;
	for (int i = sz; i < sz + n; i++) if (seg[i] != 0) res = i - sz + 1;
	if (res == -1) cout << 0;
	else cout << res;

	return 0;
}
