//세부
//disjoint set, union find, MST

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
#define MAX 
#define DIV 1000000
#define INF 2000000000

using namespace std;

int n, m, s, e, par[100001], u, v, w;
vector<pair<int, pii>> adj;

int unionfind(int a) {
	if (par[a] < 0) return a;
	return par[a] = unionfind(par[a]);
}

void unioning(int a, int b) {
	a = unionfind(a);
	b = unionfind(b);
	if (a == b) return;
	par[a] += par[b];
	par[b] = a;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof(par));
	cin >> n >> m >> s >> e;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj.pb({ w, {u,v } });
	}
	sort(adj.begin(), adj.end());
	int sz = adj.size() - 1;
	while (sz >= 0) {
		pair<int, pii> tmp = adj[sz];
		int a = tmp.second.first, b = tmp.second.second;
		unioning(a, b);
		if (unionfind(s) == unionfind(e)) {
			cout << tmp.first;
			return 0;
		}
		sz--;
	}
	cout << 0;
	return 0;
}
