//Lost in the Woods
/*
  기대값문제.
  0번 노드에서 출발하여 N-1번 노드에 닿을 이동시간의 기대값을 구하는 문제이다.
  처음에는 0번 노드에 있을 확률이 1이고, 다른 어떤 노드에도 존재할 수 있을 확률은 0이다.
  시간이 지남에 따라 그래프의 연결관계를 통해 각 노드에 위치할 확률을 구한다.
    (ex. 1초가 지났을 때, 0번 노드와 연결된 노드가 1, 2번이었다면 해당 노드에 존재할 확률이 각각 0.5)
    
  이렇게 해서 실제 N-1번 노드에 존재할 확률 * 이동시간 을 ans에 계속 더해주고, 확률을 0으로 업데이트해준다.
  
  결과적으로 시행을 거듭할 수록 sum of probabilities는 점점 줄어들 것이고, 오차범위가 10^-5 이기 때문에
  10^5 만큼의 loop만 거듭해주면 충분하다.
*/

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
#include <set>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(),(v).end()
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int n, m, u, v;
double prob[21][21];
double res[2][21], ans;
vector<int> adj[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int u = 0; u < n; u++) {
		for (int v : adj[u]) {
			prob[u][v] ++;
		}
		for (int v : adj[u]) {
			prob[u][v] /= adj[u].size();
		}
	}
	res[0][0] = 1;
	int from, to;
	for (int i = 1; i < 100000; i++) {
		from = (i+1) % 2, to = i % 2;
		memset(res[to], 0, sizeof(res[to]));
		for (int u = 0; u < n; u++) {
			for (int v : adj[u]) {
				res[to][v] += res[from][u] * prob[u][v];
			}
		}
		ans += i * res[to][n - 1];
		res[to][n - 1] = 0;
	}
	printf("%.5lf", ans);
	return 0;
}
