//복붙하기
//Hashing, Rabin Karp
/*
  boj.kr/3033과 거의 같은 문제이다. 이 문제에서 다른 부분은 중복해서 등장하는 부분문자열이 서로 겹치면 안된다는 점인데,
  이는 롤링해시를 통해 마지막에 발견된 위치와 처음에 발견된 위치의 차이를 문자열 길이와 비교하여 쉽게 처리할 수 있다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

unordered_map<ll, pii> mp;
int sz, ans = -1;
string s;

bool chk(int len) {
	mp.clear();
	ll cur = 0, p = 27, ppow = 1;
	for (int i = 0; i < len - 1; i++) ppow *= p;
	for (int i = 0; i < len; i++) {
		cur *= p;
		cur += s[i] - 'a' + 1;
	}
	mp[cur] = { 0,0 };
	for (int i = len; i < sz; i++) {
		cur -= ppow * (s[i - len] - 'a' + 1);
		cur *= p;
		cur += s[i] - 'a' + 1;
		if (mp.find(cur) != mp.end()) 
			mp[cur].y = i - len + 1;
		else mp[cur] = { i - len + 1,i - len + 1 };
	}
	for (pair<ll, pii> p : mp) {
		int l = p.y.x, r = p.y.y;
		if (l + len - 1 < r) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> s;
	sz = s.size();
	int l = 1, r = sz, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
