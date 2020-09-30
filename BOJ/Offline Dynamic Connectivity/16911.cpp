//그래프와 쿼리
//Offline Dynamic Connectivity, Disjoint Set with Rollback, Divide & Conquer, Stack, Segment Tree
/*
  어떤 간선을 추가해라, 제거해라, 현재시점에 어떤 두 점이 연결되어 있는지 여부를 판단하는 문제에서 사용하는 알고리즘이다.
  
  분할정복을 통해 해결한다.
  Solve(l, r, edgeset) 에서는
  timestamp [l,r] 동안 내내 살아있는 edge들에 대해 연결하고, 처리하고, 분할-정복하고, 연결을 끊는다(Rollback).
  edge set을 만드는 과정은 segment tree의 recursive update 과정과 비슷하다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef struct query {
	int type, u, v;
}query;

typedef struct edge {
	int u, v, s, e;
}edge;

vector<edge> e;
query q[404040];
map<pii, int> mp;

vector<edge> seg[404040];

int n, m, sz = 1;
int par[101010], dep[101010];
stack<pair<pii, int>> st; //{u,v},0: u에 v를 붙였다.

void update(edge e, int node, int nodel, int noder) {
	int l = e.s, r = e.e;
	if (r < nodel || l > noder) return;
	else if (l <= nodel && noder <= r) {
		seg[node].pb(e);
		return;
	}
	int mid = (nodel + noder) / 2;
	update(e, node * 2, nodel, mid);
	update(e, node * 2 + 1, mid + 1, noder);
	return;
}

int find(int u) {
	if (par[u] == u) return u;
	return find(par[u]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;

	if (dep[u] > dep[v]) {
		par[v] = u;
		st.push({ { u,v },0 });
	}
	else if (dep[u] == dep[v]) {
		par[v] = u;
		st.push({ { u,v },1 });
		dep[u]++;
	}
	else {
		par[u] = v;
		st.push({ { v,u },0 });
	}
	return true;
}

void rollback(int cnt) {
	for (int i = 0; i < cnt; i++) {
		pair<pii, int> cur = st.top(); st.pop();
		int u = cur.first.first, v = cur.first.second, type = cur.second;
		par[v] = v;
		if (type == 1) dep[u]--;
	}
	return;
}

void solve(int node, int nodel, int noder) {
	//[nodel, noder] 시간동안 내내 살아있는 간선 연결
	int cnt = 0;
	for (edge e : seg[node]) cnt += merge(e.u, e.v);

	//nodel == noder == type3 이라면 출력
	if (nodel == noder) {
		if (q[nodel].type == 3) {
			if (find(q[nodel].u) == find(q[nodel].v)) cout << "1\n";
			else cout << "0\n";
		}
		rollback(cnt);
		return;
	}

	//분할정복
	int mid = (nodel + noder) / 2;
	solve(node * 2, nodel, mid);
	solve(node * 2 + 1, mid + 1, noder);

	//연결했던거 다시 rollback
	rollback(cnt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	while (sz < m) sz *= 2;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		dep[i] = 1;
	}

	//edge u,v,s,e로 모음
	for (int i = 1; i <= m; i++) {
		cin >> q[i].type >> q[i].u >> q[i].v;

		if (q[i].u > q[i].v) swap(q[i].u, q[i].v);
		if (q[i].type == 1) mp[{q[i].u, q[i].v}] = i;
		else if (q[i].type == 2) {
			int ss = mp[{q[i].u, q[i].v}];
			e.pb({ q[i].u,q[i].v,ss,i - 1 });
			mp[{q[i].u, q[i].v}] = -1;
		}
	}
	for (pair<pii, int> it : mp) {
		pii p = it.first; int ss = it.second;
		if (ss == -1) continue;
		e.pb({ p.first,p.second,ss,m });
	}

	for (edge ee : e) update(ee, 1, 1, sz);

	solve(1, 1, sz);

	return 0;
}
