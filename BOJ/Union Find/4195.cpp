//친구 네트워크
//disjoint set, union find, hashing

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

int t, n, par[100001], idx;
string s1, s2;

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
	cin >> t;
	while (t--) {
		idx = 1;
		map<string, int> m;
		memset(par, -1, sizeof(par));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			if (!m[s1]) m[s1] = idx++;
			if (!m[s2]) m[s2] = idx++;

			unioning(m[s1], m[s2]);
			cout << -par[unionfind(m[s1])] << "\n";
		}
	}
	return 0;
}
