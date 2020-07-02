//도토리 숨기기
//binary search
/*
  마지막 도토리가 있는 상자를 찾기 위해서 이분탐색을 한다.
  i 번 상자까지 봤을 때 정해진 규칙으로 d개 이상 도토리를 담을 수 있나? 를 chk함수로 사용한다.
  1~i번 상자에 d개 이상을 담을 수 있다면 r = mid - 1,
  다 못 담는다면 l = mid + 1
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9
using namespace std;

ll n, k, d, ans = 1000001;
ll s[10001], e[10001], dist[10001];

bool chk(ll idx) {
	ll cnt = 0;
	for (int i = 0; i < k; i++) {
		ll l = s[i];
		ll r = min(e[i], idx);
		if (r < l) continue;
		cnt += 1 + (r - l) / dist[i];
	}
	return cnt >= d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> d;
	for (int i = 0; i < k; i++) cin >> s[i] >> e[i] >> dist[i];

	ll l = 0, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}
