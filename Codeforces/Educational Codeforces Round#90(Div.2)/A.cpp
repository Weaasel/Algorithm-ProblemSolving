//A - Donut Shops

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
#define INF 1e+9
const ll DIV = 1e9 + 7;
using namespace std;

ll T, n, a, b, c;
//int a[200001];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		if (a >= c) cout << -1<<" ";
		else cout << 1<<" ";
		if (a*b <= c) cout << -1 << "\n";
		else cout << b << "\n";
	}
	return 0;
}
