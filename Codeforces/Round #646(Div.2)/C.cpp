//C - Game On Leaves
/*
  root가 주어지지 않은 tree에서 두 player가 돌아가며 leaf node를 지워가는 게임을 한다.
  타겟 node를 먼저 지우는 사람이 이기고, 두 사람은 모두 optimal하게 움직인다고 가정한다.
  이때 누가 이길 지를 맞추는 문제.
  
  leaf node란 "indegree가 1 이하"인 node를 말한다.
  따라서, O---target---O 형태를 만들면 이긴다.
  
  만약 처음부터 target node가 leaf이면 첫 player가 이길 것이고,
  그게 아니라면 두 사람 모두 위의 형태로 단 3개의 node가 남을 때까지 지워나갈 것이므로,
  전체 개수의 홀짝성에 따라 승부가 결정된다.
  
  line51에서 (adj[x].size() <= 1)에 부등호를 빼먹어서 1시간 가까이 틀렸다.
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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 1e9

using namespace std;

int T, n, x, u, v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		vector<int> adj[1001];
		cin >> n >> x;
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		if (adj[x].size() <= 1) cout << "Ayush\n";
		else if (n % 2 == 0) cout << "Ayush\n";
		else cout << "Ashish\n";
	}
}
