// B - Ternary String	
/*
  123이 모두 등장하는 substring의 가장 짧은 길이를 구하는 문제이다.
  전형적인 two-pointer 로 해결 가능하다.
  2020 kakao internship coding test 3번과도 유사하다.
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
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 1e9
using namespace std;

ll T, cnt[4];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> s;
		int sz = s.size();
		int w1 = 0, w2 = 0, res = INF;
		for (int i = 1; i <= 3; i++) cnt[i] = 0;
		cnt[s[w1] - '0']++;
		while (w2 < sz) {
			bool flg = true;
			for (int i = 1; i <= 3; i++) if (cnt[i] == 0) flg = false;
			if (!flg) {
				w2++;
				if (w2 == sz) break;
				cnt[s[w2] - '0']++;
			}
			else {
				res = min(res, w2 - w1 + 1);
				cnt[s[w1] - '0']--;
				w1++;
			}
		}
		if (res == INF) cout << "0\n";
		else cout << res << "\n";
	}
	return 0;
}
