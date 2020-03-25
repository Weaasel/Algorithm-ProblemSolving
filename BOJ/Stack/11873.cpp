//최대 직사각형
//stack, histogram

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
#define DIV 1000000
#define INF 2000000000

using namespace std;

int n, m, a;
int arr[1002][1002], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
        ans = 0;
        for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a;
				if (a == 0) arr[i][j] = 0;
				else arr[i][j] = arr[i - 1][j] + a;
			}
		}

		//각 줄마다 최대 직사각형 찾기
		for (int i = 1; i <= n; i++) {
			stack<pii> s;
			int l[1002];
			l[1] = 1;
			s.push({ arr[i][1], 1 });
			for (int j = 2; j <= m + 1; j++) {
				l[j] = j;
				while (!s.empty() && s.top().first >= arr[i][j]) {
					ans = max(ans, s.top().first *(j - l[s.top().second]));
					l[j] = l[s.top().second];
					s.pop();
				}
				s.push({ arr[i][j], j });
			}
		}

		cout << ans << "\n";
	}
	return 0;
}
