//Fear Factoring
//Number Theory
/*
  주어진 a와 b 사이에 있는 수들의 약수의 합을 구하는 문제이다.
  각 수의 약수를 전부 구해 더하기보단, 모든 수들에 대해 그 수의 배수들의 개수를 세는 형태로 해결하자.
  (ex. 2는 a,b 사이에 있는 2의 배수의 개수*2 만큼 기여할 것이다.)
  a,b의 범위가 10^12 이하이기 때문에 모든 셈을 할 수 없고,
  어떤 약수가 정해지면 그에 대응하는 약수가 정해진다는 아이디어를 이용한다.
  sqrt(b)까지 연산하면 된다.
  중복을 제거해야 하는 문제 때문에 식이 약간은 복잡하지만,
  예를 들어 생각해보자.
  3의 입장에서 3*1, 3*2, 3*3, 3*4 ... 등으로 쓰이는데
  이 중 3*1, 3*2로 쓰이는 3은 더하면 안된다.(1, 2가 약수일 때 이미 더해졌다.)
  그리고 3*3에서의 3은 1번만 더해져야 한다.
  이 두가지만 생각하고 짜면 된다.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;
ll a, b, res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> a >> b;
	ll sq = sqrt(b);
	for (ll i = 1; i <= sq; i++) {
		res += i * (1 + (b / i - (max(i*i, a) + i - 1) / i));
		ll s = a / i, e = b / i;
		if (a%i > 0) s++;
		s = max(i + 1, s);
		if (s > e) continue;
		res += (s + e)*(e - s + 1) / 2;
	}

	cout << res;
	return 0;
}
