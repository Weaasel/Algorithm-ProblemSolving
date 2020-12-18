//Photoshoot
/*
  b[i] = a[i-1] + a[i]
  -> a[i] = b[i] - a[i-1]
  즉 a[0]이 정해지면 a[1]부터는 저절로 정해진다.
  모든 a[0]에 대해 가능한 경우인지 검사한다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, b[1010], res[1010];
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		set<int> s;
		res[0] = i;
		s.insert(i);
		for (int j = 1; j < n; j++) {
			res[j] = b[j] - res[j - 1];
			if (res[j] > 0) s.insert(res[j]);
		}
		if (s.size() == n) {
			for (int j = 0; j < n; j++) cout << res[j] << " ";
			return 0;
		}
	}
	return 0;
}
