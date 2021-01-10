//문제집 만들기
//Segment Tree, Set, Logical
/*
  어떤 문제 a를 풀기 위해 먼저 풀어야 할 문제 b가 간선정보로 정의되어 있을 때,
  구간 [x, y] 를 전부 해결할 수 있니? 의 쿼리를 처리해야 한다.
  
  세그트리의 원소를 해당 구간 부모중 {가장 작은값, 가장 큰 값} 으로 정의하면,
  가장 작은값이 x 이상이고 가장 큰 값이 y 이하면 되는 문제가 되겠다.
  
  각 문제의 선행문제들의 집합을 set으로 관리하고 이를 추가/삭제하는 연산을 적절히 구현한다.
  어떤 선후관계가 생길 때, 즉 b -> a 인 관계가 생기거나 사라질 때, b의 조상들 b1, b2, ... 에 대해
  b1 -> a, b2 -> a, ... 를 모두 연결하고 삭제해야 하는 것 아닌가? 라는 물음이 생긴다.
  
  아니다.
  우리가 우려하는 상황: b1 -> b2 -> ... -> bn -> b -> a 에서 bi ~ b 까지는 범위 안에 있는데 bi-1이 범위 밖에 있는 경우
  -> bi가 범위안에 있으므로 해당 범위 구간을 커버하는 노드에서 bi의 parent인 bi-1 의 정보가 어차피 포함된다.
  즉, 바로 위 parent까지만 반영해도 안될건 안되고 될건 된다.
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m, q, sz = 1;
set<int> s[101010];
pii seg[404040];

void init() {
	while (sz < n) sz *= 2;
}

void update(int idx, pii p) {
	idx += sz - 1;
	seg[idx] = p;
	while (idx > 1) {
		idx /= 2;
		seg[idx].x = min(seg[idx * 2].x, seg[idx * 2 + 1].x);
		seg[idx].y = max(seg[idx * 2].y, seg[idx * 2 + 1].y);
	}
	return;
}

pii query(int l, int r, int node, int nodel, int noder) {
	if (l > noder || r < nodel) return { INF, -INF };
	else if (l <= nodel && noder <= r) return seg[node];
	int mid = (nodel + noder) / 2;
	pii p1 = query(l, r, node * 2, nodel, mid);
	pii p2 = query(l, r, node * 2 + 1, mid + 1, noder);
	return { min(p1.x,p2.x), max(p1.y, p2.y) };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	init();
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		s[a].insert(b);
	}

	for (int i = 1; i <= n; i++) {
		s[i].insert(i);
		update(i, { *s[i].begin(), *s[i].rbegin() });
	}

	for (int i = 0; i < q; i++) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			pii p = query(a, b, 1, 1, sz);
			if (a <= p.x && p.y <= b) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (t == 2) {
			s[a].erase(b);
			update(a, { *s[a].begin(), *s[a].rbegin() });
		}
		else {
			s[a].insert(b);
			update(a, { *s[a].begin(), *s[a].rbegin() });
		}
	}

	return 0;
}
