//D. Alice, Bob and Candies
/*
  a와 b가 사이좋게 배열의 양쪽 끝에서 사탕을 먹어치우며, 둘이 만났을 때 종료하면 된다.
  주어진 조건인 '상대방이 직전 차례에 먹은 사탕의 무게보다 많은 무게를 먹어야 한다' 라는 조건을 지키며 시뮬레이션하면 된다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define pb push_back
#define pii pair<int, int>
#define INF 1e9
#define ll long long
using namespace std;
int T, n;
int a[1001];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int tota = 0, totb = 0, lasta = 0, lastb = 0, awlk = 0, bwlk = n - 1, cnt = 0;

		while (awlk <= bwlk) {
			lasta = 0;
			while ( awlk <= bwlk && lasta <= lastb) {
				lasta += a[awlk], tota += a[awlk];
				awlk++;
			}
			cnt++;
			if (awlk > bwlk) {
				cout << cnt << " ";
				break;
			}
			lastb = 0;
			while (awlk <= bwlk && lastb <= lasta) {
				lastb += a[bwlk], totb += a[bwlk];
				bwlk--;
			}
			cnt++;
			if (awlk > bwlk) {
				cout << cnt << " ";
				break;
			}
		}
		cout << tota << " " << totb << "\n";
	}
}
