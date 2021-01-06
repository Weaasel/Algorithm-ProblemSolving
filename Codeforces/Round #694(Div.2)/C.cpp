//C - Strange Birthday Party	
//greedy
/*
  선물 가격이 non-decreasing이 보장되기 때문에
  원하는 번호가 높은 친구부터 싼 선물을 주는게 이득이다.
  해당 친구가 원하는 선물 이하의 모든 선물을 이미 줬다면 돈으로 준다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

int T, n, m, a;
ll res, b[303030];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;
	while (T--) {
		res = 0;
		cin >> n >> m;
		vector<int> v;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.pb(a);
		}
		sort(all(v));
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
			q.push(i);
		}
		for (int i = n - 1; i >= 0; i--) {
			if (q.front() <= v[i]) {
				res += b[q.front()]; q.pop();
			}
			else {
				res += b[v[i]];
			}
		}
		cout << res << "\n";
	}
	return 0;
}
