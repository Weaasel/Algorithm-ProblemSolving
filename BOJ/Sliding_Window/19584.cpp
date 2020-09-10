//난개발
//Sliding Window, Prefix sum
/*
  모든 구간에 대해 시작점에 +1, 끝점+1에 -1을 표시해 두고 앞에서부터 훑으며 prefix sum형태로 update하면
  각 좌표에 대해 해당 좌표를 포함시키는 구간의 개수를 알 수 있다. 이렇게 좌표의 최대값을 구할 수 있다.
  이 문제는 각 구간이 고유한 값을 가지므로, 구간의 개수보다는 합해진 값의 최대값을 얻게 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
#define pb push_back
#define pii pair<int, int>

using namespace std;

int n, m;
pii ver[202020];
ll psum[202020], res;
vector<int> vlist;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> ver[i].first >> ver[i].second;
		vlist.pb(ver[i].second);
	}
	vlist.pb(1000000007);
	sort(vlist.begin(), vlist.end());
	vlist.erase(unique(vlist.begin(), vlist.end()), vlist.end());

	for (int i = 0; i < m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		int i1, i2;
		i1 = lower_bound(vlist.begin(), vlist.end(), ver[u].second) - vlist.begin();
		i2 = lower_bound(vlist.begin(), vlist.end(), ver[v].second) - vlist.begin();
		int l = min(i1, i2), r = max(i1, i2);
		psum[l] += c;
		psum[r+1] -= c;
	}
	res = psum[0];
	for (int i = 1; i < 202020; i++) {
		psum[i] += psum[i - 1];
		res = max(res, psum[i]);
	}
	cout << res;

}
