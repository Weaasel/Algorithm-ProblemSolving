//PIZZA ALVOLOC
/*
  두 선분의 교차 여부를 묻는 문제이다.
  두 선분을 AB, CD 라고 할 때,
  AB와 C, D 간의 CCW의 곱이 음수여야 하고 (AB를 기준으로 C, D 가 다른 면에 존재)
  CD와 A, B 간의 CCW의 곱이 역시 음수여야 한다.
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
#define INF 1e+9
const ll DIV = 1e9 + 7;
using namespace std;

pii p[4];
int ccw(pii a, pii b, pii c) {
	int res = a.first*b.second + b.first*c.second + c.first*a.second - a.second*b.first - b.second*c.first - c.second*a.first;
	if (res == 0) return 0;
	return  res > 0 ? 1 : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> p[i].first >> p[i].second;
	if (ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]) < 0 && ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1])) cout << 1;
	else cout << 0;
	return 0;
}
