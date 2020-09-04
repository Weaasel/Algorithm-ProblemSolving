//두번째 트리의 지름
/*
  우선 트리의 지름을 구하는 방법은 여러 가지인데, 그중 BFS 2번으로 구하는 방법을 택한다.
  지름을 이루는 두 점을 알아내고 나면,
  각각을 제외하고 뽑은 트리의 지름 중 큰 것이 두번째 트리의 지름이 된다.
  {u가 없는 지름} U {v가 없는 지름} = {u-v가 없는 지름}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define pb push_back
#define ll long long
#define pii pair<int, int>
using namespace std;

int n;
vector<pii> adj[100001];
ll dist[100001];

pair<int, ll> go(int s, int no) {
	memset(dist, -1, sizeof(dist));
	int retidx;
	ll retval = 0;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (pii p : adj[cur]) {
			int nxt = p.first; ll d = p.second;
			if (nxt == no || dist[nxt] > -1) continue;
			dist[nxt] = dist[cur] + d;
			if (dist[nxt] > retval) {
				retidx = nxt, retval = dist[nxt];
			}
			q.push(nxt);
		}
	}
	return { retidx, retval };
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({ v,c });
		adj[v].pb({ u,c });
	}
	//지름
	int l = go(1, -1).first;
	int r = go(l, -1).first;
	
	int l1 = go(1, l).first;
	int r1 = go(1, r).first;
	cout << max(go(l1, l).second, go(r1, r).second);

	return 0;
}
