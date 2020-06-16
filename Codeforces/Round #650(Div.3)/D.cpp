//D - Task On The Board	
/*
  시뮬레이션 문제였다.
  문제 조건은 약간 복잡하지만, 결국 주어진 문자들 중 가장 큰 문자부터 차례대로 배열에 넣어주면 된다.
  답이 되지 않는 input은 주어지지 않는다는 조건 때문에 크게 예외처리할 것도 없다.
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
#define pci pair<char, int>
#define pll pair<ll, ll>
#define DIV 1000000007;
const ll INF = 1e9;

using namespace std;
int T, m;
int cnt[26], b[51];
char res[51];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> s;
		cin >> m;
		memset(res, 0, sizeof(res));
		for (int i = 0; i < m; i++) cin >> b[i];
		for (int i = 0; i < s.size(); i++) {
			cnt[s[i] - 'a']++;
		}
		vector<pci> v;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) v.pb({ i + 'a', cnt[i] });
		}
		int wlk = v.size() - 1;
		for (int i = 0; i < m; i++) {
			vector<int> zidx;
			for (int j = 0; j < m; j++) if (b[j] == 0 && res[j] == 0) zidx.pb(j);
			if (zidx.size() == 0) break;
			while (v[wlk].second < zidx.size()) wlk--;
			for (int t : zidx) res[t] = v[wlk].first;
			for (int t : zidx) b[t] = -1;
			for (int j = 0; j < m; j++) {
				if (b[j] <= 0)continue;
				for (int t : zidx) {
					b[j] -= abs(j - t);
				}
			}
			wlk--;
		}
		for (int i = 0; i < m; i++) cout << res[i];
		cout << "\n";
	}
	return 0;
}
