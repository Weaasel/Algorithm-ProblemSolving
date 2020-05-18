// C1 - Simple Polygon Embedding	
/*
  2n-gon : 볼록 2n 정다각형이다. 이 다각형을 포함하는 가장 작은 정사각형의 한 변의 길이를 구하는 문제이다.
  
  볼록다각형의 외접원을 구하고, 이 원을 기준으로 볼록 다각형의 점들의 위치를 잘 잡았을 때,
  해당 변 길이를 가지는 정사각형의 내부에 모든 점이 위치하는지를 검사하였다.
  
  외접원의 반지름을 구할 때, 정사각형 한 변의 길이를 구할 때, 이분탑색을 총 두번 진행한다.
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
