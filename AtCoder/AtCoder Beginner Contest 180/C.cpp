//Cream puff

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
using namespace std;

ll n;
vector<ll> res;

int main() {
	cin >> n;
	for (ll i = 1; i <= sqrt(n); i++) {
		if (n%i == 0) {
			res.pb(i);
			if (i*i != n) res.pb(n / i);
		}
	}
	sort(res.begin(), res.end());
	for (ll i : res) cout << i << "\n";
	return 0;
}
