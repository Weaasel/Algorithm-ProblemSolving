//Cowpatibility
//Combinatorics, inclusion–exclusion principle, map
/*
  전체 쌍에서 겹치는 쌍을 제거해서 답을 구하는 문제이다.
  각 소는 5개의 flavor를 가질 수 있으므로, 이 flavor들을 가질 수 있는 32개의 조합으로 각각의 소를 포함시켜 두고,
  전체 - 1개flavor겹치는쌍 + 2개flavor겹치는쌍 ... 을 구현하면 된다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

ll n, a[5];
bool chk[5];
map<vector<int>, ll> m;
ll res = 0;

void f(int idx) {
	if (idx == 5) {
		vector<int> tmp;
		for (int i = 0; i < 5; i++) {
			if (chk[i]) tmp.pb(a[i]);
		}
		sort(all(tmp));
		if (m.find(tmp) == m.end()) m.insert({ tmp,1 });
		else m[tmp]++;
		return;
	}		
	f(idx + 1);
	chk[idx] = true;
	f(idx + 1);
	chk[idx] = false;
	return;
}

ll val(ll k) {
	return k * (k - 1) / 2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(chk, false, sizeof(chk));
		for (int j = 0; j < 5; j++) {
			cin >> a[j];
		}
		f(0);
	}
	res = val(n);
	for (pair<vector<int>,ll> t : m) {
		if (t.first.size() == 0) continue;
		else if (t.first.size() % 2 == 1) res -= val(t.second);
		else res += val(t.second);
	}

	cout << res;

	return 0;
}
