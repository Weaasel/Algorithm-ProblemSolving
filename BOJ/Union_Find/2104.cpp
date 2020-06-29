//부분배열 고르기
//Union-find, disjoint set
/*
  오프라인쿼리 느낌으로, 어떤 수 i가 최소값인 최대 부분배열을 구하는 문제로 바꾼다.
  배열의 값들을 큰 순으로 집어넣으면 i 의 차례에서 생긴 가장 큰 부분집합의 min값이 i라는 것이 보장된다.
  이 특성을 이용해 i의 차례에서 par[i]를 update하고, 양옆을 보며 이전에 update된 index였다면 i와 합친다.
  이런 식으로 minimum값을 i로 가지는 최대 부분수열을 만들고, 최대값을 갱신한다.
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
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+15
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int n, a;
pll par[100001];
vector<pii> v;
ll res;

pll find(int u) {
	if (par[u].first < 0) return { u, par[u].second };
	return par[u] = find(par[u].first);
}

bool merge(int u, int v) {
	u = find(u).first;
	v = find(v).first;
	if (u == v) return false;
	par[u].first += par[v].first;
	par[u].second += par[v].second;
	par[v].first = u;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.pb({ a,i });
	}
	sort(all(v));
	int sz = v.size();
	for (int i = sz - 1; i >= 0; i--) {
		ll val = v[i].first, idx = v[i].second;
		par[idx] = { -1, val };
		if (idx + 1 < n && par[idx + 1].first != 0) merge(idx, idx + 1);
		if (idx - 1 > -1 && par[idx - 1].first != 0) merge(idx, idx - 1);
		res = max(res, find(idx).second * val);
	}
	cout << res;
	return 0;
}
