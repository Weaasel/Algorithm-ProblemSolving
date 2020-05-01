//가장 긴 증가하는 부분수열 6
//segment tree, grid compression

/*
  값에 대한 각 노드마다 그 값에서의 최대 LIS길이, 개수를 저장하고,
  query문에서는 해당 구간에서 최대 LIS 길이와 개수를 return할 수 있게 구현해준다.
  
  + 좌표압축은 덤. 여러 기법들 중 map을 사용하면 시간초과가 나기 때문에 lower_bound를 이용해야 한다.
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

int n, x, y, sz, walk = 2;
pll seg[4000000];

vector<ll> yy;
vector<ll> ylist;

void update(ll idx, pll p) {
	idx += sz - 1;
	if (seg[idx].first == p.first) seg[idx].second = (seg[idx].second + p.second) % DIV;
	else seg[idx] = seg[idx].first > p.first ? seg[idx] : p;
	while (idx > 1) {
		idx /= 2;
		pll p1 = seg[2 * idx], p2 = seg[2 * idx + 1];
		if (p1.first == p2.first) seg[idx] = { p1.first, (p1.second + p2.second) % DIV };
		else seg[idx] = p1.first > p2.first ? p1 : p2;
	}
	return;
}

void init() {
	ylist = yy;
	sort(all(ylist));
	ylist.erase(unique(all(ylist)), ylist.end());

	sz = 1;
	while (sz < n) sz *= 2;
}

pll query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (l > r || nodel > r || noder < l) return { 0, 0 };
	else if (l <= nodel && noder <= r) return seg[node];
	else {
		pll p1 = query(l, r, node * 2, nodel, mid), p2 = query(l, r, node * 2 + 1, mid + 1, noder);
		if (p1.first == p2.first) return { p1.first, (p1.second + p2.second) % DIV };
		else return p1.first > p2.first ? p1 : p2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y;
		yy.pb(y);
	}
	init();
	vector<pair<ll, pll>> tmp;
	for (int i = 0; i < n; i++) {
		pll p;
		ll idx = 1 + (lower_bound(ylist.begin(), ylist.end(), yy[i]) - ylist.begin());

		p = query(1, idx - 1, 1, 1, sz);
		ll cury = idx;
		if (p.first > 0) update(cury, { p.first + 1, p.second });
		else update(cury, { 1, 1 });
	}
	pll res = query(1, sz, 1, 1, sz);
	cout << res.first << " " << res.second;
	return 0;
}
