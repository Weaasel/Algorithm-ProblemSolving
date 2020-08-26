//NC 문자열
//Combinatorics
/*
  주어진 문자열은 N만 포함하거나, C만 포함하거나, NC 패턴을 포함하거나, CN패턴만을 포함하거나 네가지로 나눌 수 있다.
  표현할 수 있는 문자열의 모든 조합에서 C...CN...N 형태로 조합을 구성하는 경우의 수를 빼면 NC 패턴을 포함하는 경우의 수를 구할 수 있다.
  CN패턴이 반복되면 NC패턴이 되기 때문에 CN패턴 문자열은 1개 이하만 사용할 수 있음에 주의하자.
  
  f(n): n개의 문자열이 있을 때 조합할 수 있는 경우의 수
  -> res = f(n) - f(#C문자열 개수) * (#CN문자열 개수+1) * f(#N문자열 개수) 라고 할 수 있다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <unordered_set>
using namespace std;
using ll = long long;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define MOD 1000000007
const ll INF = 1e18, mxn = 100010, MAX = 100000;

ll n, a, b, c, d; //a: N만 b: C만 c: CN만
ll res;
string s;
ll fact[MAX + 1];

void init() {
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i < MAX + 1; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
}

ll fastpow(ll a, ll pow) {
	if (pow == 0) return 1LL;
	if (pow == 1) return a;

	ll tmp = fastpow(a, pow / 2);
	tmp *= tmp; tmp %= MOD;
	if (pow % 2 == 0) return tmp;
	else return (tmp*a) % MOD;
}

ll permu(int n, int k) {
	ll res = fact[n];
	res *= fastpow(fact[k], MOD - 2);
	return res % MOD;
}

ll f(int n) {
	ll ret = 0;
	for (int i = 0; i <= n; i++) {
		ret += permu(n, i);
		ret %= MOD;
	}
	return ret;
}

int main() {
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int sz = s.size(), ni, ci;

		for (ni = 0; ni < sz; ni++) if (s[ni] == 'N') break;
		if (ni == sz) { //C만 있다
			b++;
			continue;
		}
		for (ci = 0; ci < sz; ci++) if (s[ci] == 'C') break;
		if (ci == sz) { //N만 있다
			a++;
			continue;
		}
		//CN : C 앞에 N 이 있으면 안됨
		for (ci = sz - 1; ci >= 0; ci--) if (s[ci] == 'C') break;
		for (ni = ci; ni >= 0; ni--) if (s[ni] == 'N') break;
		if (ni == -1) c++;
	}

	res = f(n) - ((f(a)*(c+1) % MOD)*f(b)) % MOD;
	cout << (res + MOD) % MOD;
	return 0;
}
