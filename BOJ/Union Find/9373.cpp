//복도 뚫기
//disjoint-set, union-find, binary search

/*
  끝없는 복도 위에서 너비가 주어지고, 길을 가로막는 원들의 정보가 주어졌을 때,
  지나갈 수 있는 물체의 최대 반지름을 구하는 문제.
  
  지나갈 수 있는 물체의 반지름 r을 이분탐색해서 해결했다.
  각 시행마다 check 함수에서 하는 일은, 반지름이 r만큼 늘어난 원들을 서로 union해주고,
  그 합쳐진 물체(단일 원일 수도 있다) 의 양쪽 사이를 물체가 모두 지나갈 수 있는가를 검사한다.
  이 검사를 한번이라도 통과하지 못한다면 그냥 지나갈 수 없는 거다.
  
  예외적으로 원의 개수 n이 0일 때는 너비/2 를 출력해야 하는 처리가 필요했다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

ll T, n, w;
double x[1001], y[1001], r[1001];
int par[1001];

int find(int u) {
	if (par[u] < 0) return u;
	return par[u] = find(par[u]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[u] += par[v];
	par[v] = u;
	return true;
}

bool check(double rr) {
	memset(par, -1, sizeof(par));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) <= (r[i] + r[j] + 2 * rr) * (r[i] + r[j] + 2 * rr)) {
				merge(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (find(i) == find(j) && x[i] - r[i] - 2 * rr <= 0 && x[j] + r[j] + 2 * rr >= w) {
				return false;
			}
		}
	}
	return true;
}

double bsearch() {
	double l = 0, r = 50001, ans = 0.0;
	while (r - l >= 0.0000001) {
		double mid = (l + r) / 2.0;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid + 0.0000001;
		}
		else {
			r = mid - 0.0000001;
		}
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	cout << fixed;
	cout.precision(6);
	while (T--) {
		cin >> w >> n;
		if (n == 0) {
			cout << (double)w / 2 << "\n";
		}
		else {
			for (int i = 0; i < n; i++) {
				cin >> x[i] >> y[i] >> r[i];;
			}
			double ans = bsearch();
			if (ans == 0.0) cout << 0 << '\n';
			else cout << ans << '\n';
		}
	}
	return 0;
}
