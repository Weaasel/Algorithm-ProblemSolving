//F - Spy-string	

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

int T, n, m;
string s[11], ans;
bool chk(string ss, int l) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (ss[i] != s[l][i]) cnt++;
	}
	if (cnt > 1) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		ans = "";
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				string tmp = s[i];
				for (int k = 0; k < 26; k++) {
					tmp[j] = 'a' + k;
					bool flg = true;
					//이 str이 match가 되는지 검사
					for (int l = 0; l < n; l++) {
						if (!chk(tmp, l)) flg = false;
					}
					if (flg) ans = tmp;
				}
			}
		}
		if (ans.size() == 0) cout << -1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}
