//C - Orac and LCM	
/*
  n개의 수가 주어졌을 때, 고를 수 있는 n*(n-1)/2 쌍의 모든 pair들에 대해 이들의 최소공배수들의 최대공약수를 구하는 문제.
  각각의 소수에 대해 생각해 보자.
  
  max(ai, aj) 들의 min 값이라고 할 수 있다. 즉, 이 값은 각 소수의 지수들 중 두번째로 작은 값이라고 할 수 있다.
  따라서 이들을 모두 곱해주면 된다.
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
#define DIV 1000000007LL
#define INF 2000000000
using namespace std;

ll T, n, a[100001];
bool notp[501];

//500까지의 소수
vector<int> prime;

int cnt[200001][2], bigcnt[200001];

//vector<int> cnt[200001];

void eratos() {
	for (int i = 2; i < 50; i++) {
		for (int j = i * i; j <= 500; j += i) {
			notp[j] = true;
		}
	}
	for (int i = 2; i <= 500; i++) {
		if (!notp[i]) prime.pb(i);
	}
	for (int i = 1; i <= 200000; i++) {
		cnt[i][0] = INF;
		cnt[i][1] = INF;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	eratos();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int nn = a[i];
		for (int p : prime) {
			int pcnt = 0;
			while (nn%p == 0) {
				pcnt++;
				nn /= p;
			}
			if (cnt[p][0] >= pcnt) {
				cnt[p][1] = cnt[p][0];
				cnt[p][0] = pcnt;
			}
			else if (cnt[p][1] >= pcnt) {
				cnt[p][1] = pcnt;
			}
		}
		if (nn > 1) {
			bigcnt[nn]++;
		}
	}
	ll res = 1;
	for (int p : prime) {
		res *= pow(p, cnt[p][1]);
	}
	for (int i = 2; i <= 200000; i++) {
		if (bigcnt[i] >= n - 1) res *= i;
	}
	cout << res << "\n";

	return 0;
}
