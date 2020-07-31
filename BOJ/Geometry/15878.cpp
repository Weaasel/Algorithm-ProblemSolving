//Pineapple Pizza
//Geometry, CCW
/*
  피자 위에 놓인 파인애플들을 한 점에서 출발하는 반직선들로 정확히 같은 개수로 나눠야 한다.
  주어진 점으로부터의 기울기가 같은 점들을 한 component로 묶는다.
  이러면 결국 점들은 {2, 1, 1, 3, 1, 2, ...} 와 같은 형태로 묶일 것이다.(예시)
  
  우리는 이것을 앞에서부터 그룹화해서 k개로 잘 나눌 수 있는지 확인하면 되는데, 그 역할을 해주는게 go 함수이다.
  n, k <= 8000 이므로 모든 component를 출발점으로  n^2 솔루션이 가능하다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <limits>
#define ll long long
#define INF 1e9 + 7
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
int N, K;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

struct P {
	int x, y;
	P operator -(const P&rhs) const {
		return { x - rhs.x, y - rhs.y };
	}
	ll cross(const P&rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	bool operator <(const P& O) {
		if (1LL * y*O.x != 1LL * x*O.y) return 1LL * y*O.x < 1LL * x*O.y;
		if (y != O.y) return y < O.y;
		return x < O.x;
	}
}a[8010];
int idx, b[16010];
vector<P> sa[4];

ll ccw(P&a, P&b, P&c) {
	ll ret = (b - a).cross(c - b);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return 0;
}
int sx, sy;

bool go(int id) {
	int cnt = K, rem = N / K;
	int tmp = rem;
	for (int i = id; i < id + idx; i++) {
		if (b[i] > tmp) return false;
		if (b[i] == tmp) {
			cnt--;
			tmp = rem;
		}
		else tmp -= b[i];
	}
	return cnt == 0 && tmp == rem;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	if (N%K) return cout << "NO", 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i].x >> a[i].y;
	}
	cin >> sx >> sy;
	for (int i = 0; i < N; i++) {
		a[i].x -= sx, a[i].y -= sy;
		int g = gcd(abs(a[i].x), abs(a[i].y));
		a[i].x /= g, a[i].y /= g;
		if (a[i].x > 0) {
			if (a[i].y > 0) sa[0].push_back(a[i]);
			else sa[3].push_back(a[i]);
		}
		else {
			if (a[i].y > 0) sa[1].push_back(a[i]);
			else sa[2].push_back(a[i]);
		}
	}
	for (int i = 0; i < 4; i++) {
		sort(all(sa[i]));
		for (int j = 0; j < (int)sa[i].size(); j++)
			a[idx++] = sa[i][j];
	}
	int w1 = 0, w2 = 0;
	idx = 0;
	while (w1 < N) {
		int cnt = 0;
		while (w2 < N && a[w1].x == a[w2].x && a[w1].y == a[w2].y) {
			w2++;
			cnt++;
		}
		b[idx++] = cnt;
		w1 = w2;
	}
	for (int i = 0; i < idx; i++)
		b[i + idx] = b[i];
	int ret = 0;
	for (int i = 0; i < idx; i++) {
		ret |= go(i);
	}
	if (ret) cout << "YES";
	else cout << "NO";
	return 0;
}
