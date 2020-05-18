//Stable Wall
/*
  알파벳 대문자들로 이루어진 벽돌 모형이 주어진다.
  ex) ZOAAMM
      ZOAOMM
      ZOOOOM
      ZZZZOM
      
  이 때, 벽돌을 쌓는 순서는 자유지만, 어떤 알파벳의 순서가 되면 해당 알파벳이 위치하는 모든 자리에 벽돌을 쌓아올릴 수 있어야 한다.
  
  아래에 있는 벽돌 -> 위에 있는 벽돌의 연결 그래프를 만들고,
  topological sort를 한다. 만약 cycle이 존재하면 이 벽돌은 못 만드는 것이다.
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
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 1e9
#define eps 1e-8
#define PI 3.14159265
using namespace std;

int T, r, c;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int adj[26][26], ind[26];
		char block[31][31];
		bool chk[26];
		memset(chk, false, sizeof(chk));

		cin >> r >> c;
		for (int i = 0; i < 26; i++) {
			ind[i] = 0;
			for (int j = 0; j < 26; j++) {
				adj[i][j] = 0;
			}
		}
		for (int i = 0; i < r; i++) {
			cin >> s;
			for (int j = 0; j < c; j++) {
				block[i][j] = s[j];
				chk[block[i][j] - 'A'] = true;
			}
		}
		for (int col = 0; col < c; col++) {
			for (int row = r - 1; row >= 1; row--) {
				if (block[row][col] == block[row - 1][col]) continue;
				if (!adj[block[row][col] - 'A'][block[row - 1][col] - 'A']) {
					adj[block[row][col] - 'A'][block[row - 1][col] - 'A'] = 1;
					ind[block[row - 1][col] - 'A']++;
				}
			}
		}
		queue<int> q;
		vector<char> res;
		for (int i = 0; i < 26; i++) if (ind[i] == 0) q.push(i);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			res.pb(cur + 'A');
			for (int i = 0; i < 26; i++) {
				if (adj[cur][i]) {
					ind[i]--;
					if (ind[i] == 0) q.push(i);
				}
			}
		}
		bool flg = false;
		for (int i = 0; i < 26; i++) if (ind[i] > 0) flg = true;

		cout << "Case #" << tc << ": ";
		if (flg) cout << "-1\n";
		else {
			for (char c : res) {
				if(chk[c - 'A']) cout << c;
			}
			cout << "\n";
		}
	}
	return 0;
}
