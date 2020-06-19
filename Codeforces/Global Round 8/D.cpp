//D - AND, OR and square sum	
/*
  Key Observation : a, b에 대한 operation은 한 수만 가지고 있는 bit를 다른 수로 옮겨줄 수 있는 연산이다.
  이 operation을 제한없이 수행할 수 있으므로,
  결국 제곱의 sum을 maximize하는 방법은,
  모든 bits의 개수를 각각 세어 최대한 몰아주는 것이다.  
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
int n;
ll a[200001];
int cnt[25];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < n; j++) {
			if ((a[j] & (1LL << i)) > 0) cnt[i]++;
		}
	}
	ll res = 0, tmp;
	for (int i = 0; i < n; i++) {
		tmp = 0;
		for (int j = 25; j >= 0; j--) {
			if (cnt[j] > 0) {
				tmp += (1LL << j);
				cnt[j]--;
			}
		}
		res += tmp * tmp;
	}
	cout << res;
	return 0;
}
