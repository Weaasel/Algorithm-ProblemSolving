//A - XXXXX
/*
  뱡향을 정해 양 끝에서부터 x의 배수인 것들을 지워나간다.
  그렇게 나온 두 답을 비교한다.
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
const ll INF = 1e9;

using namespace std;
int T, n, x, sum;
ll a[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		sum = 0;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum%x > 0) cout << n << "\n";
		else {
			if (a[0] % x > 0 || a[n - 1] % x > 0) cout << n - 1 << "\n";
			else {
				int len1 = n, len2 = n, wlk1 = 0, wlk2 = n - 1;
				while (wlk1 < n && (a[wlk1] % x == 0)) {
					wlk1++;
					len1--;
				}
				while (wlk2 >= 0 && (a[wlk2] % x == 0)) {
					wlk2--;
					len2--;
				}
				if (len1 == 0 && len2 == 0) cout << -1 << "\n";
				else if (len1 == 0) cout << len2 - 1 << "\n";
				else if (len2 == 0) cout << len1 - 1 << "\n";
				else cout << max(len1, len2) - 1 << "\n";
			}
		}
	}
	return 0;
}
