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

int T, n;
int a[200001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mx = -1;
		for (int i = 0; i < n; i++) {
			if (mx >= a[i]) continue;
			mx = a[i];
			if (i == n - 1 || a[i] > a[i + 1]) cnt++;
		}
		cout << "Case #" << tc << ": " << cnt << "\n";
	}
	return 0;
}
