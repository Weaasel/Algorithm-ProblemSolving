//인물이와 정수
//greedy, dijkstra
/*
  dijkstra의 아이디어와 비슷한 그리디로 해결 가능하다.
  먼저 u v c 로 주어진 쌍들에 대해 v의 비용은 c만큼 더해진다.
  어떤 u를 선택하면 u에 연결된 모든 정점들에 대해 연결된 간선의 가중치만큼 비용을 감소시키고 다시 pq에 넣어준다.
  이런 식의 방식이 최적해를 보장한다. 증명해보자.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

ll c[100001];
vector<pll> adj[100001];
bool chk[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	int p; cin >> p;
	for (int i = 1; i <= p; i++) {
		ll a, b, t; cin >> a >> b >> t;
		adj[a].push_back({ b, t });
		c[b] += t;
	}
	priority_queue<pll> pq;
	for (int i = 1; i <= n; i++) {
		pq.push({ -c[i], i });
	}
	ll ans = 0;
	int cnt = 0;
	while (!pq.empty()) {
		auto [a, b] = pq.top(); pq.pop();
		if (chk[b]) continue;
		chk[b] = true;
		ans = max(ans, -a);
		cnt++;
		if (cnt == m) break;
		for (auto [i, j] : adj[b]) {
			c[i] -= j;
			pq.push({ -c[i], i });
		}
	}
	cout << ans;
}
