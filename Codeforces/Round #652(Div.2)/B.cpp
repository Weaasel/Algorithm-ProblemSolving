//B - AccurateLee	
/*
  key observation : 앞에서 연속하는 0들, 뒤에서 연속하는 1들만 빼면
  그 사이에 있는 조합은 무조건 '0' 하나로 압축할 수 있다.
  그럼 이제 앞에서 연속한 0, 뒤에서 연속한 1의 개수를 세고,
  중간에 '10'을 substring으로 가지는 형태가 존재하는지의 여부만 따지면 된다.
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DIV 1000000007;
#define INF 1e+9

using namespace std;

int T, n;
int a[200001];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s;
		int w1 = 0, w2 = n - 1;
		while (w1 < n) {
			if (s[w1] == '0') {
				w1++;
			}
			else break;
		}
		while (w2 >= 0) {
			if (s[w2] == '1') {
				w2--;
			}
			else break;
		}
		for (int i = 0; i < w1; i++) cout << 0;
		if (w1 < w2) cout << 0;
		for (int i = w2; i < n - 1; i++) cout << 1;
		cout << "\n";
	}
	return 0;
}
