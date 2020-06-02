//E - Polygon	

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
#define MAX 4001
#define DIV 100000LL
#define INF 1e9

using namespace std;

int T, n, k;
char rep[51][51];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) rep[i][j] = s[j];
		}
		bool flg = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (rep[i][j] == '0') continue;
				if((i+1<n && rep[i+1][j] == '0') && (j+1<n && rep[i][j+1] == '0')) flg = false;
			}
		}
		if (flg) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
