//B - Yet Another Bookshelf	
/*
  1들을 그룹화했을 때 인접한 1들끼리의 거리합을 계산한다.
*/

#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

int T, n, a[51];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n;
		int res = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> v, tmp;
		for (int i = 0; i < n; i++) 
			if (a[i] == 1) tmp.pb(i);
		for (int i = 0; i < tmp.size() - 1; i++) v.pb(tmp[i + 1] - tmp[i] - 1);
		for (int r : v) res += r;
		cout << res << "\n";
	}

	return 0;
}
