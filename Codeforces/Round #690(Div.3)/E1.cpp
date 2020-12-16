//E1 - Close Tuples (easy version)	
//Combinatorics
/*
  각 수가 몇개씩 나오는 지 센다. 그리고 각각의 경우의 수를 전부 더한다.
  1. 같은 수로 3개를 뽑는 경우
  2. 차이가 1인 두 수로 3개를 뽑는 경우
  3. 차이가 2인 두 수로 3개를 뽑는 경우
  4. 연속한 세 수를 뽑는 경우
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll T, n, res;
ll c[202020];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		res = 0;
		for (int i = 1; i <= n; i++) c[i] = 0;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			c[num]++;
		}
		for (int i = 1; i <= n; i++) 
			res += c[i] * (c[i] - 1)*(c[i] - 2) / 6;
		for (int i = 1; i <= n - 1; i++) {
			res += c[i] * (c[i] - 1) / 2 * c[i + 1];
			res += c[i+1] * (c[i+1] - 1) / 2 * c[i];
		}
		for (int i = 1; i <= n - 2; i++) {
			res += c[i] * (c[i] - 1) / 2 * c[i + 2];
			res += c[i + 2] * (c[i + 2] - 1) / 2 * c[i];
			res += c[i] * c[i + 1] * c[i + 2];
		}
		cout << res << "\n";
	}

	return 0;
}
