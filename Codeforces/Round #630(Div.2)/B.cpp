//B. Composite Coloring

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
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int T, n, a[1001], col[1001], ans;
int prime[12] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 }, used[12];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		map<int, int> check;
		ans = 0;
		int idx = 1;
		memset(used, -1, sizeof(used));
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < 12; j++) {
				if (a[i] % prime[j] == 0) {
					col[i] = j;
					used[j] = 1;
					break;
				}
			}
		}
		for (int i = 1; i < 12; i++) {
			if (used[i] > 0) {
				ans++;
				check[prime[i]] = idx++;
			}
		}
		for (int i = 0; i < n; i++) {
			col[i] = check[prime[col[i]]];
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i++) cout << col[i] << " ";
		cout << "\n";
	}
	return 0;
}
