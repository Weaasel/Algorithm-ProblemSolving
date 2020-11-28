//줄임말
//set, inversion count
/*
  문자열 T를 여러번 이어붙여 문자열 S를 부분문자열로 만들어야 한다.
  최대한 적게 이어붙이기 위해서는 S의 문자들을 하나씩 훑으며 T에서 최대한 뽑아내야 한다.
  wlk = -1에서 출발하여 T에 있는 wlk이상인 가장 가까운 S[i] 문자를 찾자.
  만약 upper bound == set.end() 라면 더이상 T에서 뽑아낼 수 없는 것이므로 T를 하나 더 이어붙인다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
const int INF = 1e9 + 7;

set<int> st[26];
string s, t;
int ssz, tsz, res = 1;

int main() {
	cin >> s >> t;
	ssz = s.size(), tsz = t.size();
	for (int i = 0; i < tsz; i++) {
		st[t[i] - 'a'].insert(i);
	}
	int wlk = -1;
	for (int i = 0; i < ssz; i++) {
		int idx = s[i] - 'a';
		if (st[idx].empty()) return cout << -1, 0;
		if (st[idx].upper_bound(wlk) == st[idx].end()) {
			res++;
			wlk = -1;
		}
		wlk = *st[idx].upper_bound(wlk);
	}
	cout << res;
	return 0;
}
