//PPC 2019. Delicious Pineapple Pizza
//XOR의 minimum을 maximize하는 문제. 따라서 이진탐색으로 min_XOR value를 고정하고, XOR했을 때 그 값 이상을 가지는 점들끼리만 연결하여 이분매칭을 했을 때 N개의 pair가 되어야 함.


#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using lint = long long;
using ii = pair<int, int>;

bitset<101> vis;
int b[101], N;
lint A[101], B[101];

bool dfs(int cur, vector<vector<int>> &adj) {
	if (vis[cur]) return false;
	vis[cur] = 1;
	for (int&nxt : adj[cur]) {
		if (b[nxt] == -1 || dfs(b[nxt], adj)) {
			b[nxt] = cur;
			return true;
		}
	}

	return false;
}

int solve(lint h) {
	vector<vector<int> > adj;
	vis.reset();
	adj.resize(N + 1);
	int ret = 0;
	memset(b, -1, sizeof b);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((A[i] ^ B[j]) >= h) adj[i].push_back(j);
		}	
	}
	
	for (int i = 0; i < N; i++) {
		vis.reset();
		if (dfs(i, adj)) ret++;
	}

	if (ret == N) return 1;
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(A, A + N), sort(B, B + N);
	lint lo = 0, hi = 3e9, ans = 0;
	while (lo <= hi) {
		lint mid = (lo + hi) / 2;
		if (solve(mid)) {
			ans = max(ans, mid);
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << ans;
	return 0;
}
