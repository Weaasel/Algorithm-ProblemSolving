//Takahashi Unevolved
//Greedy
/*
  문제를 단순화하면 a를 곱하거나 b를 더하는 두 연산 중 선택해서 반복할 수 있을 때
  x를 y 이상으로 만드는데 할 수 있는 연산의 최대 횟수이다.
  결국 x가 커질수록 a를 곱하는 연산이 더 나빠지기 때문에
  a*x <= b+x 일 때까지는 a를 곱하고, 남은 만큼 b를 더하면 된다.
  x,y 범위가 10^18이기 때문에 조건을 걸어줄 때 overflow에 주의.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
using namespace std;

ll x, y, a, b, res;

int main() {
	cin >> x >> y >> a >> b;

	while (x <= y / a && (a - 1)*x <= b) {
		res++;
		x = a * x;
	}
	if (x >= y) return cout << res - 1, 0;
	res += (y - x - 1) / b;
	cout << res;

	return 0;
}
