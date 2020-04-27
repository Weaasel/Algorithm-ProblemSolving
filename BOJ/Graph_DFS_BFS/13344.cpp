//Chess Tournament
/*
  '=' 기호로 묶인 원소들에 대해서는 같은 집합으로 표시해주고,
  '>', '<' 를 edge 관계로 보아 cycle체크를 하는 문제이다.
  cycle check는 back edge의 유무, 즉 아직 순회 path에 포함된 노드로 향하는 edge가 존재할 때 발견한 것으로 하였다.
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
#define MAX 4001
#define DIV 1000000007LL
#define INF 2000000000000000000
using namespace std;

int n, m, u, v;
char c;
bool vis[50001], chk[50001];
int par[50001];
vector<int> adj[50001];

bool dfs(int u) {
	bool flg = true;
	vis[u] = true;
	chk[u] = true;
	for (int v : adj[u]) {
		if (chk[v]) return false;
		if (vis[v]) continue;
		if (!dfs(v)) flg = false;
	}
	chk[u] = false;
	return flg;
}

typedef struct q {
	int u, v;
	char c;
}q;

int find(int u) {
	if (par[u] < 0) return u;
	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	par[v] = u;
	return;
}

vector<q> qv;

void init() {
	memset(par, -1, sizeof(par));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		cin >> u >> c >> v;
		if (c == '=') merge(u, v);
		else {
			q nq;
			nq.u = u, nq.c = c, nq.v = v;
			qv.pb(nq);
		}
	}
	int sz = qv.size();
	for (int i = 0; i < sz; i++) {
		q nq = qv[i];
		if (nq.c == '>') adj[find(nq.u)].pb(find(nq.v));
		else adj[find(nq.v)].pb(find(nq.u));
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i] && !dfs(i)) {
			cout << "inconsistent";
			return 0;
		}
	}
	cout << "consistent";
	return 0;
}
