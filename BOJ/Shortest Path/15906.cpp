//변신 이동 게임
//Shortest Path, Dijkstra
/*
  상태를 다음과 같이 정의한다.
  d[r][c][mode]: (r,c)에 mode 모드로 도달하는 최소 시간
  
  이러면 d[1][1][0] 에서 출발하여 도착점 (R,C)까지
  min(d[R][C][0], d[R][C][1]) 을 구하면 되고,
  각 상태에서는 최대 5개의 다른 상태로 이동할 수 있다. (모드에 따른 상하좌우, 현재 점에서 모드 변경)
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define pb push_back
using namespace std;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int n, t, R, C;
int d[501][501][2]; //r, c, mode. 0:일반 1:변신
pii near[501][501][4]; //가까운 #찾기, dxdy따라
char m[501][501];
vector<pair<pii,pii>> adj[501][501][2]; // {점,{모드, 비용}}

bool in_range(int r, int c) {
	if (r<1 || r>n || c<1 || c>n) return false;
	return true;
}

void dijk() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j][0] = INF;
			d[i][j][1] = INF;
		}
	}
	d[1][1][0] = 0;
	priority_queue<pair<int, pair<pii,int>>> pq; //비용, 점정보
	pq.push({ 0,{{1,1},0} });
	while (!pq.empty()) {
		auto p = pq.top(); pq.pop();
		int dist = -p.x, mode = p.y.y, r = p.y.x.x, c = p.y.x.y;
		if (dist > d[r][c][mode]) continue;
		for (pair<pii, pii> np : adj[r][c][mode]) {
			int nr = np.x.x, nc = np.x.y, nmode = np.y.x, cost = np.y.y;
			if (dist + cost < d[nr][nc][nmode]) {
				d[nr][nc][nmode] = dist + cost;
				pq.push({ -d[nr][nc][nmode], {{nr,nc},nmode} });
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> t >> R >> C;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 1; j <= n; j++) {
			m[i][j] = s[j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 4; k++) {
				int wr = i, wc = j;
				do {
					wr += dx[k], wc += dy[k];
				} while (in_range(wr, wc) && m[wr][wc] != '#');
				if (!in_range(wr, wc)) near[i][j][k] = { INF,INF };
				else near[i][j][k] = { wr,wc };
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pair<pii, pii> p;
			//일반모드
			for (int k = 0; k < 4; k++) {
				int nr = i + dx[k], nc = j + dy[k];
				if (!in_range(nr, nc)) continue;
				p.x.x = nr, p.x.y = nc;
				p.y.x = 0;
				p.y.y = 1;
				adj[i][j][0].pb(p);
			}
			adj[i][j][0].pb({ {i,j},{1,t} });
			//변신모드
			for (int k = 0; k < 4; k++) {
				int nr = near[i][j][k].x, nc = near[i][j][k].y;
				if (!in_range(nr, nc)) continue;
				p.x.x = nr, p.x.y = nc;
				p.y.x = 1;
				p.y.y = 1;
				adj[i][j][1].pb(p);
			}
			adj[i][j][1].pb({ {i,j},{0,0} });
		}
	}
	dijk();
	cout << min(d[R][C][0], d[R][C][1]);

	return 0;
}
