//C - Social Distance	
/*
  주어진 문자열(binary)과 k가 있을 때,
  k+1 간격으로 1을 얼마나 놓을 수 있는지를 알고 싶다.
  1이 들어가는 indices를 모아두고 간격별로 계산하면 된다.
  계산의 편의를 위해 가상의 -k, n+k-1 인덱스에 1이 들어있다고 가정했다.
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
int T, n, k;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		vector<int> idx;
		cin >> n >> k;
		cin >> s;
		int res = 0;
		k++;
		idx.pb(-k);
		for (int i = 0; i < s.size(); i++) if (s[i] == '1') idx.pb(i);
		idx.pb(n - 1 + k);
		for (int i = 0; i < idx.size() - 1; i++) {
			res += max((idx[i + 1] - idx[i]) / k - 1, 0);
		}
		cout << res << "\n";
	}
	return 0;
}
