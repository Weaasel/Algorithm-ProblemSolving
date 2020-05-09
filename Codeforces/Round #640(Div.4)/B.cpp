//B. Same Parity Summands
/*
  주어진 수 n을 k개의 홀수 or 짝수의 합으로 표현할 수 있는지 묻는 문제였다.
  n과 k의 parity에 따라 홀수로 표현할 수 있으면 1을 k-1개, 짝수로만 표현할 수 있으면 2를 k-1개 넣는 식으로 구현했다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define pii pair<int, int>
#define INF 1e9

using namespace std;
int T, n, k;

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> k;
		if (n % 2 == 1 && k % 2 == 0) cout << "NO\n";
		else if (n % 2 == 0 && k % 2 == 1) {
			if (n < 2 * k) cout << "NO\n";
			else {
				cout << "YES\n";
				for (int i = 0; i < k - 1; i++) cout << "2 ";
				cout << n - 2 * k + 2 << "\n";
			}
		}
		else {
			if (n < k) cout << "NO\n";
			else {
				cout << "YES\n";
				for (int i = 0; i < k - 1; i++) cout << "1 ";
				cout << n - k + 1 << "\n";
			}
		}
	}
}
