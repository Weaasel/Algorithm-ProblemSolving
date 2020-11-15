//Queen on Grid
//Dynamic Programming
/*
  퀸은 오른쪽, 아래, 대각선 아래 방향으로 원하는 만큼 이동할 수 있다.
  이용하지 못하는 점(벽)들의 정보가 주어진 격자판에서 퀸이 좌상단 꼭지점에서 우하단 꼭지점으로 이동할 수 있는 경로의 수를 구하는 문제이다.
  
  어떤 점으로 올 수 있는 가능성을 3방향으로 나누어 생각하자.
  나의 왼쪽점에서, 위쪽 점에서, 대각선 위쪽 점에서 올 수 있다.
  각각의 경우에 대해 이전 점의 전체 개수 + 이전점의 해당 방향 성분 개수를 더해주면 된다.
  
  우측방향에 대해서만 설명하자면,
  우측으로 이동해서 현재 점으로 올 수 있는 가짓수는 (내 왼쪽점에서 오른쪽으로 이동한 경우 + 모든 왼쪽점들에서 오른쪽으로 이동하는 경우의 수)인데,
  다른 왼쪽점들에서 이동한 가짓수에 대해서는 내 왼쪽점에 합쳐져 있을 것이기 때문에 이를 이용해 시간복잡도를 줄인 것이다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e15+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265

const ll mod = 1e9 + 7;

using namespace std;

char a[2020][2020];
int h, w;
ll dp[2020][2020][4];

ll go(int r, int c, int dir) {
	if (dp[r][c][dir] > -1) return dp[r][c][dir];
	if (a[r][c] == '#') return dp[r][c][dir] = 0;
	if (r < 1 || c < 1) return dp[r][c][dir] = 0;
	if (dir == 0)
		return dp[r][c][dir] = (go(r - 1, c, 0) + go(r - 1, c, 3)) % mod;
	else if (dir == 1)
		return dp[r][c][dir] = (go(r - 1, c - 1, 1) + go(r - 1, c - 1, 3)) % mod;
	else if(dir == 2) 
		return dp[r][c][dir] = (go(r, c - 1, 3) + go(r, c - 1, dir)) % mod;
	else return dp[r][c][dir] = (go(r, c, 0) + go(r, c, 1) + go(r, c, 2)) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		string s; cin >> s;
		for (int j = 1; j <= w; j++) {
			a[i][j] = s[j - 1];
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[1][1][3] = 1;

	cout << go(h, w, 3);

	return 0;
}
