//D - Constant Palindrome Sum	
/*
	(x, y) 쌍이 있을 때(x <= y 가정) 합이 i가 되려면 바꿔야 할 수의 개수를 dist[i]로 정의하자.
	[2, x] : dist[i] = 2
	[x+1, x+y-1] : dist[i] = 1
	[x+y] : dist[i] = 0
	[x+y+1, y+k] : dist[i] = 1
	[y+k+1, 2k] : dist[i] = 2

	라는 것을 알 수 있고, 

	한 점으로 모으는 데에 가장 비용이 적은 점을 구하는 문제이므로
	모든 (x, y) pairs에 대해 각 dist[i]들을 더했을 때
	argmin(sum of dist[i]) 인 i가 답이 됨을 알 수 있다.
	
	모든 pairs의 dist들을 [2, 2k] 인 모든 index에 대해 표시하면
	O(n * k) 의 시간이 필요하므로, 그냥 해서는 불가능해 보인다.
	
	prefix sum의 idea를 이용하자.
	res[2] = 2 로 해두고, prefix sum 방식의 update를 해나가면
	모든 res에 대해 2의 값이 들어가게 된다. 예컨대,
	res[2] = 2;
	res[x + 1] = -1;
	res[x + y] = -1;
	res[x + y + 1] = 1;
	res[y + k + 1] = 1;
	를 해두고 prefix sum 진행을 하면 맨위에 서술한 dist 값들이
	알맞게 들어가게 되는 것을 볼 수 있다.

	따라서 각 pair에 대해 실제 값 대입은 5번만 하고,
	prefix sum 연산 한 번으로 모든 값을 update할 수 있게 된다.

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
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000

using namespace std;

int a[200001], res[400001], ans, n, k, T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 2; i <= 2 * k; i++) res[i] = 0;
		ans = INF;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n / 2; i++) {
			int x = min(a[i], a[n - 1 - i]), y = max(a[i], a[n - 1 - i]);
			res[2] += 2;
			res[x + 1] -= 1;
			res[x + y] -= 1;
			res[x + y + 1] += 1;
			res[y + k + 1] += 1;
		}
		for (int i = 2; i <= 2 * k; i++) {
			res[i] += res[i - 1];
			ans = min(ans, res[i]);
		}
		cout << ans << "\n";
	}

	return 0;
}
