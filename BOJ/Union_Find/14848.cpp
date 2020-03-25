//문명
//union-find, BFS

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

int n, k, u, v, cnt=0, res=0;
int dist[2001][2001];
pii par[2001][2001];

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };

pii unionfind(pii a) {
	if (par[a.first][a.second].first < 0) return a;
	return par[a.first][a.second] = unionfind(par[a.first][a.second]);
}

void merge(pii a, pii b) {
	a = unionfind(a);
	b = unionfind(b);
	if (a == b) return;
	pii tmp = { par[a.first][a.second].first + par[b.first][b.second].first, 0 };
	par[a.first][a.second] = b;
	par[b.first][b.second] = tmp;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cnt = k;
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = { -1, 0 };
		}
	}

	queue<pii> q;
	for (int i = 0; i < k; i++) {
		cin >> u >> v;
		dist[u][v] = 0;
		q.push({ u, v });
		for (int i = 0; i < 4; i++) {
			int nu = u + dx[i], nv = v + dy[i];
			if (nu<1 || nu>n) continue;
			if (nv<1 || nv>n) continue;
			if (dist[nu][nv] == 0) {
				merge({ u, v }, { nu, nv });
				pii tmp = unionfind({ u, v });
				res = -par[tmp.first][tmp.second].first;
			}
		}
	}
	if (res == cnt) {
		cout << 0; return 0;
	}

	while (!q.empty()) {
		pii p = q.front(); q.pop();
		u = p.first, v = p.second;
		for (int i = 0; i < 4; i++) {
			int nu = u + dx[i], nv = v + dy[i];
			if (nu<1 || nu>n) continue;
			if (nv<1 || nv>n) continue;
			if (dist[nu][nv] > -1) continue;
			cnt++;
			dist[nu][nv] = dist[u][v] + 1;
			merge({ u, v }, { nu, nv });

			q.push({ nu, nv });
			for (int j = 0; j < 4; j++) {
				int nnu = nu + dx[j], nnv = nv + dy[j];
				if (nnu<1 || nnu>n) continue;
				if (nnv<1 || nnv>n) continue;
				if (dist[nnu][nnv] == -1) continue;
				merge({ nnu, nnv }, { nu, nv });
				pii tmp = unionfind({ nu, nv });
				res = -par[tmp.first][tmp.second].first;
				if (res == cnt) {
					cout << dist[nu][nv];
					return 0;
				}
			}
		}
	}
	return 0;
}
