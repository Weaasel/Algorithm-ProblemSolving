//보석 가게
//FFT, binary something
/*
  이 문제는 아래와 같이 
*/

#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef complex <double> base;
void fft(vector<base> &a, bool invert) {
	int n = a.size();
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			base w(1);
			for (int j = 0; j < len / 2; j++) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}

void multiply(const vector<bool> &a, const vector<bool> &b, vector<bool>&res) {
	vector<base> fa(all(a)), fb(all(b));
	int n = 1;
	while (n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);
	res.resize(n);
	for (int i = 0; i < n; i++) res[i] = (int)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}


vector<bool> a[10];
vector<bool> res[2];
int n, k, idx;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	k--;
	a[0].resize(1001);
	res[0].resize(1001);

	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		a[0][val] = 1;
		res[0][val] = 1;
	}

	for (int i = 1; i < 10; i++) {
		int s0 = a[i - 1].size();
		multiply(a[i - 1], a[i - 1], a[i]);
	}
	vector<int> v;

	for (int i = 9; i >= 0; i--) {
		if (k < (1 << i)) continue;
		v.pb(i);
		k -= (1 << i);
	}
	reverse(all(v));
	for (int i : v) {
		multiply(res[idx], a[i], res[1 - idx]);
		res[idx].clear();
		idx = 1 - idx;
	}

	int sz = res[idx].size();
	for (int i = 0; i < sz; i++) if (res[idx][i]) cout << i << " ";

	return 0;
}
