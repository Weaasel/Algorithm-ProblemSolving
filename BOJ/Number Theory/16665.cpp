//fractions
//Number Theory, Euler set
/*
  우리가 n을 1이상의 coprime {a, b} 로 나눴을 때,
  문제는 b*x + a*y = n-1 인 {x, y}를 찾는 문제로 바뀐다. (0 < x < a, 0 < y < b)
  이 방정식이 만족하는 해 x, y가 항상 존재한다는 정수론 기반 증명이 가능하기 때문에,
  1 ~ a-1 범위를 전부 탐색해 x를 찾을 수 있다.
  
  증명) gcd(a,b) = 1 이기 때문에 x*b = -1(mod a) 인 x가 [1, a-1] 사이에 존재한다.
  그러한 x를 가정하면, y = (n -1 -b*x)/a 가 되는데, 우선 이 y가 b보다 작은것은 자명하다. (n/a = b이므로)
  그리고 b*x <= b*(a-1) = n - b 이므로, 0 < n-1-b*x 이 보장된다.
  따라서 조건 범위를 만족하는 {x,y}가 항상 존재한다.
*/

#include <iostream>
#include <vector>
#define pii pair<int, int>
#define pb push_back

using namespace std;

int k, n;
vector<pii> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> k;
	n = k;
	for (int i = 2; i*i <= n; i++) {
		if (n%i != 0) continue;
		int cnt = 0;
		while (n%i == 0) {
			cnt++;
			n /= i;
		}
		v.pb({ i,cnt });
	}
	if (n > 1) v.pb({ n,1 });
	if (v.size() < 2) return cout << "NO", 0;
	int a = 1, b = 1;
	for (int i = 0; i < v[0].second; i++) a *= v[0].first;
	for (pii p : v) 
		for (int i = 0; i < p.second; i++) b *= p.first;
	
	b /= a;
	for (int x = 1; x < a; x++) {
		if ((k - 1 - b * x) % a == 0) {
			int y = (k - 1 - b * x) / a;
			cout << "YES\n2\n";
			cout << x << " " << a << "\n";
			cout << y << " " << b << "\n";
			return 0;
		}
	}
	return 0;
}
