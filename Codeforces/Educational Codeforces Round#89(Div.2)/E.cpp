//E - Two Arrays	
/*
  1. B로 주어지는 배열값들이 순서대로 A에 존재해야 한다. 이걸 매칭시킬 것이다.
  2. B[i]가 A에 여러번 등장한다면, 무조건 맨 뒤에 나온 녀석을 골라야 한다.
  2번의 이유는 띵킹이 필요하다.
  간단하게 말하면 B가 오름차순이므로, 맨 뒤에 나온 B[i]를 선택하지 않으면 이녀석은 B[i+1]의 구간에 들어가게 되어 
  구간 min값으로 B[i]가 나오지 못하게 한다.
  
  이렇게 각 B 배열값들을 매칭시켜놓고, 이들이 A배열에서 커버할 수 있는 범위를 구하면,
  사이사이에 겹치는 만큼이 가짓수를 늘릴 수 있는 방법들이고,
  만약 커버할 수 있는 구간이 사이구간 미만이라면 가짓수가 0이 된다.  
*/

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DIV 998244353;
const ll INF = 4e10;

using namespace std;
int n, m, mn;
ll res = 1;
bool flg = true;
int a[200001], b[200001], idx[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(idx, -1, sizeof(idx));
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int wlk = n - 1;
	for (int i = m - 1; i >= 0; i--) {
		while (wlk>=0 && a[wlk] != b[i]) wlk--;
		if (wlk < 0) break;
		idx[i] = wlk;
		wlk--;
	}
	if (idx[0] == -1) flg = false;
	mn = a[idx[0]];
	for (int j = idx[0]; j >= 0; j--) mn = min(mn, a[j]);
	if (mn != b[0]) flg = false;

	mn = a[idx[m-1]];
	for (int j = n-1; j >= idx[m-1]; j--) mn = min(mn, a[j]);
	if (mn != b[m-1]) flg = false;

	//사이만 볼거
	for (int i = m - 1; i >= 1; i--) {
		ll tot = idx[i] - idx[i - 1] - 1;
		ll rcnt = 0, lcnt = 0;
		for (int j = idx[i] - 1; j > idx[i - 1]; j--) {
			if (a[j] >= b[i]) rcnt++;
			else break;
		}
		for (int j = idx[i - 1] + 1; j < idx[i]; j++) {
			if (a[j] >= b[i - 1]) lcnt++;
			else break;
		}
		if (lcnt + rcnt < tot) flg = false;
		else {
			res *= lcnt + rcnt - tot + 1;
			res %= DIV;
		}
	}
	if (!flg) cout << 0;
	else cout << res % DIV;
	return 0;
}
