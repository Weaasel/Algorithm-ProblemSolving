//Left and Right
/*
  Lexiographical order에 따르기 위해,
  R이 나오면 선택할 수 있는 최소의 수를 고르고,
  L이 나오면 최소의 수에서 L 개수만큼 큰 수를 고르면 된다.
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

string s;
int n, st = 1, w = 0, cnt = 0;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	while (w < n - 1) {
		cnt = 0;
		if (s[w] == 'R') {
			cout << st << "\n";
			st++;
			w++;
		}
		else {
			while (w < n && s[w] == 'L') {
				cnt++;
				w++;
			}
			for (int i = st + cnt; i >= st; i--) cout << i << "\n";
			st += cnt + 1;
			w++;
		}
	}
	if(s[n-2] == 'R') cout << st <<"\n";
	return 0;
}
