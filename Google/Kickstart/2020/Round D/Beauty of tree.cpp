//just small case
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int T, n, a, b;
int par[500001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int cnt = 0;
		cin >> n >> a >> b;
		for (int i = 2; i <= n; i++) cin >> par[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				set<int> s;
				int na = i, nb = j;
				s.insert(i); s.insert(j);
				while (na != 0) {
					for (int k = 0; k < a; k++) {
						na = par[na];
					}
					if (na > 0) s.insert(na);
				}
				while (nb != 0) {
					for (int k = 0; k < b; k++) {
						nb = par[nb];
					}
					if (nb > 0) s.insert(nb);
				}
				cnt += s.size();
			}
		}
		printf("Case #%d: %.7lf\n", tc, (double)cnt / (n*n));
	}
	return 0;
}
