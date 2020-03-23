//축사 배정
//Bipartite matching

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
using namespace std;

vector<int> adj[201];
int A[201], B[201];
bool visited[201];

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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, num, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> k;
			adj[i].push_back(k - 1);
		}
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	for (int i = 0; i < n; i++) {
		if (A[i] == -1) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) cnt++;
		}
	}
	cout << cnt;
}
