//B - Subsequence Hate
/*
  주어진 binary string에서, '101' 혹은 '010' 의 subsequence가 없게 만들어야 한다.
  따라서 string은 전부 0 혹은 1이거나, 000...111, 111...000 꼴이어야 하고,
  이 경우들에 대해 전수조사하면 된다.
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 1e9

using namespace std;

int T, ans;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> s;
		ans = INF;
		int sz = s.size(), res = 0;
		for (int i = 0; i < sz; i++) {
			if (s[i] == '1') res++;
		}
		ans = min(ans, res);
		res = 0;
		for (int i = 0; i < sz; i++) {
			if (s[i] == '0') res++;
		}
		ans = min(ans, res);
		for (int i = 0; i < sz; i++) {
			res = 0;
			for (int j = 0; j < i; j++) {
				if (s[j] == '0') res++;
			}
			for (int j = i; j < sz; j++) {
				if (s[j] == '1') res++;
			}
			ans = min(ans, res);
		}
		for (int i = 0; i < sz; i++) {
			res = 0;
			for (int j = 0; j < i; j++) {
				if (s[j] == '1') res++;
			}
			for (int j = i; j < sz; j++) {
				if (s[j] == '0') res++;
			}
			ans = min(ans, res);
		}
		cout << ans << "\n";
	}
}
