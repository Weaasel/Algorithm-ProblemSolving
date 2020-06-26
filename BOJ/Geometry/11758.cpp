//CCW
/*
  주어진 세 점이 ccw(counter clockwise) 관계인지 여부를 출력하는 문제이다.
  ccw는 세 점의 외적으로 구한다.
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

pii p[3];
int ccw(pii a, pii b, pii c) {
	int res = a.first*b.second + b.first*c.second + c.first*a.second - a.second*b.first - b.second*c.first - c.second*a.first;
	if (res == 0) return 0;
	return  res > 0 ? 1 : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;
	cout << ccw(p[0], p[1], p[2]);
	return 0;
}
