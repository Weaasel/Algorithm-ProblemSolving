//A - Favorite Sequence	
/*
  문제 설명대로 주어진 수열을 앞뒤 번갈아 읽어주면 된다.
*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T, n;
int a[301];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> v;
		int l = 0, r = n - 1;
		while (l < r) {
			v.pb(a[l++]);
			v.pb(a[r--]);
		}
		if (l == r) v.pb(a[l]);
		for (int r : v) cout << r << " ";
		cout << "\n";
	}

	return 0;
}
