//Radio Prize
//Tree dfs
/*
  루트의 결과값을 구해두고 각 점으로 퍼뜨리며 O(1)에 각 점의 결과값을 구할 수 있으면 된다.
  점이 u->v로 옮겨갈 때, v의 subtree에 속하는 점들에게는 u->v edge 길이만큼 가까워지고,
  나머지 점들로부터는 같은 길이만큼 멀어진다.
  이를 반영해서 각 점에 대해 새로운 결과값을 만들어주면 된다.
  각 점을 root로 하는 subtree의 크기, 가중치합을 구해놓아야 하고,
  u->v로 옮겨갈 때 기존에 t[u] 로 계산했던 것들을 t[v]로 바꿔야 하기 때문에 t[u]가 전체 연산에 몇번 쓰였는지를 계산하는 cnt변수도 필요하다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
using namespace std;

ll n, subs[101010], subcnt[101010], t[101010], dist[101010], res[101010], cnt, ttotal;
vector<pll> adj[101010];

void dfs1(int u, int prv = -1) {
    subs[u] = t[u];
	subcnt[u] = 1;
	for (pll p : adj[u]) {
		ll nxt = p.first, d = p.second;
		if (nxt == prv) continue;
		dist[nxt] = dist[u] + d;
		dfs1(nxt, u);
        subs[u] += subs[nxt];
		subcnt[u] += subcnt[nxt];
	}
    ttotal += subs[u];
	return;
}

void dfs2(int u, ll cnt, int prv = -1) {
	for (pll p : adj[u]) {
		ll v = p.first, e = p.second, cnt1 = cnt, ret = res[u];
		if (v == prv) continue;
		ret += cnt * (t[v] - t[u]);
		ret -= e * (subcnt[v] * t[v] + subs[v]);
		ret += e * ((n - subcnt[v])*t[v] + subs[1] - subs[v]);

		cnt1 -= e * subcnt[v];
		cnt1 += e * (n - subcnt[v]);
		res[v] = ret;
		dfs2(v, cnt1, u);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 0; i < n - 1; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].pb({ v,c });
		adj[v].pb({ u,c });
	}

	//루트로부터 각점 거리 구하기, 서브트리 개수/가중치 구하기
	dist[1] = 0;
	dfs1(1);
	for (int i = 1; i <= n; i++) {
		res[1] += dist[i] * (t[i] + t[1]);
		cnt += dist[i];
	}

	dfs2(1, cnt);

	for (int i = 1; i <= n; i++) cout << res[i] << "\n";
	return 0;
}
