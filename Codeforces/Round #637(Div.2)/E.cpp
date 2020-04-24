//E - Nastya and Unexpected Guest	

/*
  우선 이 코드는 틀린 코드이다. 각 safe island를 연결하는데에 있어서 누락한 경우가 있었고, 그래서 0-1 BFS를 하라는 말도 있다.
  어쨌든 내 접근방식과 풀이를 기록하기 위해 남기는 commit이다.
  
  우선 0 -> n 으로 이동을 완료해야 하고, gt : 초록불 시간, rt : 빨간불 시간 인데 
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
