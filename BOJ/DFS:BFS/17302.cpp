//흰색으로 만들기
//DFS, BFS, Ad-hoc
/*
  모든 점을 흰색으로 만들기 위해 각 점에서 할 수 있는 3가지 연산 중 2, 3번에 주목하자.
  2번 연산 + 해당 점 반전 = 3번 연산이다.
  따라서 모든 점에  2번 연산을 수행하고, B로 남아있는 점들에 대해 3번 연산으로 간주하면 된다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <unordered_set>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
const ll INF = 1e18, mxn = 100010;

int N, M;
char color[2020][2020];
int res[2020][2020];

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

inline int inrange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}
queue<ii> q;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			res[i][j] = 2;
			cin >> color[i][j];
		}
	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++) {
			for (int x = 0; x < 4; x++) {
				int nr = i + dr[x], nc = j + dc[x];
				if (!inrange(nr, nc)) continue;
				if (color[nr][nc] == 'W') color[nr][nc] = 'B';
				else color[nr][nc] = 'W';
			}
		}
	for(int i = 0; i<N; i++)
		for (int j = 0; j < M; j++)
			if (color[i][j] == 'B') res[i][j] = 3;
	cout << 1 << '\n';
	for (int i = 0; i < N; i++, cout<<'\n')
		for (int j = 0; j < M; j++)
			cout << res[i][j];

	return 0;
}
