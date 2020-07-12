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

int T, n, num;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (a.empty() || a[a.size() - 1] != num) a.pb(num);
		}
		int cnt = 0;
		n = a.size();

		for (int i = 0; i < n - 4;) {
			bool f = true;
			for (int j = 0; j < 4; j++) {
				if (a[i + j] < a[i + j + 1]) f = false;
			}
			if (f) {
				cnt++;
				i += 4;
			}
			else i++;
		}
		for (int i = 0; i < n - 4;) {
			bool f = true;
			for (int j = 0; j < 4; j++) {
				if (a[i + j] > a[i + j + 1]) f = false;
			}
			if (f) {
				cnt++;
				i += 4;
			}
			else i++;
		}
		cout << "Case #" << tc << ": " << cnt << "\n";
	}
	return 0;
}
