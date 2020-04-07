//BAPC 2018 Preliminaries J. Jurassic Jigsaw
//MST, string

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
using namespace std;

int par[10001], n, m, res;

string str[1001];

vector<pair<int, pii>> adj;
vector<pii> ans;

int f(string a, string b) {
	int res = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] != b[i]) res++;
	}
	return res;
}

int find(int a) {
	if (par[a] < 0) return a;
	return par[a] = find(par[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	par[a] += par[b];
	par[b] = a;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof(par));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			adj.pb({ f(str[i], str[j]) , {i, j} });
		}
	}
	sort(adj.begin(), adj.end());

	for (int i = 0; i < adj.size(); i++) {
		pair<int, pii> tmp = adj[i];
		pii p = tmp.second;
		int c = tmp.first;
		if (merge(p.first, p.second)) {
			ans.pb(p);
			res += c;
		}
	}
	cout << res << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}
