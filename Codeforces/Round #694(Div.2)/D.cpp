//D - Strange Definition
/*
  두 수가 adjacent하다 <-> 두 수가 a*제곱수 꼴로 표현될 때 a가 같다.
  즉 모든 수를 이 때의 a로 표현한다.
  홀수개가 속해있는 집합은 전부 곱해도 a집합으로 귀결될 것이고,
  짝수개가 속해있는 집합은 전부 곱하면 1집합으로 귀결될 것이다.
  즉 operation을 1번만 하면 그 결과가 쭉 유지되고,
  w == 0 일때의 답은 가장 크기가 큰 집합의 크기,
  w > 0 일때의 답은 max(가장 크기가 큰 집합, 1집합 크기 + 개수가 짝수개인 집합들의 크기) 가 된다.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

int T, n, r[2], a[303030];
bool chk[1010];
vector<int> prime;

void init() {
	for (int i = 2; i*i < 1010; i++) {
		if (chk[i]) continue;
		for (int j = i * i; j < 1010; j += i) chk[j] = true;
	}
	for (int i = 2; i < 1010; i++) if (!chk[i]) prime.pb(i);
}

int decom(int num) {
	int ret = 1;
	vector<pii> v;
	for (int p : prime) {
		if (p > num) break;
		if (num%p == 0) {
			int cnt = 0;
			while (num%p == 0) {
				num /= p;
				cnt++;
			}
			v.pb({ p,cnt });
		}
	}
	if (num > 1) ret = num;
	for (pii p : v) 
		if (p.second % 2 == 1) ret *= p.first;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	init();

	cin >> T;
	while (T--) {
		r[0] = 0, r[1] = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = decom(a[i]);
		}
		sort(a, a + n);
		vector<pii> v;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) cnt++;
			else {
				v.pb({ a[i-1],cnt });
				cnt = 1;
			}
		}
		v.pb({ a[n - 1],cnt });
		int ev = 0;
		for (pii p : v) {
			r[0] = max(r[0], p.second);
			if (p.first == 1 || p.second % 2 == 0) ev += p.second;
		}
		r[1] = max(r[0], ev);
		int q; cin >> q;
		for (int i = 0; i < q; i++) {
			ll w; cin >> w;
			if (w == 0) cout << r[0] << "\n";
			else cout << r[1] << "\n";
		}
	}
	return 0;
}
