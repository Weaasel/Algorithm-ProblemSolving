//Product Max

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
