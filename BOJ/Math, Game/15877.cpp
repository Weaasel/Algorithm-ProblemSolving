//Apples and Bananas
//Game
/*
  각 player는 자기 차례에 4가지 선택지 중 하나를 고를 수 있고,
  사과와 바나나가 최대 각 1000개씩 있는 상태에서 시작하므로,
  (사과개수, 바나나개수) 를 한 state로 생각하면 각 state일 때 턴을 가진 사람이 이길수 있는지 없는지를 알 수 있다.
  
  예를들어, 현재 state에서 갈 수 있는 4개의 state중 상대가 이길 수 없는 state가 하나라도 있다면, 나는 그 선택을 하여 이길 수 있다.
  상대가 이길 수 있는 state밖에 없다면 나는 진다.
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
#define ll long long
#define INF 1e9 + 7
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

int a, b;
int dx[] = { 0, 1, 3, 1 }, dy[] = { 1, 0, 1, 3 };
int dp[1001][1001]; //0 : Lose, 1 : Win

int go(int a, int b) {
	if (dp[a][b] > -1) return dp[a][b];
	int res = 0;
	for (int i = 0; i < 4; i++) {
		int na = a - dx[i], nb = b - dy[i];
		if (na < 0 || nb < 0) continue;
		if (go(na, nb) == 0) res = 1;
	}
	return dp[a][b] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	if (go(a, b))
		cout << "Alice";
	else cout << "Bob";
	return 0;
}
