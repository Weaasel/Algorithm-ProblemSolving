//Billiards
//Math
/*
  당구장에서 공을 쳐서 한번의 쿠션으로 다른 공을 맞추는 문제이다.
  x축을 기준으로 점을 대칭시키고 직선으로 연결하는 수학문제.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e15+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265

using namespace std;

double sx, sy, gx, gy, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> sx >> sy >> gx >> gy;
	gy = -gy;
	res = -sy * (sx - gx) / (sy - gy) + sx;
	printf("%.6lf", res);
	return 0;
}
