//B - Nezzar and Binary String
//Seg Tree with Lazy
/*
  거꾸로 생각하자.
  target 문자열에서 출발하여 source 문자열을 만들어야 한다. 그리고 이 과정에서 바꿀 수 있는 문자가 강제된다.
  연산 순서가 다음과 같음을 알 수 있다.
  
  1. 이번 쿼리 [l, r]구간에서 절반 미만의 수를 바꾼다.
  2. [l, r] 구간의 문자가 전부 같아야 한다.
  이 순서로 q번 진행해서 source 문자열이 만들어져야 하는데,
  2번을 만족시키기 위해 1번에서 해야 하는 동작이 한 가지로 강제됨을 알 수 있다.
*/

#include <bits/stdc++.h>

using namespace std;

int sz = 1;
int seg[808080], lazy[808080];

void propagate(int node, int nodel, int noder) {
	if (lazy[node] == -1) return;
	seg[node] = lazy[node] * (noder - nodel + 1);
	if (nodel != noder) {
		lazy[node * 2] = lazy[node];
		lazy[node * 2 + 1] = lazy[node];
	}
	lazy[node] = -1;
	return;
}

void update(int l, int r, int node, int nodel, int noder, int val) {
	propagate(node, nodel, noder);
	if (l > noder || r < nodel) return;
	else if (l <= nodel && noder <= r) {
		seg[node] = val * (noder - nodel + 1);
		if (nodel != noder) {
			lazy[node * 2] = val;
			lazy[node * 2 + 1] = val;
		}
		return;
	}
	int mid = (nodel + noder) / 2;
	update(l, r, node * 2, nodel, mid, val);
	update(l, r, node * 2 + 1, mid + 1, noder, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	return;
}

int query(int l, int r, int node, int nodel, int noder) {
	propagate(node, nodel, noder);
	if (l > noder || r < nodel) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	int mid = (nodel + noder) / 2;
	return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

int T, n, q;
int L[202020], R[202020];
string s1, s2;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> q;
		sz = 1;
		while (sz < n)sz *= 2;
		for (int i = 0; i < sz * 2; i++) {
			seg[i] = 0, lazy[i] = -1;
		}
		bool flg = true;
		cin >> s1 >> s2;
		for (int i = 0; i < q; i++) cin >> L[i] >> R[i];

		for (int i = 0; i < n; i++) 
			update(i + 1, i + 1, 1, 1, sz, s2[i] - '0');
		
		for (int i = q - 1; i >= 0; i--) {
			int cnt = query(L[i], R[i], 1, 1, sz);
			if (R[i] - L[i] + 1 == 2 * cnt) flg = false;
			if (R[i] - L[i] + 1 < 2 * cnt) { //1이 더 많다
				update(L[i], R[i], 1, 1, sz, 1);
			}
			else {
				update(L[i], R[i], 1, 1, sz, 0);
			}
		}
		for (int i = 0; i < n; i++) {
			int val = query(i + 1, i + 1, 1, 1, sz);
			if (val != s1[i] - '0') flg = false;
		}
		if (flg) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
