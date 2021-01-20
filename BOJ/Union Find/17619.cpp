//개구리 점프
//union find
/*
  핵심 아이디어는
  1. y좌표가 의미없다는 것이다. x좌표끼리만 겹치면 어떻게든 이동 가능하다.
  2. 정렬해두고 잘 훑으면 이웃한 직선들끼리만 판별하면 된다는 것이다.
  단순 정렬하고 시작하자. 현재 직선그룹의 최소x, 최대x를 update하면서 이동하면
  다음 직선의 x1이 mnx <= x1 <= mxx 이기만 하면 이 그룹에 들어갈 수 있다.
  이게 아니라면 새로운 그룹을 형성하게 된다.
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, q;
int par[101010];
pair<pii,int> a[101010];
map<int, int> idx;

int find(int u) {
	if (par[u] < 0) return u;
	return par[u] = find(par[u]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x.x >> a[i].x.y >> a[n].x.x;
		a[i].y = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) idx[a[i].y] = i;
	
	int l = a[0].x.x, r = a[0].x.y;
	for (int i = 1; i < n; i++) {
		int curl = a[i].x.x, curr = a[i].x.y;
		if (l <= curl && curl <= r) {
			merge(i, i - 1);
			r = max(r, curr);
		}
		else {
			l = curl, r = curr;
		}
	}

	for (int i = 1; i <= q; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		u = idx[u], v = idx[v];
		if (find(u) == find(v)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}
