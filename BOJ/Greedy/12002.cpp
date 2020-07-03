//Field Reduction
//greedy
/*
  좌표평면에 주어진 점들을 가둘 수 있는 최소의 울타리면적을 구하는 문제이다. 최대 3개의 점까지 제외할 수 있다.
  잘 생각해보면 어차피 점들의 집합에서 최대/최소 x좌표, 최대/최소 y좌표에 달려있다는 사실을 알 수 있고,
  이 값들을 변화시키려면 경계값에 있는 점들을 제외해야 하기 때문에
  x좌표 큰/작은, y좌표 큰/작은 몇개의 점들을 뽑아 이들의 조합으로 최적해를 찾는다.
  썩 마음에 드는 솔루션은 아니다.
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
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int V, E, M, x, S, y, u, v, w;
vector<pii> adj[10001];
priority_queue<pii> mpq, spq;
bool ismc[10001], isstar[10001];
int mdist[10001], sdist[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	fill(mdist, mdist + V + 1, INF);
	fill(sdist, sdist + V + 1, INF);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].pb({ v,w });
		adj[v].pb({ u,w });
	}
	cin >> M >> x;
	for (int i = 0; i < M; i++) {
		cin >> u;
		ismc[u] = true;
		mdist[u] = 0;
		mpq.push({ 0,u });
	}
	cin >> S >> y;
	for (int i = 0; i < S; i++) {
		cin >> u;
		isstar[u] = true;
		sdist[u] = 0;
		spq.push({ 0,u });
	}
	while (!mpq.empty()) {
		pii p = mpq.top(); mpq.pop();
		int cur = p.second, d = -p.first;
		for (auto np : adj[cur]) {
			int nxt = np.first, w = np.second;
			if (mdist[nxt] > d + w) {
				mdist[nxt] = d + w;
				mpq.push({ -(d + w), nxt });
			}
		}
	}
	while (!spq.empty()) {
		pii p = spq.top(); spq.pop();
		int cur = p.second, d = -p.first;
		for (auto np : adj[cur]) {
			int nxt = np.first, w = np.second;
			if (sdist[nxt] > d + w) {
				sdist[nxt] = d + w;
				spq.push({ -(d + w), nxt });
			}
		}
	}
	int mn = (INF) * 2, mnidx = -1;
	for (int i = 1; i <= V; i++) {
		if (ismc[i] || isstar[i]) continue;
		if (mdist[i] > x || sdist[i] > y) continue;
		if (mn > mdist[i] + sdist[i]) {
			mnidx = i;
			mn = mdist[i] + sdist[i];
		}
	}
	if (mn == (INF) * 2) cout << -1;
	else cout << mn;
	return 0;
}
