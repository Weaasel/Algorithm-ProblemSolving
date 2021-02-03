//세 수의 합
//Bitset, Meet in the middle
/*
  집합 a의 원소를 ai라고 표현하자.
  a[i]+a[j]+a[k] = a[l] 인 가장 큰 a[l]를 찾아야 하고
  즉 a[l]-a[i] = a[j]+a[k]인 가장 큰 a[l]을 찾으면 된다.
  따라서 a[j]+a[k]들을 전처리해두고 a[l], a[i]를 순회하며 해당하는 값을 찾으면 되는데,
  이 과정에서 std::set을 사용해도 되고, 값의 범위가 최대 2억이므로 bitset을 사용해도 된다.
  bitset을 사용하면 O(n^2)에 풀린다.
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1010];
bitset<400000001> bs;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bs[a[i] + a[j]] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (bs[a[i] - a[j]]) return cout << a[i], 0;
		}
	}

	return 0;
}
