//구간 합 세그트리 기준.
//index : 1 ~ n
//기본적인 4개의 함수(init, update, query, find)를 구현해 놓았음.

#include <iostream>
#include <algorithm>
#define MAX_SIZE
using namespace std;

int n, sz, seg[MAX_SIZE * 4];

void init() {
	sz = 1;
	while (sz < n) sz *= 2;
}

void update(int idx, int val) {
	idx += sz - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
	return;
}

int query(int l, int r, int node, int nodel, int noder) {
	int mid = (nodel + noder) / 2;
	if (nodel > r || noder < l) return 0;
	else if (l <= nodel && noder <= r) return seg[node];
	else return query(l, r, node * 2, nodel, mid) + query(l, r, node * 2 + 1, mid + 1, noder);
}

int find(int rank) {
	int idx = 1;
	while (idx < sz) {
		if (seg[idx * 2] >= rank) idx = idx * 2;
		else {
			rank -= seg[idx * 2];
			idx = idx * 2 + 1;
		}
	}
	return idx - sz + 1;
}
