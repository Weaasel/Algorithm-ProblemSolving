//UnDetected
//disjoint-set, union-find
/*
  원들이 주어지고 1번부터 차례대로 켰을 때 해당 원의 영역으로 길을 막을 수 있는지를 검사하는 문제이다.
  
  "왼쪽 벽과 오른쪽 벽에 닿는 두 원이 서로 같은 집합에 들어가면 끝낸다."
  라는 논리로 풀이를 전개했다.
  
  원이 최대 200개 들어오므로,
  200*200개의 pair 를 잡고 한개씩 켜면서 merge해도 최대 200*200*200의 연산으로 해결 가능하다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb push_back
#define pii pair<int, int>
using namespace std;

int par[201];

int find(int u) {
	if (par[u] < 0) return u;
	return par[u] = find(par[u]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[u] += par[v];
	par[v] = u;
	return true;
}

int n, x[201], y[201], r[201];
vector<pii> chk;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof(par));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> r[i];;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i] - r[i] <= 0 && x[j] + r[j] >= 200) {
				chk.pb({ i, j });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for(int j=0;j < i;j++) {
			if ((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) <= (r[i] + r[j]) * (r[i] + r[j])) {
				merge(i, j);
			}
		}
		for (pii p : chk) {
			if (p.first == p.second && p.first == i) {
				cout << i;
				return 0;
			}
			else if (find(p.first) == find(p.second)) {
				cout << i;
				return 0;
			}
		}
	}
	cout << n;
	return 0;
}
