//C - Nezzar and Nice Beatmap	
//God
/*
  엄청난 갓문제다.
  주어진 점들의 순서를 정하고 이어서 모든 연속한 세 점들이 이루는 각이 예각이 되게 만들어야 한다.
  
  풀이는 한 점에서 출발하여 가장 먼 점을 계속해서 고르면 된다.
  이게 왜 되냐?
  한 점 A에서 가장 먼 점 B를 골랐고, 다시 B에서 가장 먼 점 C를 골랐다고 하자.
  이렇게 해서 만들어진 각이 둔각이려면 A->B 거리 < A-C 거리여야 한다.
  즉 모순이다.
*/

#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define pb push_back

using namespace std;

int n;
pii a[5050];
bool chk[5050];
vector<int> res;
ll dist(int i, int j) {
	ll X = a[i].x - a[j].x, Y = a[i].y - a[j].y;
	return X * X + Y * Y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	res.pb(1);
	chk[1] = true;
	int now = 1;

	for (int i = 0; i < n - 1; i++) {
		ll d = 0, idx = -1;
		for (int j = 1; j <= n; j++) {
			if (chk[j]) continue;
			if (dist(now, j) > d) {
				d = dist(now, j);
				idx = j;
			}
		}
		res.pb(idx);
		chk[idx] = true;
		now = idx;
	}
	for (int r : res) cout << r << " ";
	return 0;
}
