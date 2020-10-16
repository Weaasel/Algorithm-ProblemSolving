//뱀
//Simulation
/*
  필요한건 뱀의 머리와 꼬리 정보를 알기 위한 deque, 뱀의 몸이 놓인 좌표를 체크하기 위한 배열, 사과의 위치를 나타낼 배열이다, 방향전환 정보를 저장할 queue
  문제의 설명에 맞게 simulate 하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#define pii pair<int, int>

using namespace std;

int n, k, l, app[101][101], chk[101][101], dir, res;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
deque<pii> dq;
queue<pii> q;

int main() {

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int r, c; cin >> r >> c;
		app[r][c] = true;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t;
		char c;
		cin >> t >> c;
		if (c == 'L') q.push({ t,0 });
		else q.push({ t,1 });
	}
	dq.push_back({ 1,1 });
	chk[1][1] = true;

	while (1) {
		res++;
		int nr = dq.front().first + dx[dir], nc = dq.front().second + dy[dir];
		if (nr < 1 || nr > n) break;
		if (nc < 1 || nc > n) break;
		if (chk[nr][nc]) break;
		dq.push_front({ nr,nc });
		chk[nr][nc] = true;
		if (app[nr][nc]) {
			app[nr][nc] = false;
		}
		else {
			chk[dq.back().first][dq.back().second] = false;
			dq.pop_back();
		}

		if (!q.empty() && q.front().first == res) {
			if (q.front().second == 0) dir = (dir + 3) % 4;
			else dir = (dir + 1) % 4;
			q.pop();
		}
	}
	cout << res;
	return 0;
}
