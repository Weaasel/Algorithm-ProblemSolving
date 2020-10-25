//D - Bandit in a City	
//DFS
/*
  우선 나는 이런 유형의 문제를 Tree DP라고 부르지 않는다.
  DP라고 하는 유형의 문제는 dp 배열을 정의하고 각 dp값을 재사용해야만 하는 문제라고 생각한다.
  이건 그냥 tree dfs문제다. 그리고 나는 이런 유형에 강하다. 실제로 virtual이긴 하지만 친구창에 있는 사람들 중 가장 먼저 해결했다.
  
  문제의 요구는 주어진 트리에서 parent->child로 사람들을 보내는 작업을 반복해서 leaf까지 전부 보냈을 때,
  leaf에 존재하는 사람들의 max값을 minimize하는 것이다.
  
  node는 3가지 정보를 담고 있다.
  mx: 내 child leaf들의 리프 사람 수 maximum 값의 minimum
  cnt: 내 child leaf의 수
  sum: 내 child leaf들에 담긴 모든 사람 수
  
  dfs진행은 다음과 같다.
  내 child들에서 node정보를 받아온다.
  이 sum들의 합에 현재노드에서 출발하는 사람 수를 더하면 현재 노드를 루트로 하는 서브트리의 전체 사람 수를 알 수 있다.
  이 인원을 적절히 분배해서 mx값 이하로 만들 수 있다면(최악의 경우 모든 child에 mx명 만큼 담는 상황)
  현재 노드에서의 mx값은 커지지 않고 유지된다.
  반대로 모든 리프에 mx명씩 담아도 사람이 남는다면, 남은 사람들을 1명씩 균일하게 분배하면서 mx값을 minimize해야 할 것이고,
  이 경우 mx값은 mx + (남은 사람수 - 1)/리프수 + 1 이 될 것이다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long

using namespace std;

struct node{
	ll mx, cnt, sum;
};

int n;
vector<int> adj[202020];
ll a[202020];

node go(int u) {
	if (adj[u].size() == 0) return {a[u], 1, a[u]};
	//내 child중 maximum을 minimize하고 싶다.
	ll mx = 0, cnt = 0, sum = a[u];
	for (int v : adj[u]) {
		node nxt = go(v);
		mx = max(mx, nxt.mx);
		cnt += nxt.cnt;
		sum += nxt.sum;
	}
	//mx 이하로 다 만들 수 있다
	if (mx*cnt >= sum) return { mx, cnt, sum};
	else {//다 나눠주고도 문제가 있다.
		ll rem = sum - mx * cnt;
		return { mx + (rem-1)/cnt + 1, cnt, sum };
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].pb(i);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << go(1).mx;
	
	return 0;
}
