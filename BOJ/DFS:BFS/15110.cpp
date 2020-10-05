//Security Badge
//BFS
/*
  방들을 연결하는 문의 정보(security number가 s이상 e이하여야 문 이용 가능) 이 주어질 때
  출발점으로부터 도착점으로 갈 수 있는지 여부를 판단하는 문제.
  
  등장한 구간의 s,e 들만 모아서 새로운 구간들을 만든다.
  이렇게 하면 한 구간 안에서 도착여부가 달라질 일은 없다.
  구간은 m에 비례하여 만들어지기 때문에 m개의 구간에 대해 각각 bfs를 하면
  시간복잡도는 O(m*(n+m)) 이 보장된다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

int n, m, k, frm, to, res;
vector<pair<int, pii>> adj[1010];
vector<pii> range;
vector<int> vlist;
bool vis[1010];

void bfs(int idx) {
	queue<int> q;
	int val = range[idx].first;
	vis[frm] = true;
	q.push(frm);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			int v = nxt.first, s = nxt.second.first, e = nxt.second.second;
			if (vis[v]) continue;
			if (s > val || val > e) continue;
			vis[v] = true;
			q.push(v);
		}
	}
	if (vis[to]) res += range[idx].second - range[idx].first + 1;
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	cin >> frm >> to;
	for (int i = 0; i < m; i++) {
		int u, v, s, e;
		cin >> u >> v >> s >> e;
		adj[u].pb({ v,{s,e} });
		vlist.pb(s);
		vlist.pb(e);
	}
	vlist.pb(1);
	vlist.pb(k);

	sort(all(vlist));
	vlist.erase(unique(all(vlist)), vlist.end());

	int vsz = vlist.size();
	range.pb({ vlist[0],vlist[0] });
	for (int i = 0; i < vsz - 1; i++) {
		if (vlist[i + 1] > vlist[i] + 1) range.pb({ vlist[i] + 1,vlist[i + 1] - 1 });
		range.pb({ vlist[i + 1], vlist[i + 1] });
	}

	int sz = range.size();
	for (int i = 0; i < sz;i++) {
		memset(vis, false, sizeof(vis));
		bfs(i);
	}
	cout << res;

	return 0;
}
