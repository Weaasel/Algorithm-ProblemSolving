//B - Phoenix and Beauty	
/*
  k개의 연속한 부분합이 모두 같은 배열을 만드려면 k의 주기를 갖는 배열이어야 한다.
  즉 k의 주기를 갖는 배열을 만들 수 있냐 없냐로 처음 판단을 시작한다.
  
  등장하는 모든 수가 k개 이하라면, 그 모든 수가 등장하는 k개 배열을 n번 반복하는 것이 답이 된다.
  등장하는 모든 수가 k개 초과라면, 그런 배열은 만들 수 없다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

int T, n, k, cnt;
int a[101], vis[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(vis, false, sizeof(vis));
		cnt = 0;
		vector<int> ans;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			vis[a[i]] = true;
		}
		for (int i = 0; i < 101; i++) {
			if (vis[i] == true) {
				cnt++;
				ans.pb(i);
			}
		}
		if (cnt > k) cout << "-1\n";
		else {
			cout << n * k << "\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < k; j++) {
					if (j >= cnt) cout << "1 ";
					else cout << ans[j]<< " ";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
