//인덕이의 고민
//Dijkstra, Brute force
/*
  간단하지만 귀찮은 brute force + dijkstra 문제인데,
  한번 pq에서 꺼낸 점에 대해 같은 dist를 무시하지 않는 코드를 짜면 MLE(...)가 난다.
  나는 이걸 vis로 처리했다...
  그런데 생각해보니 pq에 넣을때 dist와 같은값도 거르는 로직을 짜면 되겠다. dijkstra 코드를 수정해야겠다.
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define pb push_back
const int INF = 1e9 + 7;
using namespace std;

int n, m, r, c, res = INF;
int dist[51][51], a[3];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 }, dy[8] = { -2,-1,1,2,2,1,-1,-2 };
pii b[4];
int seq[4];

void dijk(int R, int C) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}
	dist[R][C] = 0;
	priority_queue<pair<int, pii>> pq;
	pq.push({ 0,{R,C} });
	while (!pq.empty()) {
		int curd = -pq.top().x;
		pii p = pq.top().y; pq.pop();
		int r = p.x, c = p.y;
		if (dist[r][c] < curd) continue;
		//나이트
		for (int i = 0; i < 8; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (dist[nr][nc] < curd + a[0]) continue;
			dist[nr][nc] = curd + a[0];
			pq.push({ -dist[nr][nc],{nr,nc} });
		}
		//비숍
		for (int i = -n; i <= n; i++) {
			int nr = r + i, nc = c + i;
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (dist[nr][nc] < curd + a[1]) continue;
			dist[nr][nc] = curd + a[1];
			pq.push({ -dist[nr][nc],{nr,nc} });
		}
		for (int i = -n; i <= n; i++) {
			int nr = r - i, nc = c + i;
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (dist[nr][nc] < curd + a[1]) continue;
			dist[nr][nc] = curd + a[1];
			pq.push({ -dist[nr][nc],{nr,nc} });
		}
		//룩
		for (int i = 0; i < n; i++) {
			int nr = i, nc = c;
			if (dist[nr][nc] < curd + a[2]) continue;
			dist[nr][nc] = curd + a[2];
			pq.push({ -dist[nr][nc],{nr,nc} });
		}
		for (int i = 0; i < n; i++) {
			int nr = r, nc = i;
			if (dist[nr][nc] < curd + a[2]) continue;
			dist[nr][nc] = curd + a[2];
			pq.push({ -dist[nr][nc],{nr,nc} });
		}
	}
	return;
}

void get() {
	int ret = 0;
	vector<pii> v;
	v.pb({ r,c });
	for (int i = 0; i < m; i++) v.pb(b[seq[i]]);
	for (int i = 0; i < m; i++) {
		dijk(v[i].x, v[i].y);
		ret += dist[v[i + 1].x][v[i + 1].y];
	}
	res = min(res, ret);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a[0] >> a[1] >> a[2];
	cin >> r >> c;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i].x >> b[i].y;
		seq[i] = i;
	}
//	get();
	do {
		get();
	} while (next_permutation(seq, seq + m));
	cout << res;
	return 0;
}
