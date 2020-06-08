//수열과 쿼리1
//segment tree, merge sort tree
/*
  100,000개의 수열이 주어지고, 어떤 구간에서 어떤 수보다 큰 수의 개수를 출력하는 100,000개의 쿼리를 처리해야 한다.
  전형적인 merge-sort tree문제로, segment tree의 각 인덱스를 integer가 아닌 vector로서 저장한다면,
  upper_bound의 연산으로 각 구간에서 k 초과인 수의 개수를 log(구간크기) 에 연산이 가능하다.
  
  시간복잡도 : O(n(logn)^2)
  공간복잡도 : nlogn
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
#define INF 1e9

using namespace std;

int n, m, num, l, r, k, sz = 1;
vector<int> seg[400001];

void update(int idx, int val) {
	idx += sz - 1;
	seg[idx].pb(val);
	while (idx > 1) {
		idx /= 2;
		seg[idx].pb(val);
	}
	return;
}

int query(int l, int r, int node, int nodel, int noder, int val) {
	if (noder < l || r < nodel) return 0;
	else if (l <= nodel && noder <= r) {
		return (seg[node].end() - upper_bound(all(seg[node]), k));
	}
	return query(l, r, node * 2, nodel, (nodel + noder) / 2, val) + query(l, r, node * 2 + 1, (nodel + noder) / 2 + 1, noder, val);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (sz <= n) sz *= 2;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		update(i, num);
	}
	for (int i = 1; i < sz; i++) sort(all(seg[i]));
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> k;
		cout << query(l, r, 1, 1, sz, k) << "\n";
	}
	return 0;
}
