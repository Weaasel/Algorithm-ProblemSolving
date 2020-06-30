//소가 길을 건너간 이유 9
//segment tree
/*
  소를 시작점과 끝점의 pair로 나타내면
  두 소 (s1, e1), (s2, e2)가 무슨 일이 있어도 만난다 -> 이동구간이 무조건 겹친다
  -> s1 < s2 < e1 < e2 관계를 가진다. 임을 알 수 있다.
  
  이런 관계를 가지는 쌍의 개수를 찾으면 된다.
  자료구조는 segment tree를 사용할 것인데, 값에 0, 1로 체크하여 구간에 체크된 좌표가 몇개인지를 세는 합 seg tree로 구현한다.
  먼저 소들을 s가 작은 순으로 정렬해 두고, 앞에서부터 보면서 seg tree를 update 한다.
  
  현재 tree에 update되어 있는 소들은 무조건 나보다 먼저 출발한 소들 이라는 사실이 보장된다.
  그러면 나보다 먼저 출발한 소들 중 도착점이 나의 [출발점, 도착점] 사이에 있는 소의 개수를 세면 되므로,
  합 seg tree의 현재 상태에서 [s,e] 구간 쿼리를 보낸 값을 구하면 된다.
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
#define INF 1e+15
#define base 1500000
const ll DIV = 1e9 + 7;
using namespace std;

ll n, a, res = 0, sz = 1;
int seg[400001];

int query(int l, int r, int node, int nodel, int noder) {
	if (l > noder || r < nodel) return 0;
	if (l <= nodel && noder <= r) return seg[node];
	int mid = (nodel + noder) / 2;
	return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

void update(int idx, int val) {
	idx += sz - 1;
	seg[idx] += val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pii> se(n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a;
		if (se[a].first != 0) se[a].second = i;
		else se[a].first = i;
	}
	while (sz <= 2*n) sz *= 2;
	sort(all(se));
	for (pii p : se) {
		if (p.first == 0 && p.second == 0) continue;
		int s = p.first, e = p.second;
		res += query(s, e, 1, 1, sz);
		update(e, 1);
	}
	cout << res;
	return 0;
}
