//B - Balanced Array	

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
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int T, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n % 4 != 0) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < n / 2; i++) {
				cout << 2 * (i + 1) << " ";
			}
			for (int i = 0; i < n / 2 - 1; i++) {
				cout << 2 * (i + 1) - 1 << " ";
			}
			cout << n + n / 2 - 1;
		}
		cout << "\n";
	}

	return 0;
}
