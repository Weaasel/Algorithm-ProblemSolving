//Perfect Subarray
//prefix sum

/*
  주어진 배열에서 부분수열 [l, r] 의 합이 제곱수인 것의 개수를 판단하는 문제이다.
  
  먼저 [l, r]의 합은 prefix sum을 이용하여 O(1)에 구할 수 있음에 주목한다.
  또한 각 배열 원소의 값이 -100 이상 100 이하이고, 배열의 개수가 100000개 이하이므로,
  prefix sum의 최대값은 10^7 이하임을 알 수 있으므로,
  cnt 배열을 사용할 수 있다.
  
  index를 0부터 n까지 키워가며, 'psum[r] - psum[l] == 제곱수' 인 것의 개수를 알고 싶으므로,
  지나온 psum[l]들에 대해 마킹을 해놓고 sqrt(10^7) = 약 3200 개의 제곱수들에 대해 검사하는 식으로 진행한다.
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
#define eps 1e-8
#define PI 3.14159265
#define base 15000005
using namespace std;

int T, n, a[100001], cnt[30000010];
ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
		for (int i = 0; i <= n; i++) {
			for (int p = 0; p < 3300; p++) {
				if (p*p > 10000000) break;
				ans += cnt[a[i] - p * p + base];
			}
			cnt[a[i] + base]++;
		}
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
