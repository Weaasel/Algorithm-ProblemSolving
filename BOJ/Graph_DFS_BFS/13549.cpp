//숨바꼭질3
//BFS, 0-1 BFS
/*
  재미있는 0-1 BFS 문제다.
  
  0-1 bfs란, dijkstra로 해결해야 할 문제에 대해 deque을 이용한 bfs로
  시간복잡도를 O(nlogn)에서 O(n) 으로 줄여주는 기법이다.
  cost가 0인 edge를 지나는 것에 대한 처리를 deque의 front에 push 해주고,
  cost가 1인 edge를 지나는 것에 대한 처리를 deque의 back에 push 해주면
  deque이 마치 priority_queue처럼 동작하게 된다.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;
int n, k, dist[100001];
int bfs() {
	dist[n] = 0;
	deque<int> dq;
	dq.push_back(n);
	while (!dq.empty()) {
		int u = dq.front(); dq.pop_front();
		if (u * 2 <= 100000 && dist[u * 2] == -1) {
			dist[u * 2] = dist[u];
			dq.push_front(u * 2);
		}
		if (u - 1 >= 0 && dist[u - 1] == -1) {
			dist[u - 1] = dist[u] + 1;
			dq.push_back(u - 1);
		}
		if (u + 1 >= 0 && dist[u + 1] == -1) {
			dist[u + 1] = dist[u] + 1;
			dq.push_back(u + 1);
		}
	}
	return dist[k];
}
int main() {
	memset(dist, -1, sizeof(dist));
	cin >> n >> k;
	cout << bfs();
	return 0;
}
