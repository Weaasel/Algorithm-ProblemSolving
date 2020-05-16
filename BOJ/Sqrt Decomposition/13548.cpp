//수열과 쿼리6
//Mo's algorithm
/*
  mo's algorithm을 이용해 [l, r] 구간 쿼리들을 r에 대해 sqrt 버킷 idx로, l에 대해 오름차순으로 정렬한다.
  이렇게 하면 go 함수를 call 하는 횟수가 O((N+Q)*sqrt(N)) 으로 해결된다.
  
  '최빈값의 개수' 쿼리이므로, 각 숫자가 등장한 횟수에 대한 cnt 배열과,
  해당 cnt를 가지는 수가 몇개인지를 나타내는 cntnum 을 update해 나간다.
  
  어차피 result는 while문 안에 연산 한 번에 최대 1만큼 늘거나 줄기 때문에,
  각 loop에 대해 O(1)이 보장된다.
  
  구간이 커지면 cnt[num]이 커지므로 기존에 cntnum[cnt[num]]은 1 줄이고 새로운 cntnum[cnt[num]]의 값을 1 증가시킨다.
  이 때 res < cnt[num] 이라면 res = cnt[num]이다.
  
  구간이 줄어들 때는 반대로 적용한다.
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

int n, m, ql, qr, l, r, rt;
int a[100001], cnt[100001], cntnum[100001], res = 0;

typedef struct query {
	int l, r, idx;
	int res;
}query;

vector<query> v;

void go(int nl, int nr) {
	while (nl < l) {
		l--;
		cntnum[cnt[a[l]]]--;
		cnt[a[l]]++;
		cntnum[cnt[a[l]]]++;
		res = max(res, cnt[a[l]]);
	}
	while (nl > l) {
		cntnum[cnt[a[l]]]--;
		if (cntnum[res] == 0) res--;
		cnt[a[l]]--;
		cntnum[cnt[a[l]]]++;
		l++;
	}
	while (nr < r) {
		cntnum[cnt[a[r]]]--;
		if (cntnum[res] == 0) res--;
		cnt[a[r]]--;
		cntnum[cnt[a[r]]]++;
		r--;
	}
	while (nr > r) {
		r++;
		cntnum[cnt[a[r]]]--;
		cnt[a[r]]++;
		cntnum[cnt[a[r]]]++;
		res = max(res, cnt[a[r]]);
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

	cnt[a[v[0].l]]++;
	cntnum[1]++;
	res = 1;
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
