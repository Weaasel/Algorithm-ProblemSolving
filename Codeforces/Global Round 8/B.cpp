//B - Codeforces Subsequences	
/*
  "codeforces"라는 부분문자열을 주어진 수 k 개 이상 가지는 최소 길이의 문자열을 만들어야 하는 문제.
  문자가 총 10개이므로, 10개의 문자의 반복으로 이루어진 문자열을 10개의 구간으로 자를 수 있고,
  "codeforces" 부분문자열의 개수는 반복되는 개수 10개의 곱으로 표현할 수 있다.

  예를 들어
  "ccooddeeffoorrcceess" 이렇게 같은 문자가 2번씩 반복된 문자열을 만들었다면, 만들수 있는 부분문자열의 개수는
  2*2*2*...*2 = 2^10 = 1024개가 된다.
  우리는 최소길이를 만들고 싶으므로, 이런 식으로 개수를 잘 분배해주면 되겠다.
  나는 a^10 >= k가 되는 a를 구하고,
  (a-1)*(a-1)*...*a*a >=k 가 되는 a-1의 개수를 구해 길이를 최소화했다.
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
ll T, k;
//int a[200001];
string s = "codeforces";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	if (k == 1) cout << "codeforces";
	else {
		int i;
		for (i = 1;; i++) {
			if (pow(i, 10) >= k) break;
		}
		int j;
		for (j = 10; j >= 0; j--) {
			if (pow(i - 1, j) * pow(i, 10 - j) >= k) break;
		}
		//i-1번씩 j개, i번씩 10-j개
		for (int idx = 0; idx < j; idx++) {
			for (int it = 0; it < i-1; it++) cout << s[idx];
		}
		for (int idx = j; idx < 10; idx++) {
			for (int it = 0; it < i; it++) cout << s[idx];
		}
	}
	return 0;
}
