//C - Dominant Piranha	
/*
  Dominant Piranha가 되려면 주어진 수들 중 가장 크고, 인접한 수들 중 하나라도 자신보다 작으면 된다.
  사실 이것만 검사하고 결정했어도 되는데, 나는 이런 piranha를 찾고 양쪽으로 먹으며 시뮬레이션했다.
*/

#include <iostream>

using namespace std;

int T, n, a[303030];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--) {
		int res = 1;
		cin >> n;
		a[0] = INF, a[n + 1] = INF;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] > a[res]) res = i;
			else if (a[i] == a[res]) {
				if (a[i - 1] < a[i] || a[i + 1] < a[i]) res = i;
			}
		}
		int l = res - 1, r = res + 1;
		bool flg = true;
		while (flg && l >= 1 && r <= n) {
			if (a[l] < a[res]) {
				l--, a[res]++;
			}
			else if (a[r] < a[res]) {
				r++, a[res]++;
			}
			else flg = false;
		}
		while (flg && l >= 1) {
			if (a[l] < a[res]) {
				l--, a[res]++;
			}
			else flg = false;
		}
		while (flg && r <= n) {
			if (a[r] < a[res]) {
				r++, a[res]++;
			}
			else flg = false;
		}
		if (flg) cout << res << "\n";
		else cout << "-1\n";
	}

	return 0;
}
