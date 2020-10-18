//동치 증명
//SCC
/*
  그래프를 SCC형태로 압축한 DAG에서 이 DAG를 하나의 SCC로 만들어야 한다.
  하나의 DAG라고 하면 root의 역할을 하는 indegree == 0 인 점들과 leaf인 outdegree == 0인 점들을 잘 연결해서 어디에서 어디로든 갈 수 있게 만들어야 한다.
  이를 위해 필요한 최소 간선 개수는 max(#ind==0, #outd==0) 임을 관찰할 수 있다.
  이제 일반화하여 여러 DAG로 이루어진 DAG Forest를 가정하자.
  이 DAG들을 서로 연결해서 하나의 DAG로 만드는 것이 우선이다. 이 과정에서 각 DAG는 최소 1개의 루트와 최소 1개의 리프를 가지므로,
  DAG끼리 연결하는 과정에서 전체 루트와 전체 리프가 한 개씩 줄어드는 것을 알 수 있고, 이렇게 만든 하나의 DAG에서 같은 작업을 하면 결국 식이 같아짐을 알 수 있다.
  
  주어진 그래프가 이미 하나의 SCC인 경우를 예외처리해야 한다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int T, n, m, c1, c2, cnt;
int ind[20202], oud[20202], who[20202];
bool vis1[20202], vis2[20202];
vector<int> adj[20202], radj[20202];
stack<int> st;

void init() {
	cnt = 0, c1 = 0, c2 = 0;
	memset(vis1, false, sizeof vis1);
	memset(vis2, false, sizeof vis2);
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		radj[i].clear();
		ind[i] = 0, oud[i] = 0;
	}
}

void dfs1(int u) {
	vis1[u] = true;
	for (int v : adj[u])
		if (!vis1[v]) dfs1(v);
	st.push(u);
}

void dfs2(int u, int rep) {
	vis2[u] = true;
	who[u] = rep;
	for (int v : radj[u])
		if (!vis2[v]) dfs2(v, rep);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		init();
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			radj[v].pb(u);
		}
		for (int i = 1; i <= n; i++) 
			if (!vis1[i]) dfs1(i);
		while (!st.empty()) {
			int u = st.top(); st.pop();
			if (!vis2[u]) dfs2(u, u);
		}

		for (int u = 1; u <= n; u++) {
			for (int v : adj[u]) {
				if (who[u] == who[v]) continue;
				ind[who[v]]++;
				oud[who[u]]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (who[i] != i) continue;
			cnt++;
			if (ind[i] == 0) c1++;
			if (oud[i] == 0) c2++;
		}
		if (cnt == 1) cout << "0\n";
		else cout << max(c1, c2) << "\n";
	}
	return 0;
}
