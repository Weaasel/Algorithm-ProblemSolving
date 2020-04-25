//C - Alternating Subsequence	

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
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

ll T, n, mx;
ll a[200001], res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		res = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int walk = 0, sz = 0;
		mx = a[0];
		walk++;

		while (walk < n) {
			if (a[walk] * a[walk - 1] > 0) mx = max(a[walk], mx);
			else {
				res += mx;
				mx = a[walk];
			}
			walk++;
		}
		res += mx;
		cout << res << "\n";
	}

	return 0;
}
