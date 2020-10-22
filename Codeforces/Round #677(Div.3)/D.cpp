//D - Districts Connection	
/*
  주어진 수들의 값이 다르면 연결할 수 있고, 최대한 연결해서 Spanning Tree를 만들 수 있는지 검사하는 문제이다.
  모든 가능한 간선들을 검사하며 우선순위가 연결가능 여부인 MST 구현으로 처리했다.
*/

#include <iostream>
#include <vector>
#define pii pair<int, int>
#define pb push_back

using namespace std;

int T, n;
int a[5001], par[5001];

vector<pii> res;

int find(int u) {
	if (!par[u]) return u;
	return par[u] = find(par[u]);
}
bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[u] = v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n;
		memset(par, 0, sizeof par);
		res.clear();
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i] == a[j]) continue;
				if (merge(i, j)) res.pb({ i,j });
			}
		}

		if (res.size() != n - 1) cout << "NO\n";
		else {
			cout << "YES\n";
			for (pii p : res) {
				cout << p.first << " " << p.second << "\n";
			}
		}
	}

	return 0;
}
