//Find my Family
//Data structure, set
/*
  주어진 배열 A에서 i < j < k 인 i,j,k에 대해 A[j] < A[i] < A[k] 를 만족하는 i,j,k가 존재하는 지 판단하는 문제이다.
  각 j를 기준으로 삼자.
  내 오른쪽에 가장 큰 원소가 내 왼쪽에 나보다 살짝 큰 원소보다 크면 된다.
  오른쪽에 존재하는 가장 큰 값은 뒤에서부터 psum-like 하게 전처리한다.
  왼쪽에 존재하는 원소들에 대해서는 구간을 한 칸씩 확장하며 set에 집어넣는다.
  이렇게 하면 내 왼쪽에 존재하는 나보다 살짝 큰 원소는 std::set.upper_bound를 사용해 찾을 수 있다.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int T, n, a[303030], mx[303030];
vector<int> res;
set<int> s;
bool flg;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		s.clear();
		cin >> n;
		flg = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		mx[n - 2] = n - 1;
		for (int i = n - 3; i >= 0; i--) {
			mx[i] = a[i + 1] > a[mx[i + 1]] ? i + 1 : mx[i + 1];
		}
		s.insert(a[0]);
		for (int i = 1; i < n - 1; i++) {
			auto it = s.upper_bound(a[i]);
			if (it != s.end() && *it < a[mx[i]]) {
				flg = true;
				break;
			}
			s.insert(a[i]);
		}
		if (flg) res.pb(tc);
	}
	cout << res.size() << "\n";
	for (int a : res) cout << a << "\n";
	return 0;
}
