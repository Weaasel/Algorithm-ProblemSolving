//C - Pluses and Minuses	
//prefix sum
/*
  pseudo code를 따라가며 관찰하면
  1과 -1을 prefix sum으로 쌓아서 얻는 최소값의 절대값이 iteration의 횟수이고,
  각 iteration의 순서 i마다 -i가 처음으로 등장하는 idx가 res에 더해질 값이라는 것을 알 수 있다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF 1e+9
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

ll T, sz, res;
ll a[1000001], idx[3000001];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		res = 0;
		cin >> s;
		sz = s.size();
		for (int i = 0; i <= sz; i++) a[i] = 0;
		for (int i = 0; i < sz; i++) {
			if (s[i] == '-') a[i + 1] = -1;
			else a[i + 1] = 1;
		}
		for (int i = 1; i <= sz; i++) a[i] += a[i - 1];
		ll mn = INF, iter;
		for (int i = 1; i <= sz; i++) mn = min(mn, a[i]);
		if (mn >= 0) iter = 1;
		else iter = -mn + 1;

		//각 값이 처음 나오는 값 저장
		memset(idx, -1, sizeof(idx));
		for (int i = 1; i <= sz; i++) {
			if (idx[a[i] + base] != -1) continue;
			idx[a[i] + base] = i;
		}
		for (int i = 0; i < iter - 1; i++) {
			res += idx[base - i - 1];
		}
		res += sz;

		cout << res << "\n";
	}
	return 0;
}
