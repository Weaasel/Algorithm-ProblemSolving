//C. Nastya and Strange Generator

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

int T, n, k;
int a[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int flg = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i + 1]) continue;
			if (a[i] < a[i + 1]) {
				if (a[i + 1] - a[i] > 1) flg = 1;
			}
		}
		if (flg) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
