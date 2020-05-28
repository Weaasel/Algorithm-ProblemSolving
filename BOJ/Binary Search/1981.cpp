//배열에서 이동
//Binary search, BFS
/*
  diff값이 될 수 있는 값을 binary search 해서 찾는다.
  diff값이 정해지면, 높이가 0~200까지이므로, 200가지의 경우에 대해서 bfs로 검사해 주면 된다.
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
#define INF 1e9
using namespace std;

int n, h[101][101], mn, mx, r, c;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
bool vis[101][101];

bool chk(int diff) {
	for (int i = 0; i <= 200 - diff; i++) {
		mn = i;
		mx = i + diff;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) vis[i][j] = false;
		queue<pii> q;
		if(h[0][0]>=mn && h[0][0]<=mx) q.push({ 0,0 });
		while (!q.empty()) {
			r = q.front().first;
			c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i], nc = c + dy[i];
				if (vis[nr][nc]) continue;
				if (nr < 0 || nr >= n) continue;
				if (nc < 0 || nc >= n) continue;
				if (h[nr][nc] < mn || h[nr][nc] > mx) continue;
				q.push({ nr, nc });
				vis[nr][nc] = true;
			}
		}
		if (vis[n - 1][n - 1]) return true;
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
		}
	}
	int l = 0, r = 201, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}
