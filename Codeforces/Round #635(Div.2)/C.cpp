// C - Linova and Kingdom	

/*
일단 그리디하게 어떤 노드를 industry로 선택하려면 그 노드의 child들은 이미 다 선택된 상태여야 한다. 따라서 나를 선택한다는 얘기는	
나로부터 root까지 가는길에 방문하는 tourism 수(lev[i]) - 내가 tourism에서 industry로 바뀜으로서 내 child들의 path상에 1개씩 손해(childs[i])
가 된다.
  => happiness[i] = lev[i] - childs[i];
따라서 이것들을 전처리해놓고 happiness가 높은순으로 sort하여 k개만큼 선택하면 된다..
코드상에 dfs식으로 구현한 것은 그냥 연습삼아 한 것이다.
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
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;
ll n, k, u, v;
vector<int> adj[200001];

ll pre[200001], lv[200001], a[200001], childs[200001];
bool isind[200001];

struct vertex {
	int idx;
	ll lv;
	ll childs;
}vertex;

vector<struct vertex> vv;

bool cmp(struct vertex aa, struct vertex bb) {
	if (lv[aa.idx] == lv[bb.idx]) {
		return childs[aa.idx] < childs[bb.idx];
	}
	return lv[aa.idx] - childs[aa.idx] > lv[bb.idx] - childs[bb.idx];
}

void make_tree(int u) {
	for (int v : adj[u]) {
		if (lv[v] > 0) continue;
		pre[v] = u;
		lv[v] = lv[u] + 1;
		make_tree(v);
	}
}

int init_child(int u) {
	ll res = 1;
	for (int v : adj[u]) {
		if (v == pre[u]) continue;
		res += init_child(v);
	}
	return childs[u] = res;
}

pll f(int u) {
	//first가 답, second가 나root subtree의 ind 개수
	pll res = { 0, 0 };

	for (int v : adj[u]) {
		if (v == pre[u]) continue;
		pll tmp = f(v);
		res.first += tmp.first;
		res.second += tmp.second;
	}
	if (isind[u]) {
		res.second++;
		return res;
	}
	else {
		res.first += res.second;
		return res;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	lv[1] = 1;
	make_tree(1);
	init_child(1);

	for (int i = 1; i <= n; i++) {
		vv.pb({ i, lv[i], childs[i] });
	}
	sort(vv.begin(), vv.end(), cmp);

	for (int i = 0; i < k; i++) {
		isind[vv[i].idx] = true;
	}

	cout << f(1).first;
	return 0;
}
