//C - Binary Search
//Binary Search, Combinatorics
/*
  문제 조건을 잘못 읽어 한참 디버깅한 문제이다. 그와 별개로 재미난 유형이었다.
  binary search 함수를 들고 특정 pos에 있는 특정 x 를 찾고 싶을 때 잘 찾아주는 순열의 개수를 구하는 문제이다.

  binary search 과정에서 보게 되는 index들만 잘 넣어주면 나머지 수는 어떻게 배치해도 된다.
  즉, 정해진 pos 에 도달하는 과정을 simulation하면서 들르는 index들에 x 미만의 수가 들어가야 하는지, x 초과의 수가 들어가야 하는지만 정해준다.
  lcnt: x미만의 수가 들어가야 하는 자리의 개수
  rcnt: x초과의 수가 들어가야 하는 자리의 개수
  a: x 미만인 수의 개수
  b: x 초과인 수의 개수
  라고 정의하면 답은
  (a P lcnt) * (b P rcnt) * (n - lcnt - rcnt - 1)! 으로 구해진다.
  디버깅중 혹시 모를 중복을 제거하기 위해 set을 사용했다.
*/

#include <iostream>
#include <algorithm>
#include <set>
#define ll long long
const ll DIV = 1e9 + 7;

using namespace std;

int n, x, pos;
ll a, b;
ll res = 1;
set<ll> lpos, rpos;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x >> pos;
	if (n == 1) return cout << 1, 0;

	a = x - 1, b = n - x;
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2; //l~mid, mid+1 ~ r-1 우리는 pos+1로 보내야돼. 그래야 마지막에 a[l -1] 로 접근할 때 pos로 접근돼.
		if (pos <= mid-1) {
			lpos.insert(mid);
			r = mid;
		}
		else {
			rpos.insert(mid);
			l = mid + 1;
		}
	}
	lpos.erase(pos);
	rpos.erase(pos);
	ll lcnt = lpos.size(), rcnt = rpos.size();
	for (ll i = n - rcnt - lcnt - 1; i >= 1; i--) {
		res *= i;
		res %= DIV;
	}
	for (ll i = 0; i < rcnt; i++) {
		res *= a - i;
		res %= DIV;
	}
	for (ll i = 0; i < lcnt; i++) {
		res *= b - i;
		res %= DIV;
	}
	cout << res;
	return 0;
}
