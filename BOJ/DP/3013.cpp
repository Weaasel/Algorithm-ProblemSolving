//부분 수열의 중앙값
/*
  나는 다른 풀이를 냈지만, prefix sum으로 풀 수 있는 문제라 dp에 넣었음.
  알고 싶은 중앙값 k를 기준으로 처리하는 것이 중요.
  
  k 앞의 idx들에 대해서는 나올 수 있는 부분수열들에 대해 k보다 큰 것, 작은 것의 개수를 세가며 배열에 반영하고,
  k 뒤의 idx들에 대해서는 역시 k보다 큰 것, 작은 것의 개수를 세가며 앞에서 만든 배열을 이용해 result에 더해간다.
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
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define MAX 4001
#define DIV 1000000007LL
#define INF 2000000000000000000
#define BASE 100001
using namespace std;

ll res, n, b, idx;
ll a[100001];
ll cnt[2 * BASE];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == b) idx = i;
	}

	int lnum = 0, snum = 0;
	for (int i = 0; i < idx; i++) {
		if (a[i] > b) lnum++;
		else snum++;
	}

	cnt[BASE + lnum - snum]++;
	for (int i = 0; i < idx; i++) {
		if (a[i] > b) lnum--;
		else snum--;
		cnt[BASE + lnum - snum]++;
	}

	res = cnt[BASE];
	lnum = 0, snum = 0;
	for (int i = idx + 1; i < n; i++) {
		if (a[i] > b) lnum++;
		else snum++;

		res += cnt[BASE - lnum + snum];
	}
	cout << res;
	return 0;
}
