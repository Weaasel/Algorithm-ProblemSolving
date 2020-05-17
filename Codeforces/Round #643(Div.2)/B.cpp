// B - Young Explorers

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
#define INF 2e9
using namespace std;

int T, n, a, cnt[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a;
			cnt[a]++;
		}
		int rem = 0, res = cnt[1];

		for (int i = 2; i <= n; i++) {
			res += (cnt[i] + rem) / i;
			rem = (cnt[i] + rem) % i;
		}
		cout << res << "\n";
	}
	return 0;
}
