//햄버거 분배
//Greedy
/*
  1. 햄버거를 먹을 수 있는 사람은 무조건 먹게 하는게 좋다. 손해볼 게 없다.
  2. 이왕 햄버거를 먹을 것이라면 가장 앞에 있는 햄버거를 먹게 하는게 좋다. 손해볼 게 없다.
  앞사람부터 보면서 그사람이 먹을 수 있는 햄버거 중 가장 앞에 있는 햄버거를 먹게 하면 된다.
*/

#include <bits/stdc++.h>

using namespace std;

string s;
int sz, res ,k;
int a[20202];

int main() {
	cin >> sz >> k;
	cin >> s;
	for (int i = 0; i < sz; i++) {
		if (s[i] == 'H') a[i] = 1;
		else a[i] = 2;
	}

	for (int i = 0; i < sz; i++) {
		if (a[i] != 2) continue;
		for (int j = max(0, i - k); j <= min(sz - 1, i + k); j++) {
			if (a[j] == 1) {
				res++;
				a[j] = 0;
				break;
			}
		}
	}
	cout << res;
}
