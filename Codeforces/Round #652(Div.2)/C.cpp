//C - RationalLee	
//greedy
/*
  우선 큰 수들은 모든 친구에게 순서대로 한개씩 나눠줘야 한다. max값에 영향을 끼치는 것들이니 말이다.
  이제 봐야 할 것은 각 친구의 min값인데, 우리는 모든 친구들이 최대의 min값을 가지길 원한다.
  그러면 어떤 min값을 친구에게 줬을 때, 그 수보다는 크지만 역시 작은 값들을 최대한 몰아주길 바란다.
  이 작업은 w[i]가 큰 친구부터 순서대로, a[j]값이 작은 수부터 몰아주는 것이 optimal한 방식이다.
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

ll T, n, k;
ll a[200001], w[200001], res;
string s;
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		res = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < k; i++) cin >> w[i];
		sort(a, a + n, cmp);
		sort(w, w + k);
		for (int i = 0; i < k; i++) {
			res += a[i];
			w[i]--;
			if (w[i] == 0) res += a[i];
		}
		sort(a, a + n);
		sort(w, w + k, cmp);
		int w1 = 0;
		for (int i = 0; i < k; i++) {
			if (w[i] == 0) continue;
			res += a[w1];
			w1 += w[i];
		}
		cout << res << "\n";
	}
	return 0;
}
