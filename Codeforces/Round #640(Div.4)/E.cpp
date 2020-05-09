//E. Special Elements
/*
  최대 8000개의 수로 이루어진 수열이 주어지고,
  '연속한 배열 수들의 합' 으로 표현될 수 있는 배열 원소의 개수를 구하는 문제이다.
  간단해 보이는 문제지만 메모리 제한이 64kb, 즉 8000*8000개의 부분합[l, r] 을 저장하면 안되는 문제였다.
  
  생각을 조금 꼬아 배열 값들을 map에 저장해서 각 값의 개수를 세고,
  prefix sum을 이용해 [l, r] 부분합 값을 구하는 로직으로
  8000 * 8000 가지의 부분합들이 표현할 수 있는 배열 값을 카운팅했다.
*/

#include <iostream>
#include <map>
#define pb push_back
#define pii pair<int, int>
#define INF 1e9
#define ll long long
using namespace std;
int T, n;
int a[8001], psum[8001];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i <= n; i++) psum[i] = 0;
		map<int, int> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			psum[i] = psum[i - 1] + a[i];
			m[a[i]]++;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (m.count(psum[j] - psum[i - 1]) > 0) {
					cnt += m[psum[j] - psum[i - 1]];
					m.erase(psum[j] - psum[i - 1]);
				}
			}
		}
		cout << cnt << "\n";
		m.clear();
	}
}
