//E - Transformable Teacher
//Prefix sum, Greedy
/*
  우선 이웃한 쌍들의 차이의 합을 최소화하려면 후보들을 정렬된 형태로 만들어야 함을 알 수 있다. 이는 그리디한 증명이 가능하다.
  그러면 남은 일은 모든 선생님 키 후보들에 대해 완전탐색하는 것인데, 이것을 prefix sum을 이용하면 O(1)에 해낼 수 있다.
  먼저 2 종류의 psum을 가지고 있자.
    1. - + - + - + ...
    2. + - + - + - ...
  이렇게 하면 어떤 idx에 선생님이 들어간다고 했을 때,
  1번 psum에서 idx까지를 취하고, 2번 psum에서 idx부터 취한 후 선생님 키에 대한 처리(idx의 parity에 따라 더하거나 빼줌)를
  하면 선생님이 해당 키로 해당 자리에 들어갔을 때 구하려는 값을 알 수 있다.
  이 값들 중 최소값을 취하면 된다.
*/

#include <iostream>
#include <algorithm>
#define ll long long
#define INF 1e18

using namespace std;

ll n, m, res;
ll h[202020], w[202020];
ll psum[202020], revsum[202020];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < m; i++) cin >> w[i];
	sort(h, h + n);
	sort(w, w + m);
	for (int i = 0; i < n; i++) {
		psum[i + 1] = psum[i];
		revsum[i + 1] = revsum[i];
		if (i % 2 == 0) {
			psum[i + 1] -= h[i];
			revsum[i + 1] += h[i];
		}
		else {
			psum[i + 1] += h[i];
			revsum[i + 1] -= h[i];
		}
	}
	res = INF;
	for (int i = 0; i < m; i++) {
		res = min(res, psum[n] + h[n - 1] + abs(w[i] - h[n - 1]));
		res = min(res, revsum[n] - h[0] + abs(h[0] - w[i]));
	}
	int idx = 0;
	for (int i = 0; i < m; i++) {
		while (idx < n && w[i] > h[idx]) idx++;
		if (idx == 0) continue;
		ll cand = psum[idx] + revsum[n] - revsum[idx];
		if (idx % 2 == 1) cand += w[i];
		else cand -= w[i];
		res = min(res, cand);
	}
	cout << res;
	return 0;
}
