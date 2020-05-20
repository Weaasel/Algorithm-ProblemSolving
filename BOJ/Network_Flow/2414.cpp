//게시판 구멍 막기
/*
  가로줄/세로줄마다 연속한 구멍들을 하나로 묶어 component형식으로 만들어주고,
  같은 점을 공유하는 가로/세로줄들에 대해 연결관계를 표시하면,
  돌멩이 제거와 같은 Vertex Cover 문제로 환원된다.
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

typedef struct comp {
	int mynum, l, r;
}comp;

int n, m, A[1250], B[1250], rcnt, ccnt, cnt;
bool vis[1250];
vector<int> adj[1250];
string s;
char b[51][51];
comp rcom[1250], ccom[1250];

bool dfs(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj[u]) {
		if (B[v] == -1 || dfs(B[v])) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) b[i][j] = s[j];
	}
	for (int row = 0; row < n; row++) {
		for (int i = 0; i < m; i++) {
			if (b[row][i] == '.') continue;
			for (int j = i; j < m; j++) {
				if (b[row][j] == '.') {
					comp tmp;
					tmp.mynum = row, tmp.l = i, tmp.r = j - 1;
					rcom[rcnt++] = tmp;
					i = j - 1;
					break;
				}
				else if (j == m - 1 && b[row][j] == '*') {
					comp tmp;
					tmp.mynum = row, tmp.l = i, tmp.r = j;
					rcom[rcnt++] = tmp;
					i = j;
				}
			}
		}
	}
	for (int col = 0; col < m; col++) {
		for (int i = 0; i < n; i++) {
			if (b[i][col] == '.') continue;
			for (int j = i; j < n; j++) {
				if (b[j][col] == '.') {
					comp tmp;
					tmp.mynum = col, tmp.l = i, tmp.r = j - 1;
					ccom[ccnt++] = tmp;
					i = j - 1;
					break;
				}
				else if (j == n - 1 && b[j][col] == '*') {
					comp tmp;
					tmp.mynum = col, tmp.l = i, tmp.r = j;
					ccom[ccnt++] = tmp;
					i = j;
				}
			}
		}
	}

	for (int i = 0; i < rcnt; i++) {
		for (int j = 0; j < ccnt; j++) {
			comp r = rcom[i], c = ccom[j];
			if (r.mynum >= c.l && r.mynum <= c.r && c.mynum >= r.l && c.mynum <= r.r) adj[i].pb(j);
		}
	}

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < rcnt; i++) {
		memset(vis, false, sizeof(vis));
		if (dfs(i)) cnt++;
	}
	cout << cnt;
	return 0;
}
