//비드맨
/*
  가장 많은 구슬이 나머지 구슬의 합보다 많다면 전부 깰 수 없다.
  더 적다면 모든 구슬들을 깰 수 있다. (홀수라면 1개가 남을 테지만)
*/

#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n, a[100001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) sum += a[i];
	if (a[n - 1] >= sum) cout << a[n - 1] - sum;
	else {
		sum += a[n - 1];
		cout << sum % 2;
	}
}
