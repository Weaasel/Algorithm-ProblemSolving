//NMK
//Constructive
/*
  n개의 수로 LIS m, LDS k 인 수열을 만들어야 한다.
  길이 m 이하인 증가수열을 k개 깔면 된다. (증가수열끼리는 내림차순)
  ex) 654, 321 등
  
  이 때, 적어도 1개의 증가수열은 길이가 m 이어야 하기 때문에 전체 길이를 생각해 보면
  최소 m + 1*(k-1)이다.
  최대 m*k 이다.
  즉 가능한 n의 범위가 정해지므로 맨 앞에서 이 조건을 만족하지 않는 n은 걸러준다.
  
  나는 맨 앞에 길이 m짜리 증가수열을 깔고, 그 뒤로는 남은 n-m개의 수를 k-1개의 그룹으로 나누었다.
*/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

int n, m, k;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	if (n<m + k - 1 || n>m*k) {
		cout << -1;
		return 0;
	}
	vector<int> v;
	for (int i = n - m + 1; i <= n; i++) v.pb(i);
	if (k > 1) {
		int nn = n - m;
		int mm = nn / (k - 1);
		int kk = nn - mm * (k - 1);
		int s = nn + 1;
		for (int i = 0; i < kk; i++) {
			s -= mm + 1;
			for (int j = s; j < s + mm + 1; j++) v.pb(j);
		}
		for (int i = kk; i < k - 1; i++) {
			s -= mm;
			for (int j = s; j < s + mm; j++) v.pb(j);
		}
	}

	for (int i : v)cout << i << " ";
	return 0;
}
