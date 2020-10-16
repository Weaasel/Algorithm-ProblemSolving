//구슬 탈출2
//Brute force
/*
  4가지 방향에 대해, 10번의 횟수에 대해 4^10 가지 경우의 수를 전부 탐색하면
  1000ms 초과의 괴랄한 수행시간과 함께 AC를 받을 수 있다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans = 11;
int dir[10];
bool rflg, bflg;
char a[101][101], cpy[101][101];

void up() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cpy[i][j] != 'R' && cpy[i][j] != 'B') continue;
			int ni = i - 1, nj = j;
			bool oflg = false;
			while (1) {
				if (ni < 0) break;
				if (cpy[ni][nj] == '#' || cpy[ni][nj] == 'R' || cpy[ni][nj] == 'B') break;
				if (cpy[ni][nj] == 'O') {
					oflg = true;
					if (cpy[i][j] == 'R') rflg = true;
					else bflg = true;
					cpy[i][j] = '.';
					break;
				}
				ni--;
			}
			if (!oflg) swap(cpy[i][j], cpy[ni+1][nj]);
		}
	}
	return;
}

void down() {
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (cpy[i][j] != 'R' && cpy[i][j] != 'B') continue;
			int ni = i + 1, nj = j;
			bool oflg = false;
			while (1) {
				if (ni >= n) break;
				if (cpy[ni][nj] == '#' || cpy[ni][nj] == 'R' || cpy[ni][nj] == 'B') break;
				if (cpy[ni][nj] == 'O') {
					oflg = true;
					if (cpy[i][j] == 'R') rflg = true;
					else bflg = true;
					cpy[i][j] = '.';
					break;
				}
				ni++;
			}
			if (!oflg) swap(cpy[i][j], cpy[ni-1][nj]);
		}
	}
	return;
}

void left() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cpy[i][j] != 'R' && cpy[i][j] != 'B') continue;
			int ni = i, nj = j - 1;
			bool oflg = false;
			while (1) {
				if (nj < 0) break;
				if (cpy[ni][nj] == '#' || cpy[ni][nj] == 'R' || cpy[ni][nj] == 'B') break;
				if (cpy[ni][nj] == 'O') {
					oflg = true;
					if (cpy[i][j] == 'R') rflg = true;
					else bflg = true;
					cpy[i][j] = '.';
					break;
				}
				nj--;
			}
			if (!oflg) swap(cpy[i][j], cpy[ni][nj+1]);
		}
	}
	return;
}

void right() {
	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >=0; j--) {
			if (cpy[i][j] != 'R' && cpy[i][j] != 'B') continue;
			int ni = i, nj = j + 1;
			bool oflg = false;
			while (1) {
				if (nj >= m) break;
				if (cpy[ni][nj] == '#' || cpy[ni][nj] == 'R' || cpy[ni][nj] == 'B') break;
				if (cpy[ni][nj] == 'O') {
					oflg = true;
					if (cpy[i][j] == 'R') rflg = true;
					else bflg = true;
					cpy[i][j] = '.';
					break;
				}
				nj++;
			}
			if(!oflg) swap(cpy[i][j], cpy[ni][nj - 1]);
		}
	}
	return;
}

void go(int idx) {
	if (idx == 10) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cpy[i][j] = a[i][j];
		rflg = false;
		bflg = false;
		for (int i = 0; i < 10; i++) {
			if (i + 1 >= ans) return;

			if (dir[i] == 1) up();
			else if (dir[i] == 2) down();
			else if (dir[i] == 3) left();
			else right();

			if (bflg) return;
			if (rflg) {
				ans = min(ans, i + 1);
				return;
			}
		}
		return;
	}
	dir[idx] = 1;
	go(idx + 1);
	dir[idx] = 2;
	go(idx + 1);
	dir[idx] = 3;
	go(idx + 1);
	dir[idx] = 4;
	go(idx + 1);
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	go(0);
	if (ans == 11) cout << -1;
	else cout << ans;
}
