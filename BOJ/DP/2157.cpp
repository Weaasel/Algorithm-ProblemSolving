//여행
//dp, bellman ford
/*
  dp 스럽기도, bellman ford 스럽기도 한 코드로 해결했다.
  m-1 개 이하의 edge를 사용해 n 에 도달하는 최대 dist를 찾는 문제로 환원할 수 있다.
  따라서 m-1번의 loop 안에서 모든 edge들에 대해 dist[i]들을 반복적으로 갱신해 주고, 마지막에 계산된 dist[n]을 출력한다.
  
  주의할 점은 포인트는
    1. 정점 번호가 높은점에서 낮은점 순으로 j를 진행해야 using multiple edge 상황이 나오지 않고,
        (예를 들어 2->4, 4->5 edge 순으로 update하면 2->5는 실제로 edge 2개를 사용한 셈인데 한 루프 안에서 update가 이루어진다.)
    2. dist가 0 인 점(아직 도달한 적이 없다는 뜻이다.) 인 j는 건너뛰어야 한다는 것이다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9
const ll DIV = 1e9 + 7;
using namespace std;

int n, m, k, u, v, c;
int cost[301][301];
int dist[301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> u >> v >> c;
		if (u > v) continue;
		cost[u][v] = max(cost[u][v], c);
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = n; j >= 1; j--) {
			if (dist[j] == 0 && j != 1) continue;
			for (int k = n; k >= j; k--) {
				if (cost[j][k] == 0) continue;
				dist[k] = max(dist[k], dist[j] + cost[j][k]);
			}
		}
	}
	cout << dist[n];
	return 0;
}
