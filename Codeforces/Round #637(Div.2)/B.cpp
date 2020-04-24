//B. Nastya and Door

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
#define INF 2000000000

using namespace std;
int T, n, k, mx, mxidx, l, r;
int a[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		deque<int> dq;
		for (int i = 1; i <= k; i++) {
			if (i == 1 || i == k) continue;
			if (a[i - 1] < a[i] && a[i] > a[i + 1]) dq.push_back(i);
		}
		mx = dq.size(), mxidx = 1;

		for (int i = 2; i <= n - k + 1; i++) {
			l = i, r = i + k - 1;
			while (!dq.empty() && dq.front() <= l) dq.pop_front();
			if (a[r - 2] < a[r - 1] && a[r - 1] > a[r]) dq.push_back(r - 1);

			if (mx < dq.size()) {
				mx = dq.size();
				mxidx = l;
			}
		}
		cout << mx + 1 << " " << mxidx << "\n";
	}
	return 0;
}
