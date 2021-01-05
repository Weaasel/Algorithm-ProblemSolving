//수 묶기
//greedy, sorting
/*
  단순하다. 양수는 양수끼리, 0 이하는 0 이하끼리 분리하고 곱해서 가장 크게 되도록 만든다. 이렇기 위해서는 절대값이 큰 것들끼리 곱해야겠지?
  다만, 1은 그냥 더해주는 게 이득이다. a*1 = a < a + 1
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

ll n, res, s1, s2;
vector<ll> v1,v2;
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num; cin >> num;
		if (num == 1) res++;
		else if (num > 0) v1.pb(num);
		else v2.pb(num);
	}
	sort(all(v1));
	sort(all(v2));
	s1 = v1.size();
	s2 = v2.size();

    for (int i = s1 - 1; i > 0; i -= 2) res += v1[i] * v1[i - 1];
	if (s1 % 2 == 1) res += v1[0];

    for (int i = 0; i < s2 - 1; i += 2) res += v2[i] * v2[i + 1];
    if (s2 % 2 == 1) res += v2[s2 - 1];

    cout << res;
	return 0;
}
