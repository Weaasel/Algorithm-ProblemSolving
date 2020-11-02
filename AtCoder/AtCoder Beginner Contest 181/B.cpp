//B - Trapezoid Sum	
#include <iostream>
#define ll long long

using namespace std;

ll res, n, a, b;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		res += (a + b)*(b - a + 1) / 2;
	}
	cout << res;
	return 0;
}
