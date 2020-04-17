//PPC 2019. Team Selection
//어차피 포지션은 5개고, 각 포지션별 6군까지 뽑아놓으면 그 안에서 뽑을 수밖에 없기 때문에, 6^5 의 완전탐색을 하면 되는 문제.

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define pb push_back
using namespace std;
using lint = long long;
using ii = pair<int, int>;

int n, res, cnt[20001];
vector<int> top[6];
int a[20001][5], idx[20001], ans[5];

bool cmp0(int u, int v) {
	return a[u][0] > a[v][0];
}

bool cmp1(int u, int v) {
	return a[u][1] > a[v][1];
}

bool cmp2(int u, int v) {
	return a[u][2] > a[v][2];
}

bool cmp3(int u, int v) {
	return a[u][3] > a[v][3];
}

bool cmp4(int u, int v) {
	return a[u][4] > a[v][4];
}

int go(int d) {
	int r = 0;
	if (d == 5) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 5; i++) cnt[ans[i]]++;
		for (int i = 0; i < 5; i++) if (cnt[ans[i]] > 1) return -1;
		
		for (int i = 0; i < 5; i++) {
			r += a[ans[i]][i];
		}
		return r;
	}
	for (int i = 0; i < min(n, 6); i++) {
		ans[d] = top[d][i];
		r = max(r, go(d + 1));
	}
	return r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) idx[i] = i;
	sort(idx, idx + n, cmp0);
	for (int i = 0; i < min(n, 6); i++) top[0].pb(idx[i]);
	sort(idx, idx + n, cmp1);
	for (int i = 0; i < min(n, 6); i++) top[1].pb(idx[i]);
	sort(idx, idx + n, cmp2);
	for (int i = 0; i < min(n, 6); i++) top[2].pb(idx[i]);
	sort(idx, idx + n, cmp3);
	for (int i = 0; i < min(n, 6); i++) top[3].pb(idx[i]);
	sort(idx, idx + n, cmp4);
	for (int i = 0; i < min(n, 6); i++) top[4].pb(idx[i]);

	memset(ans, -1, sizeof(ans));
	cout << go(0);

	return 0;
}
