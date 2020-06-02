//C - Similar Pairs	

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

int T, n, a[51], od, ev;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		od = 0, ev = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2 == 0) ev++;
			else od++;
		}
		if (od % 2 == 0) cout << "YES\n";
		else {
			bool flg = false;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (abs(a[i] - a[j]) == 1) flg = true;
				}
			}
			if (flg) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
