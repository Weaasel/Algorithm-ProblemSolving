//C. K-Complete Word

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

int T, n, k, cnt[26];
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k >> str;
		int ans = n, tmp;
		for (int j = 0; j < (k+1) / 2; j++) {
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < n / k; i++) {
				int idx1 = i * k + j, idx2 = i * k + k - j - 1;
				if (idx1 == idx2) {
					cnt[str[idx1] - 'a']++;
				}
				else {
					cnt[str[idx1] - 'a']++;
					cnt[str[idx2] - 'a']++;
				}
			}
			int mx = 0;
			for (int i = 0; i < 26; i++) mx = max(mx, cnt[i]);
			ans -= mx;
		}
		cout << ans << "\n";
	}
	return 0;
}
