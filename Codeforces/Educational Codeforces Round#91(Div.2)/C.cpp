//C - Create The Teams	
//Greedy
/*
  기량이 높은 멤버들을 먼저 그룹짓는게 이득이다.
  기량이 낮은 멤버로 교체해봐야 더 많은 사람을 써야 하기 때문이다.
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
#define INF 1e+9 + 7
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

int T, n;
ll x, a[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n >> x;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int cnt = 0;
		ll rem = 0;
		for (int i = n - 1; i >= 0; i--) {
			rem++;
			if (a[i] * rem >= x) {
				cnt++;
				rem -= x % a[i] == 0 ? x / a[i] : x / a[i] + 1;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
