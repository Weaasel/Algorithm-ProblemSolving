//영화 수집
/*
  영화를 보면
  1. 나보다 앞에 존재하는 영화의 개수를 구하는
  2. 맨 앞으로 끼워넣는
  두 가지의 쿼리에 대해 처리해야 한다.
  
  효율적인 방식은 그냥 MAX_SIZE * 2 크기로 seg tree를 만들어 놓고,
  처음에 뒤 절반에 초기화를 해놓은 다음, 한 편을 볼 때마다 앞 절반의 idx에 끼워넣는 방식이다.
  말 그대로 문제에서 요구한 구현을 한 것이다.
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
#define BASE 100010
using namespace std;

int T, n, m, top, q, num, sz, seg[800100];

int id[100001];


void update(int idx, int val) {
	idx += sz - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
	return;
}

void init() {
	for (int i = 1; i < 100001; i++) id[i] = 0;
	for (int i = 1; i < 800100; i++) seg[i] = 0;

	for (int i = 1; i <= n; i++) id[i] = BASE + i;
	n += BASE;
	sz = 1;
	while (sz < n) sz *= 2;
	for (int i = 1; i <= n - BASE; i++) update(id[i], 1);
	top = BASE;
}

int query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (nodel > r || noder < l) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	else return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		init();
		vector<int> res;
		for (int i = 1; i <= m; i++) {
			cin >> num;
			res.pb(query(1, id[num] - 1, 1, 1, sz));
			update(id[num], 0);
			id[num] = top;
			update(top, 1);
			top--;
		}
		for (int r : res) cout << r << " ";
		cout << "\n";
	}
	return 0;
}
