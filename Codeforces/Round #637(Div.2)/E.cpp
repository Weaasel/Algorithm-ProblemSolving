//E - Nastya and Unexpected Guest	

/*
  우선 이 코드는 틀린 코드이다. 각 safe island를 연결하는데에 있어서 누락한 경우가 있었고, 그래서 0-1 BFS를 하라는 말도 있다.
  어쨌든 내 접근방식과 풀이를 기록하기 위해 남기는 commit이다.
  
  우선 수직선 상에서 0 -> n 으로 이동을 완료해야 하고, gt : 초록불 시간, rt : 빨간불 시간 인데 gt 시간동안 계속해서 1칸/1초의 속도로
  이동해야 하고, gt시간이 종료됐을 때는 safe island (d[] array에 포함된 좌표)위에 있어야 하며, rt 시간동안 대기해야 한다.
  
  내가 접근한 방식은 safe island끼리의 연결관계를 표시하여 bfs로 [n - gt, n] 범위에 있는 점까지 닿는 데 까지의 걸리는 시간을 계산했다.
  safe island의 개수가 min(n+1, 10^4)개라는 조건이 있으므로 2중 for문으로 각 safe island끼리의 연결관계를 제한시간 안에 구할 수 있다.
  
  safe island끼리의 연결관계는, 두 island를 o로 표시하고, 거쳐갈 island를 x로 표시하면,
  o---o, x---o---o, o---o---x 의 3가지 위치관계에 놓여있는 상황을 가정하고 이 중 하나라도 성립하면 연결된 것으로 보았다.
  
  경유하는 island가 1개가 아니어도 되기 때문에 위의 풀이는 틀린 풀이가 되었다.
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
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 200000000000000000

using namespace std;

ll n, m, gt, rt, d[10001], chk[1000001];
ll dist[1000001];
vector<ll> adj[1000001];

ll mn = INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dist, -1, sizeof(dist));
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {

		cin >> d[i];
		chk[d[i]] = 1;
	}

	cin >> gt >> rt;

	for (ll j = 0; j < m; j++) {

		//d[i] == 0
		if (0 == d[j]) continue;
		if (abs(0 - d[j]) == gt) {
			adj[0].pb(d[j]);
		}
		//k < i
		if ((0 + d[j] - gt) % 2 == 0 && (0 + d[j] - gt) / 2 >= 0 && (0 + d[j] - gt) / 2 <= n && chk[(0 + d[j] - gt) / 2] == 1) {
			adj[0].pb(d[j]);
		}
		//k > j
		else if ((0 + d[j] + gt) % 2 == 0 && (0 + d[j] + gt) / 2 >= 0 && (0 + d[j] + gt) / 2 <= n && chk[(0 + d[j] + gt) / 2] == 1) {
			adj[0].pb(d[j]);
		}

	}

	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < m; j++) {
			if (i == j) continue;
			if (abs(d[i] - d[j]) == gt) {
				adj[d[i]].pb(d[j]);
			}
			//k < i
			if ((d[i] + d[j] - gt) % 2 == 0 && (d[i] + d[j] - gt) / 2 >= 0 && (d[i] + d[j] - gt) / 2 <= n && chk[(d[i] + d[j] - gt) / 2] == 1) {
				adj[d[i]].pb(d[j]);
			}
			//k > j
			else if ((d[i] + d[j] + gt) % 2 == 0 && (d[i] + d[j] + gt) / 2 >= 0 && (d[i] + d[j] + gt) / 2 <= n && chk[(d[i] + d[j] + gt) / 2] == 1) {
				adj[d[i]].pb(d[j]);
			}
		}
	}

	queue<ll> q;
	q.push(0);
	dist[0] = 0;
	while (!q.empty()) {
		ll cur = q.front(); q.pop();
		if (n == cur) {
			mn = min(mn, dist[cur] * (gt + rt) - rt);
		}
		else if (n - cur <= gt) {
			mn = min(mn, dist[cur] * (gt + rt) + n - cur);
		}

		for (ll next : adj[cur]) {
			if (dist[next] > -1) continue;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	if(mn < INF) cout << mn;
	else cout << -1;
	return 0;
}
