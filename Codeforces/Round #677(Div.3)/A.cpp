//A - Boring Apartments	
/*
  n 제한이 작아서 n이 몇 번째로 나오는 수인지 계산한다.
  n 제한이 작아서 그냥 시뮬레이션해도 된다.
*/

#include <iostream>

using namespace std;

int T, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n;
		int res = 0, cnt = 0;
		res += 10 * (n % 10 - 1);
		while (n > 0) {
			cnt++;
			n /= 10;
		}
		cout << res + cnt*(cnt+1)/2 << "\n";
	}

	return 0;
}
