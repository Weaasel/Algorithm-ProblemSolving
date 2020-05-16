//Superdoku
//Bipartite matching
/*
  kth row까지 주어진 superdoku가 valid한지 판단하는 것은 어렵지 않다. row/col에 겹치는 수가 있는지를 검사하면 된다.
  valid하다면, (k+1)th row부터 superdoku를 채워나간다.
  
  채워나갈 때는 각 column에 올 수 있는 숫자들의 후보(이전 row들의 해당 col에서 나오지 않은 수들) 과 인접관계를 연결하는 그래프를 만들고,
  이 그래프에 대해 이분매칭하여 매칭된 수를 sudoku[row][col]에 채우면 된다.
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
#define DIV 1000000007LL
#define INF 2e18
using namespace std;

int n, k;
int sudoku[101][101], cnt[101], A[101], B[101];
bool flg, vis[101];
vector<int> adj[101];

bool dfs(int a) {
	vis[a] = true;
	for (int b : adj[a]) {
		if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
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
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> sudoku[i][j];
		}
	}
	flg = false;
	for (int i = 1; i <= k; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= n; j++) {
			cnt[sudoku[i][j]]++;
			if (cnt[sudoku[i][j]] > 1) flg = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= k; j++) {
			cnt[sudoku[j][i]]++;
			if (cnt[sudoku[j][i]] > 1) flg = true;
		}
	}
	if (flg) {
		cout << "no\n";
		return 0;
	}
	for (int i = k + 1; i <= n; i++) {
		//ith row를 채울 것임.
		for (int c = 1; c <= n; c++) {
			memset(cnt, 0, sizeof(cnt));
			for (int r = 1; r < i; r++) {
				cnt[sudoku[r][c]]++;
			}
			for (int val = 1; val <= n; val++) {
				if (cnt[val]) continue;
				adj[c].pb(val);
			}
		}
		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));
		for (int c = 1; c <= n; c++) {
			if (A[c] == -1) {
				memset(vis, false, sizeof(vis));
				dfs(c);
			}
		}
		for (int c = 1; c <= n; c++) {
			sudoku[i][c] = A[c];
		}
		for (int j = 1; j <= n; j++) adj[j].clear();
	}
	cout << "yes\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
