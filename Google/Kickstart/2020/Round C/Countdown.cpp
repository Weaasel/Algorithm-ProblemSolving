// Countdown
/*
  k-countdown : k, k-1, k-2, ... , 3, 2, 1 의 수열로 정의한다.
  주어진 수열에서 k-countdown의 개수를 찾는 문제.
  naive하게 찾으면 된다.
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
#define eps 1e-8
#define PI 3.14159265
using namespace std;

int T, n, k, a[200001], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		vector<int> v;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == k) v.pb(i);
		}
		for (int idx : v) {
			bool flg = 1;
			for (int i = 1;i < k; i++) {
				if (i + idx >= n || a[i + idx] != k - i) {
					flg = 0;
					break;
				}
			}
			ans += flg;
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
