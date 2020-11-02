//C - Collinearity
/*
  주어진 점들 중 한 직선 위에 놓인 세 점이 존재하는지 여부를 묻는 문제이다.
  모든 3점들 중 두 점들간의 기울기가 같은 점들이 존재하는지 검사하면 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define pb push_back

using namespace std;

pii a[101];
int n;
bool flg;

bool chk(int i, int j, int k) {
	vector<pii> v;
	v.pb(a[i]);
	v.pb(a[j]);
	v.pb(a[k]);
	sort(all(v));
	if ((v[0].first - v[1].first) * (v[1].second - v[2].second) == (v[1].first - v[2].first) * (v[0].second - v[1].second)) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (chk(i, j, k)) flg = true;
			}
		}
	}
	if (flg) cout << "Yes";
	else cout << "No";
	return 0;
}
