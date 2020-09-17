//배
//greedy
/*
  실제 시뮬레이션을 통해 해결한다.
  어떤 크레인을 볼 때 해당 크레인으로 옮길 수 있는 가장 무거운 짐을 옮기는 것이 이득이다.
  따라서 multiset에 짐들을 모두 넣어두고 upper bound - 1 로 이런 값을 찾는다.
*/

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m, a[51], res, mx;
multiset<int> ms;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		mx = max(mx, num);
		ms.insert(num);
	}
	if (mx > a[n - 1]) return cout << -1, 0;
	while (1) {
		if (ms.empty()) break;
		res++;
		for (int i = 0; i < n; i++) {
			if (ms.empty()) break;
			//a[i]이하의 최대값을 알고 싶다
			auto it = ms.upper_bound(a[i]);
			if (it != ms.begin()) {
				it--;
				ms.erase(it);
			}
		}
	}
	cout << res;
	return 0;
}
