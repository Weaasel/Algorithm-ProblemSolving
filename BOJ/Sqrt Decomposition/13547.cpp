//수열과 쿼리5
//Mo's algorithm
/*
  mo's algorithm을 이용해 [l, r] 구간 쿼리들을 r에 대해 sqrt 버킷 idx로, l에 대해 오름차순으로 정렬한다.
  이렇게 하면 go 함수를 call 하는 횟수가 O((N+Q)*sqrt(N)) 으로 해결된다.
  
  서로 다른 수의 개수 쿼리이므로, 각 숫자가 등장한 횟수에 대한 cnt 배열을 update해 나가며,
  cnt[num]이 0->1 로 바뀌면 result에 1을 더하고,
  cnt[num]이 1->0 로 바뀌면 result에 1을 뺀다.
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
#define INF 2e18
using namespace std;

typedef struct query {
	int l, r, idx, res;
}query;

int n, m, ql, qr, a[100001], rt, res = 0, l, r;
int cnt[1000001];
vector<query> v;

void go(int nl, int nr) {
	while (nl < l) {
		l--;
		if (cnt[a[l]] == 0) res++;
		cnt[a[l]]++;
	}
	while (nl > l) {
		if (cnt[a[l]] == 1) res--;
		cnt[a[l]]--;
		l++;
	}
	while (nr < r) {
		if (cnt[a[r]] == 1) res--;
		cnt[a[r]]--;
		r--;
	}
	while (nr > r) {
		r++;
		if (cnt[a[r]] == 0) res++;
		cnt[a[r]]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ql >> qr;
		ql--, qr--;
		query q;
		q.l = ql, q.r = qr, q.idx = i;
		v.pb(q);
	}
	rt = sqrt(n) + 1;
	sort(all(v), [&](query a, query b) {
		if (a.r / rt == b.r / rt) return a.l < b.l;
		return a.r / rt < b.r / rt;
	});

	cnt[a[v[0].l]] = 1, res = 1;
	l = r = v[0].l;
	for (int i = 0; i < m; i++) {
		go(v[i].l, v[i].r);
		v[i].res = res;
	}
	
	sort(all(v), [&](query a, query b) {
		return a.idx < b.idx;
	});

	for (auto q : v) {
		cout << q.res << "\n";
	}
	return 0;
}
