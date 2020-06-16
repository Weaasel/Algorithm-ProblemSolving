//A - Short Substrings	
/*
  입력받은 문자열의 맨앞, 맨뒤를 제외하고 나머지 원소들은 2번씩 반복된다. 이를 한 번씩 출력해주면 된다.
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
const ll INF = 1e9;

using namespace std;
int T, n;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> s;
		int len = s.size();
		cout << s[0];
		for (int i = 1; i < len - 1; i += 2) cout << s[i];
		cout << s[len - 1] << "\n";
	}
	return 0;
}
