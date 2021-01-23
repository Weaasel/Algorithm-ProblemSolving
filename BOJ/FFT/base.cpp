#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(), (v).end()
const double PI = acos(-1);

using namespace std;

vector<ll> a[2];
vector<ll> res;
bool chk[1010101];
int T, n;

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

void multiply(const vector<ll> &a, const vector<ll> &b, vector<ll>&res) {
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
	for (int i = 0; i < n; i++) res[i] = (ll)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
  
  /*
    multiply a0, a1 -> res
  */
	a[0].resize(n);
	a[1].resize(n);	
	multiply(a[0], a[1], res);
		
	return 0;
}
