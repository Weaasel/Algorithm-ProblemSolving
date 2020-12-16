//F - The Treasure of The Segments	
//Binary search
/*
  어떤 한 구간에 대해 다른 모든 구간이 연결되어 있는 상태를 만들기 위해 제거해야 할 구간의 최소 개수를 구하는 문제이다.
  결국 각 구간에 대해 연결된 구간의 개수 중 최대값을 구하는 문제가 된다.(n - 최대값이 답)
  
  따라서 모든 구간에 대해 해당 구간과 연결되지 않은 구간의 개수를 세어 주자.
  어떤 구간과 연결되지 않은 구간은 다음 두 조건 중 하나를 만족한다.
  1. 해당 구간의 시작보다 일찍 끝났다.
  2. 해당 구간의 끝보다 늦게 시작했다.
  
  따라서 각 구간의 l, r들을 따로 모으고 모든 구간에 대해 l보다 작은 r의 개수, r보다 큰 l의 개수를 찾아주면 된다.
  이 두 가지 조건이 중복되는 경우는 없음이 보장된다.(내 끝보다 늦게시작하는데 내 시작보다 일찍 끝날 수 있다고? ㄴㄴ)  
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
const int INF = 1e9+7;
using namespace std;

int T, n, mn;
pii a[202020];
vector<int> l, r;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--) {
		mn = INF;
		cin >> n;
		l.clear(); r.clear();
		for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
		for (int i = 0; i < n; i++) {
			l.pb(a[i].x);
			r.pb(a[i].y);
		}
		sort(all(l));
		sort(all(r));
		for (int i = 0; i < n; i++) {
			int ridx = lower_bound(all(r), a[i].x) - r.begin();
			int lidx = upper_bound(all(l), a[i].y) - l.begin();
			mn = min(mn, ridx + n - lidx);
		}
		cout << mn << "\n";
	}

	return 0;
}
