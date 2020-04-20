//Google Code jam 2020 Round1B A - Expogo

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

int tc, x, y;
bool xf, yf, flg;
vector<char> res;

void read() {
	while (!res.empty()) res.pop_back();
	xf = false;
	yf = false;
	flg = false;

	cin >> x >> y;
	if (x < 0) {
		xf = true;
		x = -x;
	}
	if (y < 0) {
		yf = true;
		y = -y;
	}
}

void write() {
	if (flg) cout << "IMPOSSIBLE\n";
	else {
		for (char c : res) {
			if (c == 'S' && yf) cout << "N";
			else if (c == 'N' && yf) cout << "S";
			else if (c == 'E' && xf) cout << "W";
			else if (c == 'W' && xf) cout << "E";
			else cout << c;
		}
		cout << "\n";
	}
}

void solve() {
	while (1) {
		bool t = false;

		if (x == 0 && y == 0) break;
		if ((x & 1) == (y & 1)) { flg = true; break; }

		if (y & 1 == 1) t = true;
		if ((x & 2) == (y & 2) && (x >= 2 || y >= 2)) {
			if (!t) { // x : W or E
				x++;
				res.pb('W');
			}
			else { // y : N or S
				y++;
				res.pb('S');
			}
		}
		else {
			if (!t) {
				x--;
				res.pb('E');
			}
			else {
				y--;
				res.pb('N');
			}
		}
		x /= 2, y /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		read();
		cout << "Case #" << i << ": ";
		solve();
		write();
	}

	return 0;
}
