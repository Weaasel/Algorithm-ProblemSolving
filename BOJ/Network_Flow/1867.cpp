//돌멩이 제거
//Vertex Cover, Bipartite matching

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#define MAX 501
using namespace std;

vector<int> adj[MAX];
int A[MAX], B[MAX];
bool visited[MAX];

bool dfs(int a) {
	visited[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
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
	int n, m, a, b, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) cnt++;
		}
	}
	cout << cnt << "\n";
}
