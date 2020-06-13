//D - Two Divisors	
/*
  어떤 수 n을 소인수분해 했을 때, 소인수가 p1, p2, ... pi 라면
  d1 = p1, d2 = p2*p3*...*pi 로 만들어주면 된다.
  이렇게 했을 때 d1 + d2는 p1, p2, ... , pi 어떤 수로도 나누어떨어지지 않는다.(소수끼리는 서로소)
  따라서 gcd(d1 + d2, n) = 1을 만족하게 된다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DIV 998244353;
const ll INF = 4e10;

using namespace std;
ll n;
ll a[500001], d1[500001], d2[500001];
vector<int> prime;
bool isp[3501];

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(a%b, b);
}

void era() {
	memset(isp, true, sizeof(isp));
	for (int i = 2; i < sqrt(3501); i++) {
		for (int j = i * i; j < 3501; j += i) {
			isp[j] = false;
		}
	}
	for (int i = 2; i < 3501; i++) if (isp[i]) prime.pb(i);
	return;
}

vector<int> go(int n) {
	vector<int> res;
	for (int p : prime) {
		if (n%p == 0) {
			res.pb(p);
			while (n%p == 0) n /= p;
		}
	}
	if (n > 1) res.pb(n);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	era();
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		vector<int> r = go(a[i]);
		if (r.size() <= 1) continue;
		else {
			int sz = r.size(), dd1 = 1, dd2 = 1;
			dd1 *= r[0];
			for (int i = 1; i < sz; i++) {
				dd2 *= r[i];
			}
			d1[i] = dd1, d2[i] = dd2;
		}
	}
	for (int i = 0; i < n; i++) cout << d1[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++) cout << d2[i] << " ";
	cout << "\n";
	return 0;
}
