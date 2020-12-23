//피보나치 음악
//Math, Pisano Period
/*
  피보나치수열은 f[n-2], f[n-1]의 조합으로 f[n]이 결정된다.
  즉 2개의 연속한 수의 조합으로 다음 수가 정해진다.
  따라서 modulo m을 하게 되면 이 조합은 최대 m*m가지가 등장할 수 있고,
  m*m이하의 주기를 갖는다는 것을 관찰할 수 있다.
  m <= 1000 이므로 최대 100만번의 iteration을 통해 주기(처음과 같은 f1, f2쌍 등장)를 찾는다.
  그리고 이 수들을 한 자리씩 분리해 주면 이제 input n에 대해 (n-1) % vector.size() 번째 수를 출력하면 된다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

ll n, m, q;
int f[1010101], sz;
vector<int> v;

ll period(ll m) {
	ll f1 = 1, f2 = 1, f3;
	for (int i = 0; i < m*m; i++) {
		f3 = (f1 + f2) % m;
		f1 = f2;
		f2 = f3;
		if (f1 == 1 && f2 == 1) return i + 1;
	}
}

void put(int a) {
	vector<int> tmp;
	if (a == 0) {
		v.pb(0);
		return;
	}
	while (a > 0) {
		tmp.pb(a % 10);
		a /= 10;
	}
	reverse(all(tmp));
	for (int t : tmp) v.pb(t);
}

int go(ll n) {
	n %= sz;
	return v[n];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> q >> m;
	ll p = period(m);
	f[1] = 1, f[2] = 1;
	for (int i = 3; i <= p; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= m;
	}
	for (int i = 1; i <= p; i++) put(f[i]);
	sz = v.size();

	for (int i = 0; i < q; i++) {
		cin >> n;
		cout << go(n-1) << "\n";
	}

	return 0;
}
