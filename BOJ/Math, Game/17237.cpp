//PPC 2019. Conquering A Castle
//재밌는 게임이었음. 이기려면 dist가 1인 병사 2명이 있으면 됨. 그게 안될 경우에는 가진 군사들을 잘 나눠주면 됨.

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using lint = long long;
using ii = pair<int, int>;

int a[1000], cnt[22];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;  cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i], cnt[a[i]]++;

	for (int loop = 1; loop <= 20; loop++) {
		if (cnt[1] >= 2) {
			cout << "A";
			return 0;
		}
		else if (cnt[1] == 1) {
			for (int i = 1; i <= 20; i++) {
				cnt[i] = cnt[i + 1];
			}
		}
		else {
			int flg = 0;
			for (int i = 1; i <= 20; i++) {
				cnt[i] = cnt[i + 1];
			}
			for (int i = 1; i <= 20; i++) {
				if (!flg) cnt[i] = cnt[i] / 2;
				else cnt[i] = (cnt[i] + 1) / 2;
				if (cnt[i] > 0) flg = 1;
			}
		}
	}
	cout << "B";

	return 0;
}
