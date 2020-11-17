//기왕 이렇게 된 거 암기왕이 되어라
//Offline Query, Disjoint set
/*
  주어진 트리에서 어떤 정점과 그 정점의 부모 사이의 연결을 끊는 쿼리와, 어떤 시점에 두 정점이 같은 그룹에 속해 있는지 물어보는 쿼리가 들어온다.
  오프라인 쿼리로 해결한다.
  끊는 쿼리에 포함된 간선은 제거한 트리상태에서 출발하고, 뒤쪽 라운드에 끊어진 간선부터 차례차례 연결하며 해당 시점에 맞는 정답쿼리를 처리한다.
  주의할 점은 간선을 끊는 쿼리에서 같은 수가 여러 번 등장하면(ex. 3 3 3) 가장 앞에 있는 쿼리에 도달해야 그 간선을 연결할 수 있다는 점이다. 
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e9+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265

using namespace std;
using vi = vector<int>;

int n, m, k;
int par[101010], p[101010], x[101010];
int cnt[101010];
struct query {
	int round;
	int u, v;
	int idx;
	string res;
};
query q[101010];

int find(int u) {
	if (par[u] == 0) return u;
	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u != v) par[v] = u;
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= m; i++) {
		cin >> x[i];
		cnt[x[i]] ++;
	}
	for (int i = 0; i < k; i++) {
		cin >> q[i].round >> q[i].u >> q[i].v;
		q[i].idx = i;
	}

	//n-1-m개의 edge 연결
	for (int i = 1; i <= n; i++) {
		if (p[i] == -1 || cnt[i]) continue;
		merge(i, p[i]);
	}

	//round 느린순으로 정렬
	sort(q, q + k, [&](query a, query b) {
		return a.round > b.round;
	});

	int wlk = m;
	for (int i = 0; i < k; i++) {
		//query[i].round보다 큰 라운드 처리
		while (q[i].round < wlk) {
			cnt[x[wlk]]--;
			if(cnt[x[wlk]] == 0 && p[x[wlk]] != -1) merge(x[wlk], p[x[wlk]]);
			wlk--;
		}
		if (find(q[i].u) == find(q[i].v)) q[i].res = "Same Same;";
		else q[i].res = "No;";
	}

	sort(q, q + k, [&](query a, query b) {
		return a.idx < b.idx;
	});
	for (int i = 0; i < k; i++) cout << q[i].res << "\n";
	
	return 0;
}
