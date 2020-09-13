//Ubiquity
/*
  10^n - 2*9^n + 8^n을 계산하면 된다. (전체경우 - 0과 9가 없는 경우) + (0과 9 모두 없는 경우)
  음수 보정에 주의
*/

#include <iostream>
#define ll long long
#define DIV 1000000007;

using namespace std;

ll n, a=1, b=1, c=1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		a *= 10, a %= DIV;
		b *= 9, b %= DIV;
		c *= 8, c %= DIV;
	}
	a += 2*DIV;
	cout << (a - 2 * b + c) % DIV;
	return 0;
}
