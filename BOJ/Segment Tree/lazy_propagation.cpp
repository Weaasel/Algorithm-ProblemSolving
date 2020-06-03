//Sum seg tree, update with difference
//합 구간 트리, 업데이트는 값에 더하는 형식

int sz = 1;
int seg[400001], lazy[400001]; 

void propagate(int node, int nodel, int noder) {
	if (!lazy[node]) return;
	seg[node] += lazy[node] * (noder - nodel + 1);
	if (nodel != noder) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
	return;
}

void update(int l, int r, int node, int nodel, int noder, int val) {
	propagate(node, nodel, noder);
	if (l > noder || r < nodel) return;
	else if (l <= nodel && noder <= r) {
		seg[node] += val * (noder - nodel + 1);
		if (nodel != noder) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
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
