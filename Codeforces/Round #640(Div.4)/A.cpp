//A. Sum of Round Numbers
/*
  주어진 수를 자리수별로 잘 나누어 주면 되는 문제.
  어떻게 구현을 간단히 할 것인가가 중요했다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define pii pair<int, int>
#define INF 1e9

using namespace std;
int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> v;
		while (n > 0) {
			v.pb(n % 10);
			n /= 10;
		}
		int wlk = 0, cnt = 0;
		while (wlk < v.size()) {
			if (v[wlk] == 0) cnt++;
			wlk++;
		}
		cout << v.size() - cnt << "\n";
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) continue;
			cout << v[i] * pow(10, i) << " ";
		}
		cout << "\n";
	}
}
