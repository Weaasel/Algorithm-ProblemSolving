//E - Necklace Assembly	
/*
  주어진 k의 모든 약수들(p)에 대해,
  p만큼의 주기를 가지는 문자열(문자 그룹이라고 봐도 된다)을 최대한 많이 만들고,
  그 개수 m * p 를 maximize하면 된다.
  
  m을 구하는 과정은 chk함수를 보면 되는데,
  각 문자열이 등장한 회수를 m으로 각각 나누고 전부 더해서
  이것이 p 이상이 되면 길이p를 가지는 m개의 그룹으로 나눌 수 있는 것으로 보았다.
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
#define pci pair<char, int>
#define pll pair<ll, ll>
#define DIV 1000000007;
const ll INF = 1e9;

using namespace std;
int T, n, k, mx;
int cnt[26];
string s;

bool chk(int c, int p) {
	if (c == 0) return true;
	int len = 0;
	for (int i = 0; i < 26; i++) {
		len += cnt[i] / c;
	}
	return len >= p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		mx = 0;
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> k;
		cin >> s;
		for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
		for (int i = k; i >= 1; i--) {
			if (k%i != 0) continue;
			//주기 정하고 해당 주기로 몇개만들수 잇는지 binary search
			int p = i;
			int l = 0, r = 100000, mid, tmp = 0;
			while (l <= r) {
				mid = (l + r) / 2;
				if (chk(mid, p)) {
					tmp = max(tmp, mid);
					l = mid + 1;
				}
				else r = mid - 1;
			}
			mx = max(mx, p*tmp);
		}
		cout << mx << "\n";
	}
	return 0;
}
