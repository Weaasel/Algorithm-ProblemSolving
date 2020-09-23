//쿨한 물건 구매
//math, brute force
/*
  p원짜리 지폐와 q원짜리 지폐를 잘 조합해 d원짜리 물건을 사야 할 때, 지불해야 할 최소 금액을 출력하는 문제이다.
  wlog p<=q 라고 가정하면, q원짜리 지폐를 0장 ~ d/q + 1 장 사용하는 경우를 모두 비교하면 된다.
  문제는 입력 범위상 d/q가 굉장히 커지는 경우인데,
  잘 생각해 보면 q를 p장 사용하는 경우는 q를 0장 사용하는 경우와 동치이다. (q*p = p*q)
  q를 p+1장 사용하는 경우는 q를 1장 사용하는 경우와 동치이다.
  따라서 봐야 할 경우의 수는 min(d/q, p-1) 이 되고 이 숫자는 절대 tle가 나지 않는 범위에서 수행된다.
*/

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll d, p, q, cand = INF;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> d >> p >> q;
	if (p > q) swap(p, q);

	for (int i = 0; i <= min(d / q + 1, p - 1); i++) {
		ll cur = d - q * i, tmp = i * q;
		if (cur <= 0) {
			cand = min(cand, tmp);
			continue;
		}
		tmp += ((cur - 1) / p + 1)*p;
		cand = min(cand, tmp);
	}
	cout << cand;
	return 0;
}
