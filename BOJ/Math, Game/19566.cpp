//수열의 구간 평균
/*
  조건을 만족하는 구간의 개수를 세는 문제 중 웰노운 유형이다.
  psum[r] - psum[l-1] = k*(r-l+1) 인 l, r의 개수이므로
  psum[r] - k*r = psum[l-1] - k*(l-1) 로 볼 수 있고,
  모든 A의 원소들에 k를 뺀 후 psum을 구해 개수를 세면 된다.
*/

#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
ll n, k, res, a[200001];
map<ll, ll> m;
int main() {
	cin >> n>>k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1] - k;
	}
	for (int i = 0; i <= n; i++) {
		res += m[a[i]];
		m[a[i]]++;
	}
	cout << res;
}
