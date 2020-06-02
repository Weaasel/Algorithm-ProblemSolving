//D - Buying Shovels	

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

int T, n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		if (k >= n) cout << 1 << "\n";
		else {
			int mx = -1;
			for (int i = (int)sqrt(n); i >= 1; i--) {
				if (i > k) continue;
				if (n%i == 0 && n / i <= k) {
					mx = i;
				}
			}
			if (mx == -1) cout << n << "\n";
			else cout << mx << "\n";
		}
	}
	return 0;
}
