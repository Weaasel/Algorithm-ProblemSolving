//늑대와 양
//Constructive
/*
  적당히 울타리를 쳐 늑대들로부터 양들을 안전하게 보호할 수 있는지 여부를 판단하는 문제이다.
  단순하게, 모든 .에 대해 울타리를 전부 쳐두고, 늑대와 인접한 양이 있는지 없는지 확인하면 된다.
  최소 울타리의 개수를 구하는 문제가 아니기 때문이다.
  만약 그랬다면, 어떻게 했어야 할까?
*/

#include <iostream>
#include <string>

using namespace std;
int n, m, dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
bool flg = true;
char a[501][501];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 'S') continue;
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
				if (a[ni][nj] == 'W') flg = false;
			}
		}
	}
	if (!flg) return cout << 0, 0;
	cout << 1 << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') cout << 'D';
			else cout << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}
