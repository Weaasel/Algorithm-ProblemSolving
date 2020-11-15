//Water Heater
//Prefix sum
/*
  초당 물 공급량과 물의 수요가 시간구간과 양으로 주어질 때
  각 시점에 사용해야 하는 물의 양이 초당 공급량보다 많으면 No를 출력하는 문제이다.
  구간의 시작점에 사용량을 더하고 끝점에 사용량을 빼둔 후 prefix sum으로 스위핑하여 해결하는 전형적인 문제이다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define INF 1e15+7
#define eps 1e-8
#define DIV 998244353
#define pi 3.14159265

using namespace std;

ll n, w;
ll psum[202020];
bool flg = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		ll s, t, p; cin >> s >> t >> p;
		psum[s] += p;
		psum[t] -= p;
	}
	if (psum[0] > w) flg = false;
	for (int i = 1; i < 202020; i++) {
		psum[i] += psum[i - 1];
		if (psum[i] > w) flg = false;
	}
	if (flg) cout << "Yes";
	else cout << "No";

	return 0;
}
