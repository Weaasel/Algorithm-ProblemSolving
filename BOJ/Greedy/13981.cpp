//Postman
//Greedy
/*
  이 문제를 해결하기 위한 그리디한 전략을 짜보자.
  가장 먼 집은 어차피 왔다갔다하며 배달을 해줘야 한다.
  그럼 가장 먼 집부터 방문하며 편지를 배달해주고, 남은 편지는 돌아오는길에 다음으로 먼 집에 주고오면 되지 않을까?
  정답!
  주의할 점은 음수와 양수좌표를 따로 처리해 줘야 한다는 것이다.
  원점이 우체국이기 때문에 어차피 원점을 지난다 == 원점에서 우편물을 최대로 들고 출발한다 == 음수와 양수는 독립적이다
*/

#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using pll = pair<ll, ll>;

ll n, k, res, wlk, rem;
vector<pll> v1, v2;

ll travel(vector<pll> v) {
    ll ret = 0;
    wlk = (int)v.size() - 1;
	while (wlk >= 0) {
		ret += v[wlk].second / k * v[wlk].first * 2;
		rem = v[wlk].second%k;
		if (rem == 0) {
			wlk--; continue;
		}
		rem = k - rem;
		ret += v[wlk].first * 2;
		wlk--;
		while (wlk >= 0 && v[wlk].second <= rem) {
			rem -= v[wlk].second;
			wlk--;
		}
		if (wlk < 0) break;
		v[wlk].second -= rem;
	}
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll xx, yy; cin >> xx >> yy;
		if (xx == 0) continue;
		if (xx < 0) {
			v1.pb({ -xx,yy });
		}
		else v2.pb({ xx,yy });
	}

	sort(all(v1));
	sort(all(v2));
    res += travel(v1);
    res += travel(v2);

    cout << res;
	return 0;
}
