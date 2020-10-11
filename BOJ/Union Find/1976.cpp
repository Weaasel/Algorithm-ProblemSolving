//여행 가자
//disjoint set, union-find
/*
   주어진 경로로 여행을 할 수 있으려면 모든 여행지가 같은 set에 포함되어 있어야 한다.
*/

#include <iostream>

using namespace std;

int n, m;
int a[201][201], b[1001], par[201];

int find(int a) {
	if (par[a] == 0) return a;
	return par[a] = find(par[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	par[b] = a;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) merge(i, j);
		}
	}
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < m - 1; i++) if (merge(b[i], b[i + 1])) return cout << "NO", 0;
	cout << "YES";

	return 0;
}
