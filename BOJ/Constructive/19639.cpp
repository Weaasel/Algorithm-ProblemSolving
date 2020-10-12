//배틀로얄
/*
  최대HP를 M이라 할 때, 전투로 잃을 수 있는 체력과 포션으로 얻을 수 있는 체력이 전부 M/2 이하이므로
  포션으로 얻을 수 있는 체력의 낭비 없이 게임을 진행하는 최선의 전략을 찾자.
  최선의 전략은 간단하다.
    1. 현재 체력이 M/2 초과이면 싸운다.
    2. 현재 체력이 M/2 이하이면 포션을 먹는다.
*/

#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

const int mxn = 100001;

ll x, y, m, a[101010], b[101010];
ll xsum, ysum;

int main() {
	cin >> x >> y >> m;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
		xsum += a[i];
	}
	for (int i = 1; i <= y; i++) {
		cin >> b[i];
		ysum += b[i];
	}
	if (xsum >= m + ysum) return cout << 0, 0;

	ll w1 = 1, w2 = 1, curm = m;
	while (w1 <= x && w2 <= y) {
		if (curm > m / 2) {
			curm -= a[w1];
			cout << -w1 << "\n";
			w1++;
		}
		else {
			curm += b[w2];
			cout << w2 << "\n";
			w2++;
		}
	}
	while (w1 <= x) {
		cout << -w1 << "\n";
		w1++;
	}
	while (w2 <= y) {
		cout << w2 << "\n";
		w2++;
	}
	return 0;
}
