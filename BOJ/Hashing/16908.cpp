//가장 긴 공통 부분 문자열
//Hashing, Rabin Karp
/*
  문제 자체는 이분탐색+해싱으로 풀리는 전형적인 형태이다.
  다만 이 풀이를 선택했을 때 나이브하게 구현하면 시간초과를 받는다.
  길이 10만인 string이 10개가 있어 해시맵에 key값이 최대 100만개까지 저장될 수 있기 때문이다.
  
  따라서 해시맵의 원소개수를 최대 10만개 이하로 낮추는 커팅이 필요하다.
  공통 부분문자열로서 의미가 있기 위해선 모든 문자열에 포함되는, 문자열이어야 하므로,
  이전에 원하는 횟수만큼 등장하지 않은 부분문자열은 과감하게 버린다.
  이러면 원소들을 교집합 형태로 저장하게 되어 최대 10만개가 보장된다.
*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using lint = long long;
const lint p = 27;
int t;
string s[10];
unordered_map<lint, int> occ;
unordered_set<lint> v;
int f(int len) {
	occ.clear();
	v.clear();
	lint h = 0, pw = 1;
	int sz = (int)s[0].size();
	for (int i = 0; i < len; i++)
		h = h * p + (s[0][i] - 'a'), pw *= p;
	v.insert(h);
	for (int i = 1; i - 1 + len < sz; i++) {
		h = h * p - pw * (s[0][i - 1] - 'a') + (s[0][i - 1 + len] - 'a');
		v.insert(h);
	}
	for (lint x : v) occ[x]++;

	for (int ii = 1; ii < t; ii++) {
		v.clear();
		lint h = 0, pw = 1;
		int sz = (int)s[ii].size();
		for (int i = 0; i < len; i++)
			h = h * p + (s[ii][i] - 'a'), pw *= p;
		if(occ.find(h)!=occ.end() && occ[h] == ii) v.insert(h);
		for (int i = 1; i - 1 + len < sz; i++) {
			h = h * p - pw * (s[ii][i - 1] - 'a') + (s[ii][i - 1 + len] - 'a');
			if (occ.find(h) != occ.end() && occ[h] == ii) v.insert(h);
		}
		for (lint x : v) occ[x]++;
	}
	for (auto&it : occ)
		if (it.second == t) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	int l = 0, r = 100001, ans = 0;
	for (int i = 0; i < t; i++) cin >> s[i], r = min(r, (int)s[i].size());
	while (l <= r) {
		int m = (l + r) / 2;
		if (f(m)) {
			ans = max(ans, m);
			l = m + 1;
		}
		else r = m - 1;
	}
	cout << ans;
	return 0;
}
