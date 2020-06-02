//G - A/B Matrix	

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

int T, n, m, a, b;
int mat[51][51], sum[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> a >> b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j] = 0;
			}
		}
		memset(sum, 0, sizeof(sum));
		if (n*a != m * b || a > m || b > n) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int d;
		for (int i = 1; i <= 50; i++) {
			if (i*n % m == 0) {
				d = i;
				break;
			}
		}
		int s = 0, walk, cnt;
		for (int i = 0; i < n; i++) {
			s %= m;
			walk = s;
			cnt = a;
			while (cnt--) {
				mat[i][walk] = 1;
				walk++;
				walk %= m;
			}
			s += d;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << mat[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
