//Poklon
/*
  각 쿼리로 주어진 구간에서 정확히 두 번 등장하는 서로 다른 수의 개수를 출력하는 문제.
  
  기본적으로 Mo's algorithm으로 해결할 수 있으나 값의 범위가 넓어 좌표압축이 필요하다.
  쿼리의 답이 '서로 다른 수의 개수' 이므로, 정확한 값은 중요하지 않으니 좌표압축을 할 때 아예 배열 값을 바꿔버린다.
  이렇게 하지 않고 값에 접근할 때마다 upper_bound 서치하는 방식으로 하면 TLE를 받는다.
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

query q;
vector<query> v;
int n, Q, ql, qr, l, r, rt, res;
int a[500001], cnt[500001]; 
vector<int> alist;

//a[l] 쓸거면 idx(a[l])로.
void init() {
	rt = sqrt(n);
	sort(all(alist));
	alist.erase(unique(all(alist)), alist.end());
}

int idx(int val) {
	return lower_bound(all(alist), val) - alist.begin();
}

void go(int nl, int nr) {
	while (nl < l) {
		l--;
		cnt[a[l]]++;
		if (cnt[a[l]] == 2) res++;
		if (cnt[a[l]] == 3) res--;
	}
	while (nl > l) {
		cnt[a[l]]--;
		if (cnt[a[l]] == 1) res--;
		if (cnt[a[l]] == 2) res++;
		l++;
	}
	while (nr < r) {
		cnt[a[r]]--;
		if (cnt[a[r]] == 1) res--;
		if (cnt[a[r]] == 2) res++;
		r--;
	}
	while (nr > r) {
		r++;
		cnt[a[r]]++;
		if (cnt[a[r]] == 2) res++;
		if (cnt[a[r]] == 3) res--;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> Q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		alist.pb(a[i]);
	}

	for (int i = 0; i < Q; i++) {
		cin >> ql >> qr;
		q.l = ql - 1, q.r = qr - 1, q.idx = i;
		v.pb(q);
	}

	init();
	for (int i = 0; i < n; i++) {
		a[i] = idx(a[i]);
	}

	sort(all(v), [&](query a, query b) {
		if (a.r / rt == b.r / rt) return a.l < b.l;
		return a.r / rt < b.r / rt;
	});

	l = r = v[0].l;
	cnt[a[l]]++;
	for (int i = 0; i < Q; i++) {
		q = v[i];
		go(q.l, q.r);
		v[i].res = res;
	}
	sort(all(v), [&](query a, query b) {
		return a.idx < b.idx;
	});
	for (int i = 0; i < Q; i++) {
		cout << v[i].res << "\n";
	}
	return 0;
}
