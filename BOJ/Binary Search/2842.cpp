//집배원 한상덕
/*
  피로도가 될 수 있는 값을 binary search로 구한다.
  각 값에 대한 검사를 50*50 개의 점을 min값으로, min + diff 값을 max값으로 잡고
  [min, max] 사이의 높이를 가지는 점만 갈 수 있다고 가정한다.
  
  시간복잡도 : O(n^4 * log(1,000,000))
*/

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
#define all(v) (v).begin(), (v).end()
#define INF 1e9
using namespace std;

int n, h[51][51], mn, mx, r, c, pr, pc;
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 }, dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
bool vis[51][51];
vector<pii> v;
vector<int> hlist;
void init() {
	sort(all(hlist));
	hlist.erase(unique(all(hlist)), hlist.end());
}

bool chk(int diff) {
	for (int hh : hlist) {
		mn = hh;
		mx = hh + diff;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) vis[i][j] = false;
		queue<pii> q;
		if(h[pr][pc]>=mn && h[pr][pc]<=mx) q.push({ pr,pc });
		while (!q.empty()) {
			r = q.front().first;
			c = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nr = r + dx[i], nc = c + dy[i];
				if (vis[nr][nc]) continue;
				if (nr < 0 || nr >= n) continue;
				if (nc < 0 || nc >= n) continue;
				if (h[nr][nc] < mn || h[nr][nc] > mx) continue;
				q.push({ nr, nc });
				vis[nr][nc] = true;
			}
		}
		bool flg = true;
		for (pii p : v) {
			if (!vis[p.first][p.second]) flg = false;
		}
		if (flg) return true;
	}
	return false;
}

string s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'P') pr = i, pc = j;
			if (s[j] == 'K') v.pb({ i,j });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
			hlist.pb(h[i][j]);
		}
	}
	init();
	int l = 0, r = 1000001, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l;
	return 0;
}
