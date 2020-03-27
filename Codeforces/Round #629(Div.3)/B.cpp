//B. K-th Beautiful String
//Mathematics

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

ll T, n, k, a, fir, sec;
int main() {
	cin >> T;
	while (T--) {
		cin >> n >> k;
		a = 0;
		while (1) {
			ll chk = (a + 1)*(a + 2) / 2;
			if (chk >= k) break;
			a++;
		}
		fir = a + 2;
		sec = k - a * (a + 1) / 2;

		for (int i = 0; i < n; i++) {
			if (n - i == fir || n - i == sec) cout << "b";
			else cout << "a";
		}
		cout << "\n";
	}
	return 0;
}
