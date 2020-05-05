//A - Phoenix and Balance	
/*
  가장 큰 n번째 bit의 2^k 가 나머지 모든 수의 합보다 크기 때문에,
  a, b 한쪽에 이 수를 더하게 되면 그 다음 큰 수부터는 모두 반대쪽에 줘야
  차이를 최소화할 수 있다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
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

ll T, n, a, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		a = 0, sum = 0;
		for (int i = 1; i <= n; i++) sum += 1LL << i;
		a += 1LL << n;
		for (int i = 1; i < n/2; i++) a += 1LL << i;
		cout << abs(sum - 2 * a) << "\n";
	}

	return 0;
}
