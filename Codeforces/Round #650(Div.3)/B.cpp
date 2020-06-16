//B - Even Array	
/*
  parity가 안맞는 것들의 개수(1로 바뀌어야 할 것, 0으로 바뀌어야 할 것)을 각각 세고,
  두 개수가 같으면 그대로 출력, 다르면 좋은 배열을 만들 수 없으므로 -1을 출력한다.
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
const ll INF = 1e9;

using namespace std;
int T, n;
int a[41];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		int toz = 0, too = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i % 2 == 0 && a[i] % 2 != 0) toz++;
			else if (i % 2 == 1 && a[i] % 2 != 1) too++;
		}
		if (toz == too) cout << toz << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}
