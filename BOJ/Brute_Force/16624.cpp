//Bingo Ties
/*
  naive하게 생각할 수 있는 n^4 솔루션을 잘 최적화하는 문제.(n <= 100)
  전처리와 set을 잘 이용했다.
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
using namespace std;

set<int> s[101];
int n, num;
int row[101][3001];
int cnt[101][6];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int card[101][6][6];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j) {
			for (int k = 1; k <= 5; ++k) {
				cin >> num;
				card[i][j][k] = num;
				row[i][num] = j;
				s[i].insert(num);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			vector<int> same;
			for (int r = 1; r <= 5; r++) {
				for (int c = 1; c <= 5; c++) {
					if (s[j].find(card[i][r][c]) != s[j].end()) same.push_back(card[i][r][c]);
				}
			}
			for (int nn : same) {
				int ir = row[i][nn], jr = row[j][nn];
				for (int k = 1; k <= n; k++) {
					for (int c = 1; c <= 5; c++) {
						cnt[k][c] = 0;
					}
				}
				set<int> chknum;
				for (int c = 1; c <= 5; c++) {
					if (card[i][ir][c] != nn) chknum.insert(card[i][ir][c]);
					if (card[j][jr][c] != nn) chknum.insert(card[j][jr][c]);
				}

				bool flg = false; //하나라도 안겹치게 하면 그냥 i, j 출력하고 끝
				for (int chn : chknum) {
					for (int k = 1; k <= n; k++) {
						if (k == i || k == j) continue;
						if (s[k].find(chn) == s[k].end()) continue;
						int kr = row[k][chn];
						cnt[k][kr]++;
						if (cnt[k][kr] == 5) flg = true;
					}
				}
				if (!flg) {
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
	}
	cout << "no ties\n";

	return 0;
}
