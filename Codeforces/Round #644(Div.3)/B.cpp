//B - Honest Coach	

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
#define MAX 4001
#define DIV 100000LL
#define INF 1e9

using namespace std;

int T, n, s[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i];
		sort(s, s + n);
		int ans = 1000;
		for (int i = 0; i < n - 1; i++) {
			ans = min(ans, s[i + 1] - s[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
