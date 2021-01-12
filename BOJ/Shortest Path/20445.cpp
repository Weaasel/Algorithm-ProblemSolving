//구간 겹치기
//Floyd washall, Dynamic Programming, value-coordination compression
/*
  dp[l][r]: l~r 번째 점을 커버하는데 필요한 최소비용
  으로 정의하면 floyd-washall-like 구현으로 모든 (l,r)들에 대해 비용 표현이 가능해진다.
  남은일은 쿼리를 받아서 되는지 안되는지 판단하고 값 출력하는 처리를 하는거다. 좌표압축은 애교.
*/

#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define eps 1e-8
#define pi 3.14159265
#define pic pair<int, char>
const ll MOD = 998244353;
const ll INF = 1e17 + 7;
using namespace std;

int n, sz, q;
pii a[101];
ll dp[201][201];
vector<int> vlist;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		vlist.pb(a[i].x);
		vlist.pb(a[i].y);
	}
	sort(all(vlist));
	vlist.erase(unique(all(vlist)), vlist.end());
	sz = vlist.size();
	for (int idx = 0; idx < n; idx++) {
		int l = lower_bound(all(vlist), a[idx].x) - vlist.begin();
		int r = lower_bound(all(vlist), a[idx].y) - vlist.begin();
		dp[l][r] = a[idx].y - a[idx].x + 1;
		for (int i = l; i <= r; i++) {
			for (int j = i; j <= r; j++) {
				dp[i][j] = min(dp[i][j], dp[l][r]);
			}
		}
	}

	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 0; i < q; i++) {
		int s, e; cin >> s >> e;
		s = upper_bound(all(vlist), s) - vlist.begin() - 1;
		e = lower_bound(all(vlist), e) - vlist.begin();
		if (s == -1 || e == sz || dp[s][e] == INF) cout << "-1\n";
		else cout << dp[s][e] << "\n";
	}

	return 0;
}
