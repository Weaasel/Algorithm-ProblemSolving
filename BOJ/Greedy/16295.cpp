//BAPC 2018 Preliminaries C. Criss-Cross Cables
//Greedy, priority_queue

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
#define INF 200000000000000000
#define MAX_SIZE 4000000

using namespace std;

int n, m;
int pt[500001], len[500001];
map<pii, int> vis;

int dist(pii p) {
	return abs(pt[p.first] - pt[p.second]);
}

struct cmp {
	bool operator()(pii a, pii b) {
		return dist(a) > dist(b);
	}
};

priority_queue<pii, vector<pii>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> pt[i];
	}
	sort(pt, pt + n);
	for (int i = 0; i < m; i++) {
		cin >> len[i];
	}
	sort(len, len + m);

	for (int i = 0; i < n - 1; i++) {
		pq.push({ i, i + 1 });
		vis[{i, i + 1}] = 1;
	}

	for (int i = 0; i < m; i++) {
		if (pq.empty()) {
			cout << "no";
			return 0;
		}
		pii p = pq.top(); pq.pop();
		if (len[i] < dist(p)) {
			cout << "no";
			return 0;
		}
		else {
			int l = min(p.first, p.second);
			int r = max(p.first, p.second);
			if (l - 1 >= 0 && !vis[{l - 1, r}]) {
				pq.push({ l - 1, r });
				vis[{l - 1, r}] = 1;
			}
			if (r + 1 < n  && !vis[{l, r + 1}]) {
				pq.push({ l, r + 1 });
				vis[{l, r + 1}] = 1;
			}
		}
	}
	cout << "yes";
	return 0;
}
