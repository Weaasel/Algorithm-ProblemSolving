//B - GCD Compression	
/*
  어떤 배열을 2개씩 짝지어서 1이 아닌 수를 gcd로 가지게 짝지어야 한다.
  나는 2000 이하 모든 소수에 대해 반복하게 했는데,
  사실 홀짝성을 이용하면 언제든 짝지을 수 있음을 알 수 있다.
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
#define DIV 1000000007;
#define INF 1e+9

using namespace std;

int T, n;
int a[2001];
bool isp[2001];
vector<int> prime;
void era() {
	for (int i = 2; i < sqrt(2001); i++) {
		for (int j = i * i; j < 2001; j += i) {
			isp[j] = false;
		}
	}
	for (int i = 2; i < 2001; i++) if (isp[i]) prime.pb(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(isp, true, sizeof(isp));
	era();
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= 2 * n; i++) {
			cin >> a[i];
		}
		bool flg = false;
		for (int p : prime) {
			if (flg) break;
			vector<pii> ans;
			bool used[2001];
			memset(used, false, sizeof(used));
			for (int i = 1; i <= 2 * n; i++) {
				if (used[i]) continue;
				for (int j = i + 1; j <= 2 * n; j++) {
					if (used[j]) continue;
					if ((a[i] + a[j]) % p == 0) {
						ans.pb({ i,j });
						used[i] = true;
						used[j] = true;
						break;
					}
				}
			}
			if (ans.size() >= n - 1) {
				for (int i = 0; i < n - 1; i++) {
					cout << ans[i].first << " " << ans[i].second << "\n";
				}
				flg = true;
			}
		}
	}
	return 0;
}
