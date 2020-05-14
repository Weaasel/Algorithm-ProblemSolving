//E - Orac and Game of Life	
/*
  인접한 격자 중 자신과 색이 같은 격자가 하나도 없다면 색을 그대로 유지, 하나라도 있다면 매 초 색을 반전하는 격자들이 있다.
  이 때, 100,000 개 단위의 쿼리가 주어진다. 쿼리는 격자의 좌표와, t초가 지났을 때의 격자의 색에 대해 묻는다.
  
  이 문제에서 중요한 성질은
  1. 어떤 격자가 '색이 변하는 상태'에 들어가면 '색이 변하지 않는 상태' 로는 두번 다시 돌아가지 않는다는 의미이고,
  2. 어떤 '색이 변하지 않는 상태'에 놓인 격자라도 인접한 격자가 '색이 변하는 상태' 라면, 다음 순서부터는 '색이 변하는 상태' 로 바뀌게 된다.
  
  이 두 가지 성질을 이용하여 각 격자들에 대해 '색이 변하는 상태'가 되는 시간을 알 수 있다면, 쿼리를 상수시간에 답변할 수 있겠다.
  이 처리는 bfs로 진행한다.
  
  처음에 모든 격자에 대해 dist를 initialization한다.(0 or INF)
  그 다음부터는 dist가 갱신된 격자들에 대하여
  인접한 격자들의 dist를 갱신해 준다.
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

ll n, m, q, r, c, t;
ll grid[1001][1001], dist[1001][1001];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
string s;

void bfs() {
	queue<pii> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] == 0) q.push({ i, j });
		}
	}
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		int pi = p.first, pj = p.second;
		for (int k = 0; k < 4; k++) {
			int ni = pi + dx[k], nj = pj + dy[k];
			if (ni < 1 || ni > n) continue;
			if (nj < 1 || nj > m) continue;
			if (dist[ni][nj] > dist[pi][pj] + 1) {
				dist[ni][nj] = dist[pi][pj] + 1;
				q.push({ ni, nj });
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			if (s[j - 1] == '1') grid[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = INF;
			int ind = 0;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (ni < 1 || ni > n) continue;
				if (nj < 1 || nj > m) continue;
				if (grid[i][j] == grid[ni][nj]) ind++;
			}
			if (ind > 0) dist[i][j] = 0;
		}
	}
	bfs();
	for (int i = 0; i < q; i++) {
		cin >> r >> c >> t;
		if (dist[r][c] >= t) {
			cout << grid[r][c] << "\n";
		}
		else {
			cout << (grid[r][c] + t - dist[r][c]) % 2 << "\n";
		}
	}

	return 0;
}
