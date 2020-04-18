//트리
//Offline query, disjoint set

/*
  문제에서 주어지는 쿼리를 반대로 수행하면 쉽게 해결할 수 있다.
  뒤에서부터 봤을 때, 간선을 제거하는 쿼리를 반대로 간선을 연결해준다고 생각하고,
  질의쿼리에 대해 현재까지 형성된 그래프를 가지고 답을 낸다.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;
int pre[200001];
int par[200001];

int find(int a) {
	if (par[a] < 0) return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[a] = b;
	return;
}

struct Q {
	int idx;
	int x;
	int u;
	int v;
	string res;
};
vector<Q> query;
int n, q, u, v, x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof(par));
	cin >> n >> q;
	for (int i = 2; i < n + 1; i++) {
		cin >> v;
		pre[i] = v;
	}
	for (int i = 0; i < n - 1 + q; i++) {
		cin >> x;
		if (x == 0) {
			cin >> u;
			query.pb({ i, x, u, -1, "" });
		}
		else {
			cin >> u >> v;
			query.pb({ i, x, u, v, "" });
		}
	}
	sort(all(query), [&](Q a, Q b) {
		return a.idx > b.idx;
	});

	for (int i = 0; i < query.size();i++) {
		Q q = query[i];
		if (q.x == 0) {
			merge(q.u, pre[q.u]);
		}
		else {
			if (find(q.u) == find(q.v)) query[i].res = "YES\n";
			else query[i].res = "NO\n";
		}
	}
	sort(all(query), [&](Q a, Q b) {
		return a.idx < b.idx;
	});

	for (Q q : query) {
		if (q.x == 0) continue;
		else cout << q.res;
 	}

	return 0;
}
