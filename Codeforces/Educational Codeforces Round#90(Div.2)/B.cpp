//B - 01 Game
/*
  연속한 1과 0을 모두 지울 수 있다.
  -> min(0의 개수, 1의 개수) * 2 개만큼 지울 수 있다.
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
const ll DIV = 1e9 + 7;
using namespace std;

ll T, n, a, b, c;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> s;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') cnt1++;
			else cnt2++;
		}
		if (min(cnt1,cnt2) % 2 == 1) cout << "DA\n";
		else cout << "NET\n";
	}
	return 0;
}
