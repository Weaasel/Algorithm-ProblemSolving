//C - Palindromic Paths	
/*
  (1,1) (n,m) 으로부터 dist가 같은 점들끼리는 값이 같아야 한다. 왜인지는 시간을 두고 생각해보면 알 수 있다.
  그러나 중앙에 있는 한 줄은 원래 값을 가져도 된다. palindrome string에서의 중앙과 같은 포지션이니까.
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
int T, n, m;
int a[31][31], res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		res = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		for (int dst = 0; dst < (n + m - 1) / 2; dst++) {
			int cnt0 = 0, cnt1 = 0;
			for (int i = 0; i <= dst; i++) {
				int r = 1 + i, c = 1 + (dst - i);
				if (r<1 || r>n) continue;
				if (c<1 || c>m) continue;
				if (a[r][c] == 1) cnt1++;
				else cnt0++;
			}
			for (int i = 0; i <= dst; i++) {
				int r = n - i, c = m - (dst - i);
				if (r<1 || r>n) continue;
				if (c<1 || c>m) continue;
				if (a[r][c] == 1) cnt1++;
				else cnt0++;
			}
			res += min(cnt0, cnt1);
		}
		cout << res << "\n";
	}
	return 0;
}
