// B. Kind Anton

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
int a[100001], b[100001];
int cnt[3], flg;

vector<int> v(1);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		flg = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i] + 1]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			cnt[a[i] + 1]--;
			if (a[i] == b[i]) continue;
			else if (a[i] < b[i]) {
				if (cnt[2] > 0) continue;
				else {
					cout << "NO\n";
					flg = 1;
					break;
				}
			}
			else {
				if (cnt[0] > 0) continue;
				else {
					cout << "NO\n";
					flg = 1;
					break;
				}
			}
		}
		if(!flg) cout << "YES\n";
	}
	return 0;
}
