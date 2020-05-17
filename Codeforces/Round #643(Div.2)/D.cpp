// D - Game With Array	

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
#define DIV 1000000007LL
#define INF 2e9
using namespace std;

int n, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	if (2 * n > s) {
		cout << "NO\n";
		return 0;
	}
	else {
		cout << "YES\n";
		for (int i = 0; i < n - 1; i++) cout << 1 << " ";
		s -= (n - 1);
		cout << s << "\n" << n;
	}
	return 0;
}
