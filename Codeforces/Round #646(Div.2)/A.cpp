//Odd Selection
/*
  n개의 숫자 중 x개를 뽑아 홀수로 만들 수 있는지 없는지 판단하는 문제.
  일단 홀수는 홀수개로 최대한 뽑고, 나머지를 짝수개로 뽑아야 함.
*/

#include <iostream>
#include <algorithm>
#define ll long long
#define DIV 1000000007
#define MAX 4000000
using namespace std;

int T, n, x, a[1001], od, ev;
void solve() {
	if (od == 0) {
		cout << "NO";
		return;
	}
	if (od % 2 == 0) od--;
	x -= min(x + x%2 - 1, od);
	if (ev >= x) cout << "YES";
	else cout << "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> x;
		od = 0, ev = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2 == 0)ev++;
			else od++;
		}
		solve();
		cout << "\n";
	}
}
