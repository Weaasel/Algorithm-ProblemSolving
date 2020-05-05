//K번째 수
//Segment Tree, Merge Sort Tree

/*
  어떤 수열이 주어지고, [l, r] 구간에서 k번째 큰 수를 출력해야 하는 쿼리문이 주어진다.
  수열의 update는 없다.
  
  merge sort tree를 구현하여 해결하는 문제.
  k번째 수라는 말은,
  해당 구간에서 자기자신 이하인 수의 개수가 k인 어떤 수를 찾는 일이다.
  
  따라서 주어진 수의 upper_bound_idx를 반환하는 merge sort tree와 이분탐색을 이용해 그 수를 찾아준다.
  
  주의할 점은 수열에 없는 수도 return value가 k가 될 수 있는데,
  잘 생각해보면 answer 미만의 수는 return value로 k를 가질 수 없기에
  hi = md-1 로 hi를 줄여주면 된다.
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
#define INF 2000000000
using namespace std;

int n, q, num, l, r, k, lo, hi, md, tmp, ans;
int sz = 1;

vector<int> seg[400001];

void init() {
	for (int i = 1; i < sz; i++) sort(all(seg[i]));
}

void update(int idx, int val) {
	idx += sz - 1;
	while (idx >= 1) {
		seg[idx].pb(val);
		idx /= 2;
	}
}

int query(int val, int l, int r, int node, int nodel, int noder) {
	if (nodel > r || noder < l) return 0;
	if (nodel >= l && noder <= r) return upper_bound(all(seg[node]), val) - seg[node].begin();
	int mid = (nodel + noder) / 2;
	return query(val, l, r, node * 2, nodel, mid) + query(val, l, r, node * 2 + 1, mid+1, noder);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	while (sz < n) sz *= 2;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		update(i, num);
	}

	init();

	for (int i = 0; i < q; i++) {
		cin >> l >> r >> k;
		lo = -INF, hi = INF, ans = INF+1;
		while (lo <= hi) {
			md = (lo + hi) / 2;
			tmp = query(md, l, r, 1, 1, sz);
			if (tmp == k) {
				ans = min(ans, md);
				hi = md - 1;
			}
			else if (tmp < k) lo = md + 1;
			else hi = md - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
