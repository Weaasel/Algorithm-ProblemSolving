//Product Max
/*
  case work를 해도 되겠지만, 가끔은 뇌를 비우고 이런 naive한 풀이로 접근하도록 하자.
*/

#include <iostream>
using namespace std;

ll a, b, c, d, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	cout << max({ a*c, a*d, b*c, b*d });
	return 0;
}
