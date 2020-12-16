//C - Unique Number	
//Brute force, Recursion
/*
  모든 자리수의 합이 주어진 수가 되게 하는 최소의 수를 구하는 문제이다.
  구성하는 자리수가 모두 distinct 하다는 조건이 있어 1~9 까지의 수를 최대 1번씩만 사용하면 됨을 알 수 있다.
  따라서 9개의 수를 사용할지/안할지만을 결정하는 2^9 brute force로 해결 가능하다.
  어떤 숫자들을 사용할 지만 정해지면 수를 최소화하기 위해 오름차순으로 배치해야 하는 것이 자명하다.
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

int T, n, chk[10];
vector<int> v;

void go(int idx) {
	if (idx == 10) {
		int sum = 0;
		for (int i = 1; i < 10; i++) if (chk[i]) sum += i;
		if (n != sum) return;
		int r = 0;
		for (int i = 1; i < 10; i++) {
			if (chk[i]) {
				r *= 10;
				r += i;
			}
		}
		v.pb(r);
		return;
	}
	chk[idx] = false;
	go(idx + 1);
	chk[idx] = true;
	go(idx + 1);
	return;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		v.clear();
		memset(chk, false, sizeof(chk));
		cin >> n;
		go(1);
		sort(all(v));
		if (v.empty()) cout << "-1\n";
		else cout << v[0] << "\n";
	}

	return 0;
}
