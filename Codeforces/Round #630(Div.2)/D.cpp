//D. Walk on Matrix

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

int k, ans[3][4], u = 131072;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	cout << "3 4\n";
	ans[0][0] = k + u;
	ans[0][1] = k;
	ans[0][2] = k;
	ans[0][3] = 0;
	ans[1][0] = u;
	ans[1][1] = 0;
	ans[1][2] = k;
	ans[1][3] = 0;
	ans[2][0] = u;
	ans[2][1] = u;
	ans[2][2] = k + u;
	ans[2][3] = k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
