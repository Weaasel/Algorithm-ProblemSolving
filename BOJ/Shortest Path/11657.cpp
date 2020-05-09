//타임머신
//Bellman-Ford

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define ll long long
using namespace std;
typedef pair<int, int> P;
const ll INF = 1000000000000000; // 절대 나올 수 없는 경로값
int main() {
	ll N, M, dist[500];
    cin >> N >> M;

    map<int, int> adj[500];

	for (int i = 0; i < M; i++) {
		ll A, B, C;
		cin >> A >> B >> C;
		if(adj[A-1].count(B-1) == 0 || adj[A - 1][B - 1] > C) adj[A - 1][B - 1] = C;
	}
	bool minusCycle = false;

	fill(dist, dist + N, INF);
	dist[0] = 0;
	for (int i = 0; i <= N; i++) { // (N-1) + 1번의 루프. 마지막은 음의 싸이클 존재 여부 확인용
		for (int j = 0; j < N; j++) {
			// N-1번의 루프에 걸쳐 각 정점이 i+1개 정점을 거쳐오는 최단경로 갱신
			if (dist[j] == INF) continue;
			for (auto &p : adj[j]) {
				ll next = p.first, d = p.second;

				if (dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					// N번째 루프에 값이 갱신되면 음의 싸이클이 존재한다.
					if (i >= N - 1) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle) cout << -1;
	else {
		for (int i = 1; i < N; i++)
			printf("%d\n", dist[i] != INF ? dist[i] : -1);
	}
}
