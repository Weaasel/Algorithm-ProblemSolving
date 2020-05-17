// A - Sequence with Digits	

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
#define INF 1e18
using namespace std;

ll T, n, k, cnt[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		k--;
		for (int i = 0; i < k; i++) {
			ll nn = n;
			memset(cnt, 0, sizeof(cnt));
			while (nn > 0) {
				cnt[nn % 10]++;
				nn /= 10;
			}
			if (cnt[0] > 0) break;
			vector<int> v;
			for (int j = 0; j < 10; j++) if (cnt[j] > 0) v.pb(j);
			sort(all(v));
			n += v[0] * v[v.size() - 1];
		}
		cout << n << "\n";
	}

	return 0;
}
