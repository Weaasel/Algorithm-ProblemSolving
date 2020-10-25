//A - Reorder	
/*
  Note를 보면 주어진 식의 성질이 보인다.
  i번째 원소 a[i]에 대해 a[i]/i 가 i번 더해지므로,
  배열의 순서와 무관하게 주어진 식은 언제나 모든 수의 합을 나타낸다.
  따라서 만들고 싶은 수 m과 배열의 합이 같은지만 검사하면 된다.
*/

#include <iostream>

using namespace std;

int T, n, s, m;
int a[101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		s = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		if (s == m) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
