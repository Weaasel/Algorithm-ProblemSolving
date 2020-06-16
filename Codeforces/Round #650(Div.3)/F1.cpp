//F1 - Flying Sort (Easy Version)	
/*
  연속하는 LIS 문제로 환원된다.
  각 수를 인덱스를 매기고 오름차순으로 정렬했을 때,
  원래인덱스들의 연속하는 증가하는 부분수열의 최대길이를 구해서
  n에서 빼주면 된다.
  
  증명이 명확히 되지는 않았는데, 예제로 따져보면 이해가 된다.
  
  만약 크기순대로 정렬한 상태의 인덱스들이
  3, 1, 4, 2, 5 였다고 하자.
  
  1, 2, 3, 4, 5였던 초기상태에서 위와 같이 변해야 하므로
  기존에 순서대로 놓여있던 것들은 그대로 두고, 나머지 것들만 순서를 잘 이동시킨다고 생각할 수 있다.
  이 예제에서는 1,4 혹은 2,5만 그대로 두고 나머지 수들을 앞뒤로 잘 보낸다고 생각하면 되겠다.
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
#define pci pair<char, int>
#define pll pair<ll, ll>
#define DIV 1000000007;
const ll INF = 1e9 + 7;

using namespace std;
int T, n, res, num;
pii a[3001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			a[i] = { num,i };
		}
		sort(a, a + n);
		int ans = 0, w1 = 0, w2 = 1, tmp = 1;
		while (w2 < n) {
			if (a[w1].second <= a[w2].second) {
				tmp++;
				w1++, w2++;
			}
			else {
				ans = max(ans, tmp);
				w1++; w2++;
				tmp = 1;
			}
		}
		ans = max(ans, tmp);
		cout << n - ans << "\n";
	}
	return 0;
}
