//From A to B
//Ad-hoc
/*
  선택지는 2로 나누거나(짝수일 때) 1을 더하는 것이다.
  즉, a <= b라면 더하기만 하면 된다.
  a > b라면 a가 b 이하가 될 때까지 a를 줄이고 b가 될 때까지 더하면 된다.
  이 과정에서 a +1 +1 /2 와 a /2 +1 은 결과가 같지만 연산횟수의 차이가 있으므로,
  2로 나눌 수 있을 때는 나누는 것이 무조건 이득임을 알 수있다.
*/

#include <iostream>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	if (a <= b) cout << b - a;
	else {
		int cnt = 0;
		while (a > b) {
			if (a % 2 == 0) {
				a /= 2;
				cnt++;
			}
			else {
				a = (a + 1) / 2;
				cnt += 2;
			}
		}
		cout << cnt + b - a;
	}
	return 0;
}
