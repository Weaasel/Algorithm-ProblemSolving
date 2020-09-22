//Manhattan Mornings
/*
  주어진 2차원 좌표에서 시작점과 도착점, 내가 방문해야할 n개의 좌표들이 주어질 때,
  최소의 manhattan distance로 이동하며 방문할 수 있는 점의 최대 개수를 구하는 문제이다.
  
  dp[i]: max(dp[j]) + 1 (point[j]는 point[i]보다 좌하단에 위치한 점) 이라는 식이 세워지고,
  x-y순으로 정렬해둔 상태에서 점들을 하나씩 보며 2차원 세그 쿼리 -> 업데이트를 수행하면 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 2e10

using namespace std;
#define pii pair<int, int>
using vi = vector<int>;
using vii = vector<pii>;
using lint = long long;
const int mxn = 200020;

int n, x, y, sz, psz;
pll s, e;
ll seg[800000];
ll dp[101010];

vector<pll> points;
vector<ll> xlist, ylist;

void init() {
	xlist.pb(-INF); xlist.pb(INF);
	ylist.pb(-INF); ylist.pb(INF);
	//make x, ylist
	for (pll p : points) xlist.pb(p.first);
	sort(all(xlist));
	xlist.erase(unique(all(xlist)), xlist.end());

	for (pll p : points) ylist.pb(p.second);
	sort(all(ylist));
	ylist.erase(unique(all(ylist)), ylist.end());

	psz = points.size();
	for (int i = 0; i < psz; i++) {
		int xidx = lower_bound(all(xlist), points[i].first) - xlist.begin() + 1;
		int yidx = lower_bound(all(ylist), points[i].second) - ylist.begin() + 1;
		points[i] = { xidx,yidx };
	}

	sz = 1;
	while (sz < n + 2) sz *= 2;
}

void update(ll idx, ll val) {
	idx += sz - 1;
	seg[idx] = max(seg[idx], val);
	while (idx > 1) {
		idx /= 2;
		seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
	}
	return;
}

ll query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (l > r || nodel > r || noder < l) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	else return max(query(l, r, node * 2, nodel, mid), query(l, r, node * 2 + 1, mid + 1, noder));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s.first >> s.second >> e.first >> e.second;
	if (s.second > e.second) swap(s, e);
	bool flg = false;
	if (s.first > e.first) {
		flg = true;
		e.first = 2 * s.first - e.first;
	}
	points.pb(s);
	points.pb(e);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (flg) x = 2 * s.first - x;
		if(s.first <= x && x<=e.first && s.second <= y && y<=e.second) points.pb({ x,y });
	}
	init();

	sort(all(points));
	//x좌표 같은경우 어떻게 처리하지?
	dp[0] = 1;
	update(points[0].second, 1);
	for (int i = 1; i < psz; i++) {
		ll cury = points[i].second;
		dp[i] = query(1, cury, 1, 1, sz) + 1;
		update(cury, dp[i]);
	}

	cout << dp[psz - 1] - 2;

	return 0;
}
