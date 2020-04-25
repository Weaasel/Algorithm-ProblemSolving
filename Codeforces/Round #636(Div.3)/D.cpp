//D - Constant Palindrome Sum	

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
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int a[200001], res[400001], ans, n, k, T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 2; i <= 2 * k; i++) res[i] = 0;
		ans = INF;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n / 2; i++) {
			int x = min(a[i], a[n - 1 - i]), y = max(a[i], a[n - 1 - i]);
			res[2] += 2;
			res[x + 1] -= 1;
			res[x + y] -= 1;
			res[x + y + 1] += 1;
			res[y + k + 1] += 1;
		}
		for (int i = 2; i <= 2 * k; i++) {
			res[i] += res[i - 1];
			ans = min(ans, res[i]);
		}
		cout << ans << "\n";
	}

	return 0;
}
