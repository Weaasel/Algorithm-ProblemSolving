//A - C+=
/*
  주어진 두 수 a, b를 가지고 += 연산만을 이용해 주어진 수 n 보다 큰 수를 만들어야 한다.

  작은 수에 큰 수를 더하고, 그 수를 다시 큰수에 더하는 작업을 반복하는 것이 최적이다.
  이 observation은 엄청 빨리 해놓고, 시간복잡도 때문에 오랫동안 못풀었던게 너무 아쉽다.
  수가 마치 피보나치 수처럼 커지기 때문에 단순 반복해도 거의 O(logn)이면 충분하다.
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
int T, a, b, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b >> n;
		if (a > b) swap(a, b);
		if (a + b > n) cout << 1 << "\n";
		else {
			int cnt = 0;
			while (b <= n) {
				a += b;
				swap(a, b);
				cnt++;
			}
			cout << cnt << "\n";
		}

	}
	return 0;
}
