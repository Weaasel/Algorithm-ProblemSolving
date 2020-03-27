//A. Divisibility Problem

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

int T, a, b;
int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int t = a % b;
		if (t == 0) cout << 0 << "\n";
		else cout << b - t << "\n";
	}
	return 0;
}
