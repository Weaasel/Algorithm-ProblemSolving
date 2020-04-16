//B - Kana and Dragon Quest game	

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
int T, x, n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> x >> n >> m;
		if (x > 20) {
			while (n--) {
				x = x / 2 + 10;
				if (x <= 20) break;
			}
		}
		x -= m * 10;
		if (x <= 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
