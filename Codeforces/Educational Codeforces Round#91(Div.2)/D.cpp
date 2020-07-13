//D - Berserk And Fireball
/*
  A배열을 B배열로 만들기 위해 지워야 하는 consecutive한 원소들이 있다.
  각각의 원소 집합에 대해, min(최대한 Berserk, 최대한 Fireball) cost를 더해주면 된다.

  1. 최대한 Berserk를 하려 해도 마지막에 가장 큰 원소 1개가 남고, 이 원소가 max(l, r)보다 작아야 Berserk로 지울 수 있다.
    즉 max(l, r)보다 큰 원소가 1개 이상 존재하면 무조건 Fireball 한번은 해야 한다는 뜻이다.
  2. 최대한 Fireball을 하려 해도 (k의 배수) 개의 원소 만 지울 수 있다. 즉 남은 원소들은 Berserk로 지워야 한다.
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
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int T, n, m;
ll x, k, y, res;
int a[200001], b[200001];
vector<int> idx;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> x >> k >> y;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int w = 0;
	bool flg = true;
	idx.pb(-1);
	for (int i = 0; i < m; i++) {
		while (w < n && a[w] != b[i])w++;
		if (w == n) flg = false;
		idx.pb(w);
	}
	idx.pb(n);
  
	int sz = idx.size();
	for (int i = 0; i < sz - 1; i++) {
		int l = idx[i], r = idx[i + 1];
		int mx = max(a[l], a[r]);
		ll c1 = 0, c2 = 0;
		for (int j = l + 1; j < r; j++) {
			c1++;
			if (a[j] > mx) c2++;
		}
		ll t1, t2;
		t1 = y * (c1%k) + x * (c1 / k);
		t2 = c2 == 0 ? y * c1 : y * (c1 - k) + x;
		if (c2 > 0 && c1 < k) flg = false;
		res += min(t1, t2);
	}
	if (!flg) cout << -1;
	else cout << res;
	return 0;
}
