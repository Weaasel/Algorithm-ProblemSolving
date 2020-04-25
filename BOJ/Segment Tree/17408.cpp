//수열과 쿼리24
//segment tree

/*
  수열이 주어지고 쿼리가 주어지는 간단한 세그먼트 트리 문제입니다.
  쿼리는
    1. i번째 수의 값을 교체
    2. [a, b] 구간의 (최대값 + 두번째 최대값) 을 출력
    
   세그트리를 pair<int, int> type으로 선언하고, 각 노드에 구간의 {최대값, 두번째 최대값}을 저장하면 됩니다.
   두 구간을 합칠때는
    1. 각 구간의 최대값 중 큰 값이 [합친 구간의 최대값]이고
    2. 두 구간의 최대값 중 작은 값, 각 구간의 두번째 최대값 중 가장 큰 값이 [합친 구간의 두번째 최대값] 일 것입니다.
    
   이 규칙을 이용하여 구현하면 됩니다.
*/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define pii pair<int, int>
#define MAX_SIZE 400000
using namespace std;
int sizee = 1, n, m, a, b, c;

pii seg[MAX_SIZE];

void update(int b, int c) {
	b += sizee - 1;
	seg[b].first = c;
	while (b > 1) {
		b /= 2;
		seg[b].first = max(seg[b*2].first, seg[b*2+1].first);
		seg[b].second = max({min(seg[b*2].first, seg[b*2+1].first), seg[b*2].second, seg[b*2+1].second});
	}
	return;
}

pii query(int s, int e, int node, int lval, int rval) {
	if (lval > e || rval < s) return {0, 0};
	else if (lval >= s && rval <= e) return seg[node];
	else {
		int midval = (lval + rval) / 2;
		pii res1 = query(s, e, node * 2, lval, midval);
		pii res2 = query(s, e, node * 2 + 1, midval + 1, rval);
		return {max(res1.first, res2.first), max({min(res1.first, res2.first), res1.second, res2.second})};
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	while (sizee < n) sizee *= 2;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		update(i, a);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b>> c;
		if(a==1) {
			update(b, c);
		}
		else {
			pii res = query(b, c, 1, 1, sizee);
			cout << res.first + res.second << "\n";
		}
	}
	return 0;
}
