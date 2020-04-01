//크루스칼의 공
//LCA, Disjoint set, MST, Offline Query
/*

Point: Tree가 아니어도 된다.
  내 처리 방식은, 최대한 MST를 만들고, MST가 만들어지지 않았다면 INF값을 갖는 edge로 이어주어 억지로 tree를 구성하는 방식이다.
  그렇게 만들어진 tree에서 Input Query u,v 에 대한 lca_query를 보내 path에서의 mxcost를 구한다.
  마지막으로 tree를 재구성하면서 해당 쿼리에서의 sz를 구한다.
  
  다른 사람들의 풀이를 보니, 전체가 tree가 아닌 forest가 되더라도, 각각에 대해서 lca를 구할 수 있으므로, 그렇게 처리했어도 됐다.
  쿼리 노드간에 lca를 구하고, "그 노드가 root일 때 subtree의 sz"를 저장할 수 있다면 offline query가 아니어도 된다.
  Offline query에 너무 집착하지 않았어도 됐을 문제.
*/


#include <iostream>
#include <cstdio>
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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000
/*
[&](Query a, Query b) {
		return a.idx > b.idx;
		}
*/
using namespace std;

typedef struct Query {
	int idx;
	int u, v;
	int mxcost;
	int ans;
};

int n, m, u, v, c, qnum;
int pre[100001][21], mx_e[100001][21], lv[100001];
vector<pii> adj[100001];
vector<pair<int, pii>> raw_adj, real_adj;
vector<Query> query;

int par[100001];

int unionfind(int a) {
	if (par[a] < 0) return a;
	return par[a] = unionfind(par[a]);
}

bool unioning(int a, int b) {
	a = unionfind(a);
	b = unionfind(b);
	if (a == b) return false;
	par[a] += par[b];
	par[b] = a;
	return true;
}

void make_tree(int u) {
	for (pii pv : adj[u]) {
		int v = pv.first;
		if (lv[v] > 0) continue;
		pre[v][0] = u;
		mx_e[v][0] = pv.second;
		lv[v] = lv[u] + 1;
		make_tree(v);
	}
}

void init_pre() {
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j <= n; j++) {
			pre[j][i] = pre[pre[j][i - 1]][i - 1];
			mx_e[j][i] = max(mx_e[j][i-1], mx_e[pre[j][i - 1]][i - 1]);
		}
	}
}

int lca(int u, int v) {
	int res = 0;
	if (lv[u] > lv[v]) swap(u, v);

	for (int i = 20; i >= 0; i--) {
		if (lv[v] - lv[u] < (1 << i)) continue;
		res = max(res, mx_e[v][i]);
		v = pre[v][i];
	}
	if (u == v) return res;
	for (int i = 20; i >= 0; i--) {
		if (pre[u][i] == pre[v][i]) continue;
		res = max(res, mx_e[u][i]);
		res = max(res, mx_e[v][i]);
		u = pre[u][i]; v = pre[v][i];
	}
	return res = max({ res, mx_e[u][0], mx_e[v][0] });;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		raw_adj.pb({ c,{ u,v } });
	}
	cin >> qnum;

	for (int i = 0; i < qnum; i++) {
		cin >> u >> v;
		Query q;
		q.idx = i;
		q.u = u; q.v = v;
		query.pb(q);
	}

	//sort adj by its cost
	sort(raw_adj.begin(), raw_adj.end());

	//make MST
	memset(par, -1, sizeof(par));
	for (int i = 0; i < raw_adj.size(); i++) {
		pii uv = raw_adj[i].second;
		u = uv.first, v = uv.second, c = raw_adj[i].first;
		if (unioning(u, v)) {
			real_adj.pb(raw_adj[i]);
			adj[u].pb({ v, c }); adj[v].pb({ u, c });
		}
	}

	//if not Tree, make Tree with INF
	vector<int> par_group;
	for (int i = 1; i <= n; i++) {
		if (par[i] < 0) par_group.pb(i);
	}
	if (par_group.size() > 1) {
		for (int i = 0; i < par_group.size() - 1; i++) {
			u = par_group[i], v = par_group[i + 1];
			unioning(u, v);
			adj[u].pb({ v, INF }); adj[v].pb({ u, INF });
		}
	}

	lv[1] = 1;
	make_tree(1);
	init_pre();

	for (int i = 0; i < qnum; i++) {
		query[i].mxcost = lca(query[i].u, query[i].v);
	}
	sort(query.begin(), query.end(), [&](Query a, Query b) {
		return a.mxcost < b.mxcost;
	});

	memset(par, -1, sizeof(par));
	int walk = 0;
	for (int i = 0; i < qnum; i++) {
		Query tmp = query[i];
		if (tmp.mxcost == INF) {
			query[i].ans = -1;
			continue;
		}
		while (walk < real_adj.size() && tmp.mxcost >= real_adj[walk].first) {
			unioning(real_adj[walk].second.first, real_adj[walk].second.second);
			walk++;
		}
		query[i].ans = -par[unionfind(tmp.u)];
	}
	sort(query.begin(), query.end(), [&](Query a, Query b) {
		return a.idx < b.idx;
	});

	for (int i = 0; i < qnum; i++) {
		if (query[i].mxcost == INF) cout << "-1\n";
		else cout << query[i].mxcost << " " << query[i].ans << "\n";
	}

	return 0;
}
