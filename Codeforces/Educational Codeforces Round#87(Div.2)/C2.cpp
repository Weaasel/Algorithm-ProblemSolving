// C2 - Not so Simple Polygon Embedding	
/*
  바로 위에 있는 C1과 동일한 풀이이다.
  차이점은, 이전 문제에서는 시작점 기준을 두 가지로 잡았어도 됐고,
  이 문제에서는 n가지로 나누어 잡아야 한다는 것이다.
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 1e9
#define eps 1e-9
#define PI 3.14159265
using namespace std;

ll T;
double n, ans, rr;

bool chk1(double r) {
	double rad = PI / n;
	return 2.0*r*r*(1.0 - cos(rad)) >= 1.0;
}

bool chk(double r) {
	r /= 2.0;
	double rad = PI / n; //한 변에 해당하는 각
	double x = 0, y = -1.0*rr;
	bool flg1 = true;
	for (int i = 0; i < 2 * n; i++) {
		if (x > r || x < -1.0*r || y > r || y < -1.0*r) flg1 = false;
		double nx = cos(rad)*x - sin(rad)*y, ny = sin(rad)*x + cos(rad)*y;
		x = nx, y = ny;
	}

	bool flg2 = true;
	x = rr*sin(rad / 2.0), y = -1.0*cos(rad / 2.0)*rr;
	for (int i = 0; i < 2 * n; i++) {
		if (x > r || x < -1.0*r || y > r || y < -1.0*r) flg2 = false;
		double nx = cos(rad)*x - sin(rad)*y, ny = sin(rad)*x + cos(rad)*y;
		x = nx, y = ny;
	}
	return (flg1 || flg2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 2) {
			printf("1\n");
			continue;
		}
		double l = 1, r = 100000, mid;
		rr = INF;
		while (r - l > eps) {
			mid = (l + r) / 2.0;
			if (chk1(mid)) {
				rr = min(rr, mid);
				r = mid - eps;
			}
			else l = mid + eps;
		}
		//rr이 반지름 길이
		l = 1, r = 100000, mid, ans = INF;
		while (r - l > eps) {
			mid = (l + r) / 2.0;
			if (chk(mid)) {
				ans = min(ans, mid);
				r = mid - eps;
			}
			else l = mid + eps;
		}

		printf("%.7lf\n", ans);
	}
	return 0;
}
