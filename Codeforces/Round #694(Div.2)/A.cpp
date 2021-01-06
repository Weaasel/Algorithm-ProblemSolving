//A - Strange Partition
/*
  모든 원소들에 x를 나누고 ceil을 취하기 때문에, 원소의 개수가 많을 수록 이득이다.
  즉 min값은 전부 합치고 x로 나누는 것이고,
  max값은 전부 따로 x로 나누는 것이다.
  실수형 자료형을 사용했다가 틀린 사람들은 ceil(a/b) = (a-1)/b + 1 임을 기억하자.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T, n, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> x;
		ll sum = 0, mx = 0;
		for (int i = 0; i < n; i++) {
			ll num; cin >> num;
			sum += num;
			mx += (num - 1) / x + 1;
		}
		sum = (sum - 1) / x + 1;
		cout << sum << " " << mx << "\n";
	}
	return 0;
}
