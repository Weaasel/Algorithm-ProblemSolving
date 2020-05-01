//코끼리
/*
  코끼리가 뛸 수 있는 점들이 주어졌을 때, 밟을 수 있는 점들의 최대 개수와 그 가짓수를 구하는 문제.
  
  2차원 평면 위에 놓인 점들의 순서를 잘 매겨서 seg tree에 query->update를 반복한다.
  
  재미있는 observation은 (x,y) 점들에 대해 x에 대해 오름차순, y에 대해 내림차순으로 정렬하고 나면,
  가장 긴 증가하는 부분수열의 길이/가짓수를 구하는 문제와 같아진다.
  
  + 좌표압축은 덤. 간편하게 map을 사용해도 시간 문제는 없었다.
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
pll seg[1200000];

vector<pll> points;
map<int, int> ylist;

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
	sz = 1;
	while (sz < n) sz *= 2;

	//make ylist
	vector<ll> yy;
	for (pll p : points) yy.pb(p.second);
	sort(all(yy));
	ylist[yy[0]] = 1;
	for (int i = 1; i < n; i++) {
		if (yy[i] == yy[i - 1]) continue;
		ylist[yy[i]] = walk++;
	}
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
		cin >> x >> y;
		points.pb({ x,y });
	}
	sort(all(points));

	init();

	//x좌표 같은경우 어떻게 처리하지?
	vector<pair<ll, pll>> tmp;
	for (int i = 0; i < n; i++) {
		//p.first = 최대식물개수, p.second = 방법의 수
		pll p;
		p = query(1, ylist[points[i].second] - 1, 1, 1, sz);
		tmp.pb({ ylist[points[i].second] , p });
		if (i == n - 1 || points[i].first < points[i + 1].first) {
			for (pair<ll, pll> cur : tmp) {
				ll cury = cur.first;
				pll p = cur.second;
				if (p.first > 0) update(cury, { p.first + 1, p.second });
				else update(cury, { 1, 1 });
			}
			tmp.clear();
		}
	}
	pll res = query(1, sz, 1, 1, sz);
	cout << res.first << "\n" << res.second;
	return 0;
}
