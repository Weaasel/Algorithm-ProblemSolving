//F - Network Coverage	
//binary search
/*
  어떤 한 b[i]에서 a[i]와 a[i+1]에 몇개씩 나눠줄 건지 정하는 순간, 다른 모든 b의 분배는 정해진다.
  b[n-1]에서 (a[n-1], a[0])에 몇개씩 나눠줄 지 정하면, 해당 분배가 valid 한지의 여부는 O(n)에 판단 가능하다.
  
  a[0]에 분배할 개수로 이분탐색을 진행한다.
  만약 전체 분배가 가능하면 'YES'
  전체 분배가 불가능할 때,
    1. 나눠주다가 남긴 부분이 있다면 -> a[0]에 덜 주고 시도해볼 만 하다.
    2. 남긴 부분이 없다면 -> a[0]에 더 주고 시도해볼 만 하다.
  이 세 state를 가지고 l, r값을 좁혀가며 이분탐색을 시도한다.  
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

ll T, n;
ll a[1000001], acpy[1000001], b[1000001], bcpy[1000001];
string s;

int chk(ll a0) {
	int res = -1;
	for (int i = 0; i < n; i++) acpy[i] = a[i];
	for (int i = 0; i < n; i++) bcpy[i] = b[i];
	acpy[0] -= a0; acpy[n - 1] -= bcpy[n - 1] - a0;
	for (int i = 0; i < n - 1; i++) {
		if (acpy[i] > bcpy[i]) return res;
		bcpy[i] -= acpy[i];
		acpy[i] = 0;
		if (acpy[i + 1] < bcpy[i]) res = 1;
		acpy[i + 1] = max(0LL, acpy[i + 1] - bcpy[i]);
	}
	if (acpy[n - 1] > 0) return res;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		ll l = 0, r = min(a[0], b[n - 1]);
		bool flg = false;
		while (l <= r) {
			ll mid = (l + r) / 2;
			int res = chk(mid);
			if (res == 0) {
				flg = true;
				break;
			}
			//앞에서 안남았으면
			else if (res == -1) l = mid + 1;
			//앞에서 남았으면
			else r = mid - 1;
		}
		if (flg) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
