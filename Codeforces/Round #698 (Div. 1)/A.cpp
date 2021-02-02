//A - Nezzar and Board
/*
  어떤 두 수를 고르면 2x-y가 새로 생긴다.
  즉 z = 2x-y인 z가 생긴다는 말이고, 이는 y x z 혹은 z x y 순서의 등차수열을 생성하는 것을 알 수 있다.
  즉 우리가 새로 만들 수 있는 수는 처음의 주어진 수들을 항으로 하는 등차수열에 포함된 수들이다.
  현재 주어진 수들로 표현할 수 있는 최소의 공차는 각 수들간의 차이의 최대공약수이다.
  이를 이용해서 해결하자.
*/

#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()

using namespace std;

ll T, n, k;
ll a[202020];

ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		ll g = a[1] - a[0];
		for (int i = 1; i < n - 1; i++) g = gcd(g, a[i + 1] - a[i]);

		bool flg = true;
		if (g == 1) cout << "YES\n";
		else {
			if ((k - a[0]) % g == 0) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
