//Jerry and Tom
//선분 교차, 이분 매칭
/*
  모든 쥐-구멍 쌍들에 대해 쥐가 들어갈 수 있는지의 여부를 판단하고, 들어갈 수 있다면 매칭을 해준다.
  그리고 만들어진 이분 그래프에서 max matching이 쥐의 개체수와 같으면 possible, 다르면 impossible이다.
  
  쥐가 들어갈 수 있는지에 대한 여부는 convex hull을 이루는 모든 선분(구멍을 포함하는 선분 제외)과의 선분 교차여부로 판단한다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9
const ll DIV = 1e9 + 7;
using namespace std;

int n, k, h, m;
pll wall[1001], hole[51], mice[251];
int A[251], B[251];
bool vis[251];
vector<int> adj[251];

int ccw(pll a, pll b, pll c) {
	ll res = a.first*b.second + b.first*c.second + c.first*a.second - a.second*b.first - b.second*c.first - c.second*a.first;
	if (res == 0) return 0;
	return  res > 0 ? 1 : -1;
}

bool intersect(pll a1, pll a2, pll b1, pll b2) {
	int a = ccw(a1, a2, b1) * ccw(a1, a2, b2);
	int b = ccw(b1, b2, a1) * ccw(b1, b2, a2);
	if (a == 0 && b == 0) {
		if (a1 > a2) swap(a1, a2);
		if (b1 > b2) swap(b1, b2);
		return b1 <= a2 && a1 <= b2;
	}
	return a <= 0 && b <= 0;
}

bool chk(pll mm, pll hh) {
	bool flg = true;
	for (int i = 0; i < n - 1; i++) {
		if (ccw(wall[i], hh, wall[i + 1]) == 0) continue;
		if (intersect(mm, hh, wall[i], wall[i + 1])) flg = false;
	}
	if(ccw(wall[n-1], hh, wall[0]) != 0 && intersect(mm, hh, wall[0], wall[n-1])) flg = false;
	return flg;
}

bool dfs(int u) {
	if (vis[u]) return false;
	vis[u] = true;
	for (int v : adj[u]) {
		if (B[v] == -1 || dfs(B[v])) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> h >> m;
	for (int i = 0; i < n; i++) cin >> wall[i].first >> wall[i].second;
	for (int i = 0; i < h; i++) cin >> hole[i].first >> hole[i].second;
	for (int i = 0; i < m; i++) cin >> mice[i].first >> mice[i].second;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < h; j++) {
			if (chk(mice[i], hole[j])) {
				for (int it = 0; it < k; it++) {
					adj[i].pb(50 * it + j);
				}
			}
		}
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		memset(vis, false, sizeof(vis));
		if (dfs(i)) cnt++;
	}
	if (cnt == m) cout << "Possible";
	else cout << "Impossible";
	return 0;
}
