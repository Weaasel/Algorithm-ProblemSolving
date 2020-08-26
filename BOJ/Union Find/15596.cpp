//Mootube(Gold)
//Union Find, Offline Query

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

int n, m, u, v, w, par[100001];
vector<pair<int, pii>> adj;
vector<pii> query;
vector<int> qidx;
vector<int> ans;

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

bool cmp(int a, int b) {
	return query[a].first > query[b].first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof(par));
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		adj.pb({ w, {u,v } });
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		query.pb({ u, v });
		qidx.pb(i);
		ans.pb(0);
	}
	sort(adj.begin(), adj.end());
	sort(qidx.begin(), qidx.end(), cmp);
	int adj_wlk = adj.size() - 1, q_wlk = 0, k = 0;
	while (q_wlk < m) {
		int cur_k = query[qidx[q_wlk]].first;
		if (k != cur_k) {
			k = cur_k;
			while (adj_wlk >= 0 && adj[adj_wlk].first >= cur_k) {
				pair<int, pii> tmp = adj[adj_wlk];
				int a = tmp.second.first, b = tmp.second.second;
				unioning(a, b);
				adj_wlk--;
			}
		}
		ans[qidx[q_wlk]] = -par[unionfind(query[qidx[q_wlk]].second)] - 1;
		q_wlk++;
	}

	for (int a : ans) cout << a << "\n";
	return 0;
}
