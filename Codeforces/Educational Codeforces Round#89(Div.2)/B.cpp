//B - Shuffle	
/*
  처음에 [x,x]에서 시작한 구간이 겹치는 구간을 만나면 합쳐지며 점점 넓어지는 형태이다.
  겹치지 않는 구간과 만나면 무시하고 넘어간다.
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
#define DIV 1000000007;
const ll INF = 4e10;

using namespace std;
int T, n, x, m;
int l[101], r[101], l1, r1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> x >> m;
		for (int i = 0; i < m; i++) {
			cin >> l[i] >> r[i];
		}
		int wlk = 0;
		while ((wlk < m) && (l[wlk] > x || x > r[wlk]))wlk++;
		if (wlk == m) {
			cout << 1 << "\n";
			continue;
		}
		l1 = l[wlk], r1 = r[wlk];
		for (int i = wlk; i < m; i++) {
			if (l1 > r[i] || l[i] > r1) continue;
			l1 = min(l[i], l1);
			r1 = max(r[i], r1);
		}
		cout << r1 - l1 + 1 << "\n";
	}
	return 0;
}
