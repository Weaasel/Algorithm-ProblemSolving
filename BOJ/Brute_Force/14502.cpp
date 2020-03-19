//
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
int n, m;
int map[9][9], cpy[9][9], sz, ans = 0;
int dist[10][10], vis[100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

vector<pair<int, int>> virus, safe, wall;
queue<pair<int, int>> q;

void copying() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cpy[i][j] = map[i][j];
	}
}

int bfs() {
	//map 만들어주기
	memset(dist, -1, sizeof(dist));
	for (pair<int, int> a : virus) {
		dist[a.first][a.second] = 0;
		q.push(a);
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newr = cur.first + dx[i], newc = cur.second + dy[i];
			if (newr < 1 || newr > n) continue;
			if (newc < 1 || newc > m) continue;
			if (dist[newr][newc] > -1) continue;

			if (cpy[newr][newc] == 1) continue;
			dist[newr][newc] = dist[cur.first][cur.second] + 1;
			q.push(make_pair(newr, newc));
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] == -1 && cpy[i][j] != 1) res++;
		}
	}
	return res;
}

int func(int idx, int cnt) {
	int ret = 0;

	if (cnt == 2) {
		for (int i = idx; i < sz; i++) {
			wall.push_back(safe[i]);
			copying();
			cpy[wall[0].first][wall[0].second] = 1;
			cpy[wall[1].first][wall[1].second] = 1;
			cpy[wall[2].first][wall[2].second] = 1;
			ret = max(ret, bfs());
			wall.pop_back();
		}
	}
	else {
		wall.push_back(safe[idx]);
		for (int i = idx + 1; i < sz; i++) {
			ret = max(ret, func(i, cnt + 1));
		}
		wall.pop_back();
	}

	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			cpy[i][j] = map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
			if (map[i][j] == 0) safe.push_back(make_pair(i, j));
		}
	}
	sz = safe.size();
	for (int i = 0; i < sz; i++) ans = max(ans, func(i, 0));
	cout << ans;
	return 0;
}
