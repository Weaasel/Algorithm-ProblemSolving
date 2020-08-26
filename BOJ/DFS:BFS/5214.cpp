//환승
/*
  최대 1000개의 줄에, 최대 1000개의 정점들을 입력으로 주고, 그 점들끼리는 모두 연결된 것을 나타낸다.
  naive하게 연결관계를 표시하려고 하면, 1000^3 = 10^9 이므로 메모리 및 시간초과가 난다.
  
  연결을 위한 노드를 새로 만드는 아이디어가 필요했던 문제다.
  예컨대, m개의 줄이 주어지는 동안, 해당 줄에 대응하는 '그룹'이라는 노드를 만들고, 그 노드와 각 점들이 연결된 것으로 표시한다.
  
  그러면 어떤 두 정점 v1, vj 사이의 path는, 정점과 그룹 노드가 반복되는 형태가 될 것이다.
  
  v1 -- g1 -- v2 -- g2 -- ... -- gi -- vj     (v: vertex, g: group)
  따라서 실제 값을 구할 때는 dist/2 + 1 로 출력해주면 된다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define pb push_back
#define BASE 100000
using namespace std;

int n, k, m, u, v;
vector<int> adj[101001];
int dist[101001];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> u;
			adj[u].pb(BASE + i);
			adj[BASE + i].pb(u);
		}
	}
	
	queue<int> q;
	dist[1] = 1;
	q.push(1);
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dist[v] > 0) continue;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	if (dist[n] == 0) cout << -1;
	else cout << dist[n]/2+1;
}
