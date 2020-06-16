//수리공 항승
//Greedy
/*
  물이 새는 지점들을 정렬해 두고, 앞에서부터 보면서
  
  1. 해당 점은 무조건 테잎을 붙여야 한다.
  2. 그 테잎으로 cover할 수 있는 범위까지 cover하고 넘어가면 된다.
*/

#include <iostream>
#include <algorithm>
using namespace std;
int n, l, a[1001], res;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int wlk = 0, cov;
	while (wlk < n) {
		int cov = a[wlk] + l - 1;
		while (wlk < n && a[wlk] <= cov) wlk++;
		res++;
	}
	cout << res;
	return 0;
}
