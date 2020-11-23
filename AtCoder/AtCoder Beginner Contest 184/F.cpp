//F. Programming Contest
//Data Structure, Meet in the middle
/*
  40개의 수가 주어지고 만들고 싶은 상한 T가 주어질 때,
  40개의 수들을 적당히 골라서 그 합이 T 이하가 되는 최대값을 구하는 문제이다.
  수가 40개이기 때문에 적당히 20개씩 쪼개서 2^20 짜리 set 두개를 만들고 적당히 하면 되지 않을까? 싶었다.
  적당히를 좀더 구체화하면,
  set1에서 고른 수를 a라 할 때, set2에서는 T-a 이하의 가장 큰 수를 고르면 된다.
  T-a 이하의 가장 큰 수는 upper_bound(T-a)에서 한칸 내리면 된다. 물론 s2.begin()이라면 넘어간다.
  이렇게 하면 set1에서 고를 수 있는 모든 수(2^20개) 에 대해 log2^20(=20) 의 연산만에 후보를 찾을 수 있다.
  시간복잡도는 O(n*2^(n/2)) 이다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

using namespace std;

ll n, t, a[40], res;

set<ll> s1, s2, t1, t2;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> a[i];
	s1.insert(0);
	s2.insert(0);
	for (int i = 0; i < n / 2; i++) {
		t1 = s1;
		for (ll ss : t1) s1.insert(ss + a[i]);
	}
	for (int i = n / 2; i < n; i++) {
		t2 = s2;
		for (ll ss : t2) s2.insert(ss + a[i]);
	}

	for (ll a1 : s1) {
		ll fnd = t - a1;
		auto it = s2.upper_bound(fnd);
		if (it == s2.begin()) continue;
		it--;
		ll cand = a1;
		cand += *it;
		res = max(res, cand);
	}
	cout << res;
	return 0;
}
