//Financial Planning
//Binary Search
/*
  여러 투자상품들이 있다. 가격과 매일 벌어다주는 수익으로 표현된다.
  M원의 수익을 만들기 위해 최소 필요한 일 수를 구하는 문제이다.
  d 일이 지났을 때 M원을 만들수 있는지에 대한 결정문제로 바꿀 수 있다.
  d*p[i] - c[i] > 0 이면 i번째 상품을 구입한다.
  
  문제 특성상 n가지의 상품에 대한 수익을 더하는 과정에서 overflow가 날 수 있기 때문에
  m 이상이 되면 바로 return할 수 있도록 만들자.
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define INF 2000000007

using namespace std;

int n;
ll m, p[101010], c[101010], res = INF;

bool chk(ll d) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += max(0LL, d*p[i] - c[i]);
		if (sum >= m) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i] >> c[i];
	ll l = 0, r = INF, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			res = min(res, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
	return 0;
}
