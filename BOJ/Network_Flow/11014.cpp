//컨닝2
//Bipartite matching, indexing

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
#define DIV 1000000
#define INF 2000000000
using namespace std;


int dx[6] = { -1, 0, 1, -1, 0, 1 }, dy[6] = { -1, -1, -1, 1, 1, 1 };
string str;


bool dfs(bool* visited, vector<int>* adj, int* A, int* B, int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(visited, adj, A, B, B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n, m, a, b, cnt = 0;
	cin >> T;
	while (T--) {
		cnt = 0;
		map<pii, int> idx;
		vector<int> adj[MAX];
		int A[MAX], B[MAX], res = 0, wlk;
		bool visited[MAX], cls[81][81];

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == '.') {
					cls[i][j] = true;
					res++;
				}
				else cls[i][j] = false;
			}
		}

		wlk = 0;
		for (int j = 0; j < m; j += 2) {
			for (int i = 0; i < n; i++) {
				if (cls[i][j]) {
					idx[{ i, j }] = ++wlk;
				}
			}
		}
		int sz = wlk;
		wlk = 0;
		for (int j = 1; j < m; j += 2) {
			for (int i = 0; i < n; i++) {
				if (cls[i][j]) {
					idx[{ i, j }] = ++wlk;
				}
			}
		}
		for (int j = 0; j < m; j += 2) {
			for (int i = 0; i < n; i++) {
				if (!cls[i][j]) continue;
				for (int k = 0; k < 6; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni >= n) continue;
					if (nj < 0 || nj >= m) continue;
					if (!cls[ni][nj]) continue;
					adj[idx[{i, j}]].push_back(idx[{ni, nj}]);
				}
			}
		}

		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));
		for (int i = 1; i <= sz; i++) {
			if (A[i] == -1) {
				memset(visited, false, sizeof(visited));
				if (dfs(visited, adj, A, B, i)) cnt++;
			}
		}
		cout << res - cnt << "\n";
	}
}
