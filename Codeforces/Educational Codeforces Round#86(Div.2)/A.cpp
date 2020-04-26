//A. Road To Zero

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
#define MAX 4001
#define DIV 1000000007LL
#define INF 2000000000000000000
using namespace std;

ll T, a, b, x, y, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		res = 0;
		cin >> x >> y >> a >> b;
		if (b > 2 * a) b = 2 * a;
		res += min(x, y) * b;
		res += (abs(x-y)) * a;
		cout << res << "\n";
	}
	return 0;
}
