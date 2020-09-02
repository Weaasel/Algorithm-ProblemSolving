//개구리 1
/*
  개구리가 (a,b)까지 도달한 다음 왔다갔다하는 상황을 가정한다.
  c = 2*k + |a| + |b| 여야 한다.
*/

#include <iostream>
#include <math.h>
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> a >> b >> c;
	a = abs(a), b = abs(b);
	if (a + b <= c && (c - a - b) % 2 == 0) cout << "YES";
	else cout << "NO";

	return 0;
}
