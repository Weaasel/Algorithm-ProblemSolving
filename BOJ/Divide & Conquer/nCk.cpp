//  boj.kr/11401
//  이항계수3
//  nCk를 O(logDIV) 구하는 코드.
//  설명은 http://blog.naver.com/yjyj1027/221940371903 에 있습니다.


#include <iostream>
#include <algorithm>
#define ll long long
#define DIV 1000000007
#define MAX 4000000
using namespace std;

ll fact[MAX + 1], n, k;

void init() {
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i < MAX + 1; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= DIV;
	}
}

ll fastpow(ll a, ll pow) {
	if (pow == 0) return 1LL;
	if (pow == 1) return a;

	ll tmp = fastpow(a, pow / 2);
	tmp *= tmp; tmp %= DIV;
	if (pow % 2 == 0) return tmp;
	else return (tmp*a) % DIV;
}

ll comb(int n, int k) {
	ll res = fact[n];
	res *= fastpow(fact[k], DIV - 2);
	res %= DIV;
	res *= fastpow(fact[n-k], DIV - 2);
	return res % DIV;
}

int main() {
	init();
	cin >> n >> k;
	cout << comb(n, k);
}
