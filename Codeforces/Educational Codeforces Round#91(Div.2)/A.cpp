//A - Three Indices	
//Brute force
/*
  a[i] < a[j], a[j] > a[k] 이고 i<j<k 인 (i, j, k) 쌍을 찾는 문제이다.
  배열의 개수가 최대 1000개이기 때문에
  모든 (i, j, k) 조합들을 탐색하는 O(n^3) 알고리즘은 불가능하다.
  따라서 j를 고정시키고, 구간[0, j-1] 에서 적당한 i를 찾고, [j+1, n-1] 에서 적당한 k를 찾는다.
  이러면 O(n^2)으로 해결 가능하다.
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
int a[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		int res1 = -1, res2 = -1, res3 = -1;
		for (int i = 1; i <= n; i++) cin >> a[i];
		bool flg = false;
		for (int j = 2; j < n; j++) {
			if (flg) break;
			int i, k;
			for (i = j - 1; i >= 1; i--) if (a[i] < a[j]) break;
			for (k = j + 1; k <= n; k++) if (a[j] > a[k]) break;

			if (i > 0 && k <= n) {
				cout << "YES\n" << i << " " << j << " " << k << "\n";
				flg = true;
			}
		}
		if(!flg) cout << "NO\n";
	}
	return 0;
}
