//수 집합
//Two Pointer, Brute force, Sorting

#include <iostream>
#include <cstdio>
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
#define MAX 
#define DIV 1000000
#define INF 2000000000

using namespace std;

int n, a[1001], num, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		res = -INF;
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<pair<int, pii>> ab, cd;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ab.pb({ a[i] + a[j], {i, j} });
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				cd.pb({ a[i] - a[j], {i, j} });
			}
		}
		sort(ab.begin(), ab.end());
		sort(cd.begin(), cd.end());
		int l = 0, r = 0;
		while (l < ab.size() && r < cd.size()) {
			if (ab[l].first < cd[r].first) l++;
			else if (ab[l].first > cd[r].first) r++;
			else {
				int aa = ab[l].second.first, bb = ab[l].second.second, dd = cd[r].second.first, cc = cd[r].second.second;
				if (aa!=cc && aa!=dd && bb!=cc && bb!=dd) {
					res = max(res, a[dd]);
				}
				l++;
			}
		}
		if (res == -INF) cout << "no solution\n";
		else cout << res << "\n";
	}

	return 0;
}
