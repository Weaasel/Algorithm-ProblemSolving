//B - Strange List	
/*
  x가 2 이상이기 때문에 어떤 값은 아무리 나눠져도 최대 log(1e9) == 31 번 나누어진다.
  즉 그냥 naive하게 나누고 더하는 연산을 해도 시간복잡도는 O(nlogn)이 보장된다.
  단 같은 값을 가지는 원소들을 묶어서 관리해준다면 말이다.
  원소를 {값, 개수} 로 관리하자.
*/

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pb push_back
using namespace std;

ll T, n, x, res;
vector<pll> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;
	while (T--) {
		res = 0;
		v.clear();
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			ll num; cin >> num;
			v.pb({ num,1 });
			res += num;
		}
		int wlk = 0;
		while (1) {
			if (v[wlk].first%x == 0) {
				res += v[wlk].first*v[wlk].second;
				v[wlk] = { v[wlk].first / x, v[wlk].second*x };
			}
			else break;
			wlk++;
			wlk %= n;
		}
		cout << res << "\n";
	}
	return 0;
}
