//A. Little Artem

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
int T, n, m;
vector<int> v(1);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		if (n*m % 2 == 1) {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					for(int j=0;j<m/2;j++) cout << "BW";
					cout << "B\n";
				}
				else {
					for (int j = 0; j < m / 2; j++) cout << "WB";
					cout << "W\n";
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i == n - 1) {
					if (i % 2 == 0) {
						for (int j = 0; j < m - 2; j++) {
							if (j % 2 == 0) cout << "B";
							else cout << "W";
						}
					}
					else {
						for (int j = 0; j < m - 2; j++) {
							if (j % 2 == 0) cout << "W";
							else cout << "B";
						}
					}
					cout << "BB\n";
				}
				else if (i % 2 == 0) {
					for (int j = 0; j < m; j++) {
						if (j % 2 == 0) cout << "B";
						else cout << "W";
					}
					cout << "\n";
				}
				else {
					for (int j = 0; j < m; j++) {
						if (j % 2 == 0) cout << "W";
						else cout << "B";
					}
					cout << "\n";

				}
			}

		}
	}
	return 0;
}
