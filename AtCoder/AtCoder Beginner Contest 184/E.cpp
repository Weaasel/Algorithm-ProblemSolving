//E. Third Avenue
//BFS
/*
  주어진 맵에서 S -> G로 몇번 이동해야 하니? 를 묻는 단순 BFS 문제.
  여기에 같은 알파벳이 쓰인 좌표로 teleport할 수 있다는 조건이 추가된다.
  즉 동서남북 방향 이외에 또 갈 수 있는 후보들이 생기는 건데, 나이브하게 다 검사하면 시간초과가 날 수 있겠다.
  (2000*2000 = 4,000,000 개의 점에 전부 a가 써있다면? 한번 뻗을 때마다 4백만개의 점에 대해서...)
  따라서 어차피 텔레포트 종류는 26개(알파벳의 개수) 이므로 이 각각의 종류가 queue에 포함됐는지 안됐는지를 체크할 vis배열을 선언한다.
  어차피 텔레포트점들은 들어갈 때 한번에 다 들어가기 때문에 한번 호출되고 나면 그 이후로는 queue에 들어갈 일이 없다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

using namespace std;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int n, m, sr, sc, gr, gc;
char a[2020][2020];
int dist[2020][2020];
bool vis[26];
vector<pii> al[26];

void bfs() {
	dist[sr][sc] = 0;
	queue<pii> q;
	q.push({ sr,sc });
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		int r = p.first, c = p.second;
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			if (nr < 0 || nr >= n) continue;
			if (nc < 0 || nc >= m) continue;
			if (dist[nr][nc] > -1) continue;
			if (a[nr][nc] == '#') continue;
			dist[nr][nc] = dist[r][c] + 1;
			q.push({ nr,nc });
		}
		if (a[r][c] <= 'z' && a[r][c] >= 'a' && !vis[a[r][c] - 'a']) {
			for (pii p : al[a[r][c] - 'a']) {
				int nr = p.first, nc = p.second;
				if (dist[nr][nc] > -1) continue;
				dist[nr][nc] = dist[r][c] + 1;
				q.push({ nr,nc });
			}
			vis[a[r][c] - 'a'] = true;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(dist, -1, sizeof(dist));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (a[i][j] <= 'z' && a[i][j] >= 'a') al[a[i][j] - 'a'].pb({ i,j });
			if (a[i][j] == 'S') sr = i, sc = j;
			if (a[i][j] == 'G') gr = i, gc = j;
		}
	}

	bfs();
	cout << dist[gr][gc];
	return 0;
}
