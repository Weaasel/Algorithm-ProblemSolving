//D. Nastya and Scoreboard
/*
  dp[i][num][j]; // string의 i번째 index에서 숫자 num이 되게 불을 켜면서 택하면서 k가 j만큼 남았을때 가능한지 여부. 1이면 가능, 0이면 불가능
  이렇게 dp[0][0~9][k] 가 가능한가? 에 대한 검사로부터 출발하여 -1을 출력할 지 / 답이 있을지를 결정하고,
  그 이후로는 높은 자리수에서 될 수 있는 한 가장 높은 숫자를 선택하는 것이 greedy한 solution이다.
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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int n, k;
int cnt[2001];

string num[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
string s[2001];
int dist[2001][10];

void make_dist() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			int cnt = 0, flg = 0;
			for (int k = 0; k < 7; k++) {
				if (s[i][k] == num[j][k]) continue;
				else if (s[i][k] == '0' && num[j][k] == '1') cnt++;
				else flg = 1;
			}
			if (flg) dist[i][j] = -1;
			else dist[i][j] = cnt;
		}
	}
}

int dp[2001][10][2001]; //i번째에서 j를 택하면서 k가 k만큼 남앗을때 가능한지. 1이면 가능, 0이면 불가능

int go(int idx, int num, int k) {
	if (dp[idx][num][k] > -1) return dp[idx][num][k];
	if (idx == n - 1) {
		if (dist[idx][num] == k) return dp[idx][num][k] = 1;
		else dp[idx][num][k] = 0;
	}
	int res = 0;
	for (int i = 0; i < 10; i++) {
		if (dist[idx][num] == -1 || k < dist[idx][num]) continue;
		if (go(idx + 1, i, k - dist[idx][num])) res = 1;
	}
	return dp[idx][num][k] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) cin >> s[i];
	make_dist();

	int flag = -1;
	for (int i = 0; i < 10; i++) {
		if (go(0, i, k)) flag = 1;
	}
	if (flag < 0) cout << -1;
	else {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				for (int j = 9; j >= 0; j--) {
					if (dist[i][j] == k) {
						cout << j;
						return 0;
					}
				}
			}
			else for (int j = 9; j >= 0; j--) {
				if (go(i, j, k)) {
					cout << j;
					k -= dist[i][j];
					break;
				}
			}
		}
	}
	return 0;
}
