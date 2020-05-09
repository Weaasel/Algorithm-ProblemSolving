//C. K-th Not Divisible by n
/*
  n으로 나누어 떨어지지 않는 k번째 수를 구하는 문제이다.
  사실 k에 k/n 만큼을 더해주고 적절히 처리하면 되는 성질이 있을 법 했지만,
  빠른 구현을 위해
  "n으로 나누어 떨어지지 않는 수가 k개인 수" 를 이진탐색으로 구했다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define pb push_back
#define pii pair<int, int>
#define INF 1e9
#define ll long long
using namespace std;
int T, n, k;

int cnt(ll val) {
	return val - val / n;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> k;
		ll l = 1, r = 2e9, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (cnt(mid) < k) l = mid + 1;
			else r = mid - 1;
		}
		cout << l << "\n";

	}
}
