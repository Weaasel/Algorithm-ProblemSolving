//A - Sum and Product	

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

ll s, p, a, b;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s >> p;
	for (int i = 1; i <= sqrt(p); i++) {
		if (p%i > 0) continue;
		if (i + p / i == s) return cout << "Yes", 0;
	}
	cout << "No";
	return 0;
}
