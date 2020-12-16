//D - Add to Neighbour and Remove	
//Brute force
/*
  주어진 연산이 결국 연속한 원소들을 한 그룹으로 만드는 연산이다.
  즉 전체 합의 약수들 중 적당히 잘 partition 할 수 있는 최대 개수를 구하면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int T, n, sum;
int a[3030];

bool chk(int cnt) {
	if (sum%cnt > 0) return false;
	int g = sum / cnt, tmp = 0;

	for (int i = 0; i < n; i++) {
		tmp += a[i];
		if (tmp > g) return false;
		if (tmp == g) {
			tmp = 0;
			cnt--;
		}
	}
	return cnt == 0;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}

		for (int i = n; i >= 1; i--) {
			if (chk(i)) {
				cout << n - i << "\n";
				break;
			}
		}
	}

	return 0;
}
