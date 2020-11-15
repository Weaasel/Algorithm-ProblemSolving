//Confluence
//Disjoint set, Data structure, Smaller to Larger
/*
  N명의 학생이 각각의 Class 번호를 가지고 있고 스터디그룹을 만들어 공부하려 할 때 2가지 쿼리를 처리한다.
  1 a b: a번학생과 b번학생의 스터디 그룹을 합친다.
  2 a y: a번 학생이 속한 스터디 그룹의 y번 Class 소속인 학생의 수를 출력한다.
  
  1번 쿼리는 disjoint set 으로 해결할 수 있고,
  2번 쿼리는 set의 정보를 map으로 저장하여 해결할 수 있다.
  map에는 해당 그룹의 class별 인원수를 저장한다.
  
  주의할 점은 그룹을 합칠 때 class 종류의 수가 적은 그룹을 큰 그룹으로 합쳐야 한다는 점이다.
  merge함수에서 합쳐지는 쪽 그룹의 map의 모든 원소를 순회하기 때문에
  smaller to larger를 준수하지 않으면 크기 1짜리 그룹과 10만짜리 그룹을 합치는 10만개의 쿼리에 대해
  10만*10만번의 원소를 조회해야 한다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e15+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265

const ll mod = 1e9 + 7;

using namespace std;

int n, q;
int par[202020];
unordered_map<int, int> m[202020];

int find(int u) {
	if (par[u] == 0) return u;
	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (m[u].size() < m[v].size()) swap(u, v);
	par[v] = u;
	for (pii p : m[v]) {
		m[u][p.first] += p.second;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int c; cin >> c;
		m[i][c] = 1;
	}
	for (int i = 0; i < q; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) 
			merge(a, b);
		else {
			a = find(a);
			if (m[a].find(b) == m[a].end()) cout << "0\n";
			else cout << m[a][b] << "\n";
		}
	}
	return 0;
}
