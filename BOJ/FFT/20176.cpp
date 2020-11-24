//Needle
//Fast Fourier Transform, mathematics
/*
  x축과 평행한 세 직선이 있고, 1번직선->2번직선의 간격과 2번직선->3번직선의 간격은 같다.
  세 직선위에 좌표 -3만 ~ 3만 범위의 점들이 5만개 이하로 주어질 때, 세 직선위의 점들을 하나씩 포함하는 직선을 몇 개나 그을 수 있는지 묻는 문제이다.
  세 직선의 점의 x좌표를 각각 x1, x2, x3라 하면,
  결국 2*x2 = x1+x3 인 쌍의 개수를 묻는 문제이고,
  x1+x3들을 적당히 체크해두면 x2들을 순회하며 답을 한번에 찾을 수 있을 것 같았다.
  이 작업을 위해 필요한 것이 fft이다.
  x좌표를 차수로 치환한 다항식을 만들고 1번직선과 3번직선의 다항식을 곱하면, 결과값으로 나온 다항식이 x1+x3 좌표들의 개수를 계수로 표현한다.
*/

#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define sz(x) (x).size()
#define all(x) (x).begin(),(x).end()
#define M_PI 3.14159265
const double PI = acos(-1);
typedef complex <double> base;
void fft(vector<base> &a, bool invert) {
	int n = sz(a);
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

void multiply(const vector<lint> &a, const vector<lint> &b, vector<lint>&res) {
	vector<base> fa(all(a)), fb(all(b));
	int n = 1;
	while (n < max(sz(a), sz(b))) n <<= 1;
	n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); 
	fft(fb, false);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);
	res.resize(n);
	for (int i = 0; i < n; i++) res[i] = (lint)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

vector<lint> a[3];
vector<lint> res;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int N[3], x;
	for (int i = 0; i < 3; i++) {
		cin >> N[i];
		a[i].resize(60001);
		while (N[i]--) {
			cin >> x; x += 30000;
			a[i][x] = 1;
		}
	}
	multiply(a[0], a[2], res);
	lint ans = 0;
	for (int i = 0; i <= 60000; i++)
		if (a[1][i]) ans += res[i * 2];
	cout << ans;

	return 0;
}
