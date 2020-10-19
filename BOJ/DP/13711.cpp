//LCS 4
//Dynamic Programming, Longest Increasing Subsequence
/*
  길이 n인 두 수열 A와 B가 주어질 때, 가장 긴 공통 부분수열의 길이를 구하는 문제이다.
  B 수열에 등장한 수들의 위치를 인덱싱해 두고,
  A 수열을 앞에서부터 훑으며 해당 수가 B 수열에 등장한 위치로 갱신한다.
  그 후 새로운 A수열에서의 LIS를 구하면 된다.
  A와 B에서 함께 등장하기 위해서는 A에서도 순서대로 등장하고 B에서도 순서대로 등장해야 하는데,
  "A에서 순서대로" 는 앞에서부터 훑으며 만족하고,
  "B에서 순서대로" 는 새로운 A수열(B수열에서 등장한 위치) 가 작은 순서로 부분수열을 만듦으로서 만족하기 때문이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

int n, a[101010], pos[101010];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		pos[b] = i;
	}
	for (int i = 0; i < n; i++) a[i] = pos[a[i]];

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(all(v), a[i]) - v.begin();
		if (idx == v.size()) v.pb(a[i]);
		else v[idx] = a[i];
	}
	cout << v.size();
	return 0;
}
