//LED
//Binary Search
/*
  최대오차에 대해 이진탐색을 한다.
  우선 첫번째 구간은 [0,err]로 정해져 있기 때문에, 여기에 포함되는 점들은 건너뛰어준다.
  두번째, 세번째 구간의 y값이 될 L1, L2를 정해야 한다.
  L1은 뒤에 남은 점들의 최소값 + err가 되어야 한다.
  L2는 [L1-err, L1+err] 로 담을 수 있는 점들을 최대한 담고 뒤에 남은 점들의 최소값 + err가 되어야 한다.
  [L2-err, L2+err] 로 담을 수 없는 점이 존재하면 이번 오차 err는 불가능한 오차이다.
*/

#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define eps 1e-5
using ii = pair<int, int>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using ll = long long;
const int MOD = 1e9 + 7, INF = 1e9 + 7, mxn = 100010;

int n;
pdd a[303030];
double psum[303030];

bool chk(double err) {
	int s = 0;
	while (s < n && a[s].y <= err) s++;
	double l1 = psum[s];
	while (s < n && a[s].y <= l1 + 2*err) s++;
	double l2 = psum[s];
	while (s < n && a[s].y <= l2 + 2*err) s++;
	return s == n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	sort(a, a + n);
	psum[n] = INF;
	for (int i = n - 1; i >= 0; i--) psum[i] = min(psum[i + 1], a[i].y);
	double l = 0, r = INF, mid, ans = INF;
	if (a[0].x == 0) l = a[0].y;
	
	while (r - l > eps) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			ans = min(ans, mid);
			r = mid - eps;
		}
		else l = mid + eps;
	}
	
	printf("%.1lf", ans);
	return 0;
}
