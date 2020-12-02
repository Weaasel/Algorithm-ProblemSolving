//Social Distancing II
//Greedy
/*
  우선 감염 최대사거리를 구한다.
  인접한 감염-비감염 소 사이는 감염사거리보다 멀어야 하기 때문에 이들 사이의 거리-1 중 가장 작은 값이 감염 최대사거리가 된다.
  감염 최대사거리를 알고 나면, 감염사거리 이하의 차이가 나는 감염소들 중에 한 마리만 최초감염이면 되는 것을 알 수 있다.
  따라서 거리가 먼 인접소 쌍마다 최초감염 소가 한 마리씩 늘어난다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
const ll MOD = 998244353;
const int INF = 1e9 + 7;

using namespace std;

int n, mx = 2000, res = 1, prv, sz;
pii a[1001];
vector<int> v;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	sort(a, a + n);

	for (int i = 0; i < n-1; i++) {
		if (a[i].y != a[i + 1].y) {
			mx = min(mx, a[i + 1].x - a[i].x - 1);
		}
	}
	for (int i = 0; i < n; i++) if (a[i].y == 1) v.pb(a[i].x);
	sz = v.size();
	if (v.size() == 0) return cout << 0, 0;

	for (int i = 0; i < sz-1; i++) 
		if (v[i + 1] - v[i] > mx) res++;
	cout << res;

	return 0;
}
