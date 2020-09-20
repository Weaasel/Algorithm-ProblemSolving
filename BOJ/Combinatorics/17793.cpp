//Lucky Draw
//Combinatorics
/*
  조합론을 공부하기 좋은 문제다.
  n명의 사람, 각 사람은 k라이프, 각 턴에 라이프가 안 깎일 확률이 p로 주어질 때,
  draw(2명 이상의 사람이 동시에 죽으며 끝나는) 확률을 구하는 문제이다.
  
  
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
