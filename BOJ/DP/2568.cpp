//전깃줄 - 2
//LIS, Longest Increasing Subsequence
/*
  LIS의 길이를 구하고 backtrace하여 온전한 수열까지 구해야 하는 문제이다.
  특히 LIS 수열 자체가 아니라 빠져야 하는 수열을 구해야 하기 때문에 구현이 조금 더 들어간다.
  핵심은 vector의 lower_bound를 이용한 구현으로 LIS를 구할 때
  마지막에 vector에 남아있는 수열과 실제 LIS 수열은 다르다는 것이다. (실제 vector에는 뒤에 들어오는 수들이 덮어씌여져 수열이 훼손된다.)  
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;

int n;
int prv[1010100];
pii a[101010];
vector<pii> lis;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (lis.empty()) lis.pb({ a[i].y, a[i].x });
		else {
			int idx = lower_bound(all(lis), make_pair(a[i].y, a[i].x)) - lis.begin();
			if (idx == lis.size()) {
				lis.pb({ a[i].y,a[i].x });
				if (idx > 0) prv[lis[idx].y] = lis[idx - 1].y;				
			}
			else {
				lis[idx] = { a[i].y, a[i].x };
				if (idx > 0) prv[lis[idx].y] = lis[idx - 1].y;
			}
		}
	}
	vector<int> res;
	set<int> xlist;
	int curx = lis.back().y;
	while (curx > 0) {
		xlist.insert(curx);
		curx = prv[curx];
	}
	for (int i = 0; i < n; i++) 
		if (xlist.find(a[i].x) == xlist.end()) res.pb(a[i].x);
	
	sort(all(res));
	cout << n - lis.size() << "\n";
	for (int r : res) cout << r << "\n";

	return 0;
}
