//Parenting Partnering Returns

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

typedef struct query {
	int s, e, idx;
	char ans;
}query;

int T, n, s, e, Ce, Je, flg;
char ans[1001];
query a[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Ce = -1, Je = -1, flg = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s >> e;
			a[i].s = s; a[i].e = e; a[i].idx = i;
		}
		sort(a, a + n, [&](query x, query y) {
			if (x.s == y.s) {
				return x.e < y.e;
			}
			return x.s < y.s;
		}
			);
		cout << "Case #" << tc << ": ";
		for (int i = 0; i < n; i++) {
			if (Ce <= a[i].s) {
				a[i].ans = 'C';
				Ce = a[i].e;
			}
			else if (Je <= a[i].s) {
				a[i].ans = 'J';
				Je = a[i].e;
			}
			else {
				flg = 1;
				cout << "IMPOSSIBLE\n";
				break;
			}
		}
		if (!flg) {
			sort(a, a + n, [&](query x, query y) {
				return x.idx < y.idx;
			});
			for (int i = 0; i < n; i++) cout << a[i].ans;
			cout << "\n";
		}
	}
	return 0;
}
