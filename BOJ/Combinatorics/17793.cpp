//Lucky Draw
//Combinatorics
/*
  조합론을 공부하기 좋은 문제다.
  n명의 사람, 각 사람은 k라이프, 각 턴에 라이프가 안 깎일 확률이 p로 주어질 때,
  draw(2명 이상의 사람이 동시에 죽으며 끝나는) 확률을 구하는 문제이다.
  
  1.0 - (1명만 이기는) 확률을 구한다.
  1명만이 이기는 확률은 nC1 * 특정 턴 t에서 1명이 죽고, 나머지는 t-1 이하의 턴에서 죽는 확률이다.
  t를 k ~ 2000(대략 1e-6의 오차를 벗어나기 위한) 까지 loop를 돌면서 각 턴에 대해 해당하는 확률을 구하면 된다.
  
  t턴에서 1명이 죽고 나머지는 t-1 이하 턴에서 죽을 확률을 구해보자.
  어떤 한 사람이 t턴에서 죽을 확률을 d[t]라고 하면,
  d[t] * (d[1]+d[2]+...+d[t-2]+d[t-1])^(n-1) 을 하면 된다. (1명은 딱 t턴에 죽고, 나머지 n-1명은 1번째, 2번째, ... t-1번째 턴에서 죽는 확률들의 합)
  
  d[t]는 어떻게 구할까?
  t턴에서 딱 죽으려면, t 턴에서는 라이프가 깎이는게 고정이고, 나머지 t-1턴에서는 k-1의 라이프만 적절히 깎이면 된다.
  이 확률은 (t-1)C(k-1) * (1-p)^(k-1) * p^(t-k) 로 표현 가능하다.
  
  계속 틀렸던 이유는 combination을 정수형으로 쓰듯이 구현하는 바보같은 실수를 했기 때문이다.
  이런 문제에서는 그냥 확률 먼저 구해두고 naive하게 nCk를 계산하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

ll n, k;
double p, d[100001], psum[100001];

int main() {
	cin >> n >> k >> p;
	double res = 0;
	for (int i = k; i <= 2000; i++) {
		double die = pow(1.0 - p, k)*pow(p, i - k);
		for (ll j = 0; j < k - 1; j++) die *= i - 1 - j;
		for (ll j = 1; j <= k - 1; j++) die /= j;
		d[i] = die;
		psum[i] = psum[i - 1] + d[i];
		double bef = psum[i - 1] - psum[k - 1];
		double cur = n;
		cur *= d[i] * pow(bef, n - 1);
		res += cur;
	}
	printf("%.8lf", 1.0 - res);
	return 0;
}
